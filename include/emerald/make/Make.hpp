#pragma once

#include <concepts>
#include <Geode/ui/Button.hpp>
#include <Geode/ui/Toggler.hpp>
#include <Geode/ui/Label.hpp>
#include <Geode/ui/PopupManager.hpp>

#include "internal/Macros.hpp"

namespace emerald {
    template <
        class T,
        class Derived
    >
    class MakeBase;

    template <class T>
    class Make : public MakeBase<T, Make<T>> {
    public:
        explicit Make(T* obj) : MakeBase<T, Make>(obj) {}
        explicit Make(geode::Ref<T> const& obj) : MakeBase<T, Make>(obj) {}
    };

    template <
        class T,
        class Derived
    >
    class MakeBase {
    protected:
        T* m_obj = nullptr;

        Derived& self() noexcept {
            return static_cast<Derived&>(*this);
        }
    public:
        explicit MakeBase(T* obj) : m_obj(obj) {}
        explicit MakeBase(geode::Ref<T> obj) : m_obj(obj) {}

        #include "internal/CCObject.inc"
        #include "internal/CCNode.inc"
        #include "internal/CCProtocols.inc"
        #include "internal/CCLayer.inc"
        #include "internal/CCSprite.inc"
        #include "internal/CCMenu.inc"

        #include "internal/SimplePlayer.inc"

        #include "internal/Border.inc"
        #include "internal/Button.inc"
        #include "internal/BoxedLabel.inc"
        #include "internal/Label.inc"
        #include "internal/Layout.inc"
        #include "internal/NineSlice.inc"
        #include "internal/PregressBar.inc" // not a typo btw
        #include "internal/ScrollLayer.inc"
        #include "internal/SliderNode.inc"
        #include "internal/TextAreas.inc"
        #include "internal/TextInput.inc"
        #include "internal/Toggler.inc"

        #include "internal/Misc.inc"

        // TODO: ButtonBackgroundSprite (https://github.com/geode-sdk/geode/pull/2341)

        T* get() {
            return m_obj;
        }

        geode::Ref<T> ref() {
            return Ref(m_obj);
        }

        explicit operator bool() const noexcept {
            return m_obj != nullptr;
        }

        T* operator->() const noexcept {
            return m_obj;
        }

        T* operator*() const noexcept {
            return m_obj;
        }

        bool operator==(Derived const& other) const noexcept {
            return m_obj == other.m_obj;
        }

        bool operator==(cocos2d::CCObject const* other) const noexcept {
            return m_obj == other;
        }

        bool operator==(std::nullptr_t) const noexcept {
            return m_obj == nullptr;
        }

        operator T*() const { return m_obj; }
    };

    template <class T>
    class NPMake {
    protected:
        T m_obj;
    public:
        explicit NPMake(const T& obj) : m_obj(obj) {}
        explicit NPMake(T&& obj) : m_obj(std::move(obj)) {}
        template <typename ...Args>
        explicit NPMake(Args... args) : m_obj{args...} {}

        #include "internal/MDConfig.inc"

        T& get() {
            return m_obj;
        }

        T move() {
            return std::move(m_obj);
        }

        T& operator->() const noexcept {
            return m_obj;
        }

        T& operator*() const noexcept {
            return m_obj;
        }

        operator T&() const { return m_obj; }
    };
}

#undef callBase
#undef callBaseTo
#undef callBaseWithReqs
#undef call
#undef callP
#undef callPT
#undef callPWithReqs
#undef withOther
#undef withOtherC
#undef createP
#undef createPWithReqs
#undef setMember
#undef npCallBase
#undef npCallP