#pragma once

call(cocos2d::CCLayer, registerTouch, registerWithTouchDispatcher)
callP(cocos2d::CCLayer, touchEnabled, setTouchEnabled, (bool enabled), (enabled))
callP(cocos2d::CCLayer, touchPrio, setTouchPriority, (int prio), (prio))
callP(cocos2d::CCLayer, keypadEnabled, setKeypadEnabled, (bool enabled), (enabled))
callP(cocos2d::CCLayer, keyboardEnabled, setKeyboardEnabled, (bool enabled), (enabled))
callP(cocos2d::CCLayer, mouseEnabled, setMouseEnabled, (bool enabled), (enabled))
callBase(cocos2d::CCLayer, push, ()) {
    geode::pushSceneWithLayer(m_obj);
    return this->self();
}