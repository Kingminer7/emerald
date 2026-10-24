#pragma once

#include <Geode/cocos/menu_nodes/CCMenuItem.h>
#include <Geode/utils/function.hpp>

namespace emerald {
    /// Intercepts the callback of a CCMenuItem.
    /// Yes, I know it is spelled wrong. I do not care.
    struct Intercepter : cocos2d::CCObject {
        using Callback = geode::Function<void(Intercepter* self, CCObject* sender)>;

        /// Calls the original function of the button.
        /// If another intercepter was used on the menu item before this one, that will be called instead.
        void original(CCObject* sender) const;

        /// Replaces the button's menu handler with its own, and stores itself in a user object.
        static Intercepter* create(cocos2d::CCMenuItem* menuItem, Callback callback);
    protected:
        Intercepter(cocos2d::CCMenuItem* btn, Callback callback);

        void execute(CCObject* sender);

        cocos2d::CCMenuItem* m_btn;
        CCObject* m_origListener;
        cocos2d::SEL_MenuHandler m_origSel;
        Callback callback;
    };
}