#pragma once

#include <Geode/cocos/menu_nodes/CCMenuItem.h>
#include <Geode/utils/function.hpp>

namespace emerald {
    struct Intercepter : cocos2d::CCObject {
        using Callback = geode::Function<void(Intercepter* self, CCObject* sender)>;

        void original(CCObject* sender) const;
        void execute(CCObject* sender);

        static Intercepter* create(cocos2d::CCMenuItem* orig, Callback callback);
    protected:
        Intercepter(cocos2d::CCMenuItem* btn, Callback callback);

        cocos2d::CCMenuItem* m_btn;
        CCObject* m_origListener;
        cocos2d::SEL_MenuHandler m_origSel;
        Callback callback;
    };
}