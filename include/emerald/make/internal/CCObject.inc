#pragma once

call(cocos2d::CCObject, retain, retain)
call(cocos2d::CCObject, release, release)
call(cocos2d::CCObject, autorel, autorelease)
callP(cocos2d::CCObject, tag, setTag, (int tag), (tag))
callBase(cocos2d::CCObject, store, (T*& var)) {
    var = m_obj;
    return *this;
}
callBase(cocos2d::CCObject, store, (geode::Ref<T>& var)) {
    var = m_obj;
    return *this;
}