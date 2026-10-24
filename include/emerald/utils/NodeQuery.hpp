#pragma once

#include <Geode/cocos/base_nodes/CCNode.h>
#include <string_view>
#include <type_traits>

namespace emerald {
    /// A more convenient way to chain calls for the like 200 kinds of getChild functions.
    /// Kind of a more useful querySelector.
    /// @tparam InpT The type of node you are passing in. In most cases this can be auto deduced.
    template <class InpT = cocos2d::CCNode*, class T = std::remove_pointer_t<InpT>, std::enable_if_t<std::is_base_of_v<cocos2d::CCNode, T>>* = nullptr>
    class NodeQuery {
    protected:
        T* node;
    public:
        /// Starts a query using the passed node.
        explicit NodeQuery(T* node) : node(node) {}
        /// Starts a query using the passed node.
        explicit NodeQuery(geode::Ref<T> node) : node(node) {}

        /// Gets a child based on its id. If this holds nothing, this just returns an empty query.
        /// @tparam InpP The type of node you want it to return. If the node isn't of that type, it will end up as nullptr.
        /// @param id The id of the child to get.
        template <class InpP = cocos2d::CCNode*, class P = std::remove_pointer_t<InpP>, std::enable_if_t<std::is_base_of_v<cocos2d::CCNode, P>>* = nullptr>
        NodeQuery<P> id(std::string_view id) {
            if (!node) return NodeQuery<P>(nullptr);
            return NodeQuery<P>(geode::cast::typeinfo_cast<P*>(node->getChildByID(id)));
        }

        /// Gets a child based on its id, but recursive. If this holds nothing, this just returns an empty query.
        /// @tparam InpP The type of node you want it to return. If the node isn't of that type, it will end up as nullptr.
        /// @param id The id of the child to get.
        template <class InpP = cocos2d::CCNode*, class P = std::remove_pointer_t<InpP>, std::enable_if_t<std::is_base_of_v<cocos2d::CCNode, P>>* = nullptr>
        NodeQuery<P> idRec(std::string_view id) {
            if (!node) return NodeQuery<P>(nullptr);
            return NodeQuery<P>(geode::cast::typeinfo_cast<P*>(node->getChildByIDRecursive(id)));
        }

        /// Gets a child based on its type (and index). If this holds nothing, this just returns an empty query.
        /// @tparam InpP The type of node you want it to find.
        /// @param index The index of the child to get.
        template <class InpP, class P = std::remove_pointer_t<InpP>, std::enable_if_t<std::is_base_of_v<cocos2d::CCNode, P>>* = nullptr>
        NodeQuery<P> type(int index = 0) {
            if (!node) return NodeQuery<P>(nullptr);
            return NodeQuery<P>(node->template getChildByType<P>(index));
        }


        /// Gets a child based on its index. If this holds nothing, this just returns an empty query.
        /// Unlike type, the type parameter just casts. If the child at that index is not of type InpP, it will return nullptr!
        /// @tparam InpP The type of node you want it to return. If the node isn't of that type, it will end up as nullptr.
        /// @param index The index of the child to get.
        template <class InpP = cocos2d::CCNode*, class P = std::remove_pointer_t<InpP>, std::enable_if_t<std::is_base_of_v<cocos2d::CCNode, P>>* = nullptr>
        NodeQuery<P> index(int index) {
            if (!node) return NodeQuery<P>(nullptr);
            return NodeQuery<P>(geode::cast::typeinfo_cast<P*>(node->getChildByIndex(index)));
        }

        /// Gets a child based on its tag. If this holds nothing, this just returns an empty query.
        /// @tparam InpP The type of node you want it to return. If the node isn't of that type, it will end up as nullptr.
        /// @param tag The tag of the child to get.
        template <class InpP = cocos2d::CCNode*, class P = std::remove_pointer_t<InpP>, std::enable_if_t<std::is_base_of_v<cocos2d::CCNode, P>>* = nullptr>
        NodeQuery<P> tag(int tag) {
            if (!node) return NodeQuery<P>(nullptr);
            return NodeQuery<P>(geode::cast::typeinfo_cast<P*>(node->getChildByTag(tag)));
        }

        /// Gets a child based on its sprite name. If this holds nothing, this just returns an empty query.
        /// @tparam InpP The type of node you want it to return. If the node isn't of that type, it will end up as nullptr.
        /// @param name The sprite name of the child to get.
        /// @param index The index of the child to get.
        template <class InpP = cocos2d::CCNode*, class P = std::remove_pointer_t<InpP>, std::enable_if_t<std::is_base_of_v<cocos2d::CCNode, P>>* = nullptr>
        NodeQuery<P> sprite(const char* name, int index = 0) {
            if (!node) return NodeQuery<P>(nullptr);
            return NodeQuery<P>(geode::cast::typeinfo_cast<P*>(geode::cocos::getChildBySpriteName(node, name, index)));
        }

        /// Gets a child based on its sprite frame name. If this holds nothing, this just returns an empty query.
        /// @tparam InpP The type of node you want it to return. If the node isn't of that type, it will end up as nullptr.
        /// @param name The sprite frame name of the child to get.
        /// @param index The index of the child to get.
        template <class InpP = cocos2d::CCNode*, class P = std::remove_pointer_t<InpP>, std::enable_if_t<std::is_base_of_v<cocos2d::CCNode, P>>* = nullptr>
        NodeQuery<P> spriteFrame(const char* name, int index = 0) {
            if (!node) return NodeQuery<P>(nullptr);
            return NodeQuery<P>(geode::cast::typeinfo_cast<P*>(geode::cocos::getChildBySpriteFrameName(node, name, index)));
        }

        /// Gets the node this contains, can be nullptr.
        T* get() {
            return node;
        }

        /// Gets a ref of the node this contains, can be nullptr.
        geode::Ref<T> ref() {
            return Ref(node);
        }

        /// Calls the lambda passed in if the node exists, and passes the node to the lambda.
        NodeQuery<T> ifOk(geode::Function<void(T* node)> callback) {
            if (exists()) callback(node);
            return *this;
        }

        /// Calls the lambda passed in if the node does not exist.
        NodeQuery<T> ifErr(geode::Function<void()> callback) {
            if (!exists()) callback();
            return *this;
        }

        /// Calls the lambda passed in for you to check and handle.
        NodeQuery<T> run(geode::Function<void(T* node)> callback) {
            callback(node);
            return *this;
        }

        /// If the query has a node.
        bool exists() {
            return node != nullptr;
        }

        /// If the query has a node.
        explicit operator bool() const noexcept {
            return node != nullptr;
        }

        /// Lets you call functions on the node.
        T* operator->() const noexcept {
            return node;
        }

        /// Gets the node this contains, can be nullptr.
        T* operator*() const noexcept {
            return node;
        }

        bool operator==(NodeQuery const& other) const noexcept {
            return node == other.node;
        }

        bool operator==(cocos2d::CCNode const* other) const noexcept {
            return node == other;
        }

        bool operator==(std::nullptr_t) const noexcept {
            return node == nullptr;
        }
    };
}
