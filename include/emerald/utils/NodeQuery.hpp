#pragma once

#include <Geode/cocos/base_nodes/CCNode.h>
#include <string_view>
#include <type_traits>

template <class InpT = cocos2d::CCNode*, class T = std::remove_pointer_t<InpT>, std::enable_if_t<std::is_base_of_v<cocos2d::CCNode, T>>* = nullptr>
class NodeQuery {
protected:
    T* node;
public:
    explicit NodeQuery(T* node) : node(node) {}
    explicit NodeQuery(geode::Ref<T> node) : node(node) {}

    template <class InpP = cocos2d::CCNode*, class P = std::remove_pointer_t<InpP>, std::enable_if_t<std::is_base_of_v<cocos2d::CCNode, P>>* = nullptr>
    NodeQuery<P> id(std::string_view id) {
        if (!node) return NodeQuery<P>(nullptr);
        return NodeQuery<P>(geode::cast::typeinfo_cast<P*>(node->getChildByID(id)));
    }

    template <class InpP = cocos2d::CCNode*, class P = std::remove_pointer_t<InpP>, std::enable_if_t<std::is_base_of_v<cocos2d::CCNode, P>>* = nullptr>
    NodeQuery<P> idRec(std::string_view id) {
        if (!node) return NodeQuery<P>(nullptr);
        return NodeQuery<P>(geode::cast::typeinfo_cast<P*>(node->getChildByIDRecursive(id)));
    }

    template <class InpP, class P = std::remove_pointer_t<InpP>, std::enable_if_t<std::is_base_of_v<cocos2d::CCNode, P>>* = nullptr>
    NodeQuery<P> type(int index = 0) {
        if (!node) return NodeQuery<P>(nullptr);
        return NodeQuery<P>(node->template getChildByType<P>(index));
    }

    template <class InpP = cocos2d::CCNode*, class P = std::remove_pointer_t<InpP>, std::enable_if_t<std::is_base_of_v<cocos2d::CCNode, P>>* = nullptr>
    NodeQuery<P> index(int index) {
        if (!node) return NodeQuery<P>(nullptr);
        return NodeQuery<P>(geode::cast::typeinfo_cast<P*>(node->getChildByIndex(index)));
    }

    template <class InpP = cocos2d::CCNode*, class P = std::remove_pointer_t<InpP>, std::enable_if_t<std::is_base_of_v<cocos2d::CCNode, P>>* = nullptr>
    NodeQuery<P> tag(int tag) {
        if (!node) return NodeQuery<P>(nullptr);
        return NodeQuery<P>(geode::cast::typeinfo_cast<P*>(node->getChildByTag(tag)));
    }

    T* get() {
        return node;
    }

    geode::Ref<T> ref() {
        return Ref(node);
    }

    NodeQuery<T> ifOk(geode::Function<void()> callback) {
        if (exists()) callback();
        return *this;
    }

    NodeQuery<T> ifErr(geode::Function<void()> callback) {
        if (!exists()) callback();
        return *this;
    }

    NodeQuery<T> run(geode::Function<void(T* node)> callback) {
        callback(node);
        return *this;
    }

    bool exists() {
        return node != nullptr;
    }

    explicit operator bool() const noexcept {
        return node != nullptr;
    }

    T* operator->() const noexcept {
        return node;
    }

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
