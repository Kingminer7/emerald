#pragma once

callP(cocos2d::CCMenu, giveTouchPrio, giveMenuTouchPriority, (int prio), (prio))
callP(cocos2d::CCMenu, handlerPrio, setHandlerPriority, (int prio), (prio))
callP(cocos2d::CCMenu, enabled, setEnabled, (bool enabled), (enabled))
// CCMenuItem
static Make createCB(geode::Function<void(T*)> callback) requires std::is_same_v<T, cocos2d::CCMenuItem> {
    return Make(geode::cocos::CCMenuItemExt::create(std::move(callback)));
}
call(cocos2d::CCMenuItem, activate, activate)
call(cocos2d::CCMenuItem, select, selected) // no clue why youd want to call these but might as well include em
call(cocos2d::CCMenuItem, unselect, unselected)
callP(cocos2d::CCMenuItem, enabled, setEnabled, (bool enabled), (enabled))
callP(cocos2d::CCMenuItem, target, setTarget, (cocos2d::CCObject* listener, cocos2d::SEL_MenuHandler selector), (listener, selector))
callBase(cocos2d::CCMenuItem, setCallback, (geode::Function<void(T* obj)> callback)) {
    if (m_obj) geode::cocos::CCMenuItemExt::assignCallback(m_obj, std::move(callback));
    return *this;
}
callPT(cocos2d::CCMenuItem, addCallback, addActivateCallback, Callback, (Callback&& callback, int prio = 0), (std::forward<Callback>(callback), prio))
// CCMenuItemSprite
static Make createCB(cocos2d::CCNode* normal, cocos2d::CCNode* selected, geode::Function<void(T*)> callback) requires std::is_same_v<T, cocos2d::CCMenuItemSprite> {
    return Make(geode::cocos::CCMenuItemExt::createSprite(normal, selected, std::move(callback)));
}
static Make createCB(cocos2d::CCNode* normal, cocos2d::CCNode* selected, cocos2d::CCNode* disabled, geode::Function<void(T*)> callback) requires std::is_same_v<T, cocos2d::CCMenuItemSprite> {
    return Make(geode::cocos::CCMenuItemExt::createSprite(normal, selected, disabled, std::move(callback)));
}
callP(cocos2d::CCMenuItemSprite, displayNode, setNormalImage, (cocos2d::CCNode* node), (node))
callP(cocos2d::CCMenuItemSprite, selectedNode, setSelectedImage, (cocos2d::CCNode* node), (node))
callP(cocos2d::CCMenuItemSprite, disabledNode, setDisabledImage, (cocos2d::CCNode* node), (node))
withOtherC(cocos2d::CCMenuItemSprite, withDisplayNode, cocos2d::CCNode, node, m_obj->getNormalImage())
withOtherC(cocos2d::CCMenuItemSprite, withSelectedNode, cocos2d::CCNode, node, m_obj->getSelectedImage())
withOtherC(cocos2d::CCMenuItemSprite, withDisabledNode, cocos2d::CCNode, node, m_obj->getDisabledImage())
// CCMenuItemSpriteExtra
static Make createCB(cocos2d::CCNode* sprite, geode::Function<void(T*)> callback) requires std::is_same_v<T, CCMenuItemSpriteExtra> {
    return Make(geode::cocos::CCMenuItemExt::createSpriteExtra(sprite, std::move(callback)));
}
static Make createFileName(geode::ZStringView fileName, float scale, geode::Function<void(T*)> callback) requires std::is_same_v<T, CCMenuItemSpriteExtra> {
    return Make(geode::cocos::CCMenuItemExt::createSpriteExtraWithFilename(fileName, scale, std::move(callback)));
}
static Make createFrameName(geode::ZStringView frameName, float scale, geode::Function<void(T*)> callback) requires std::is_same_v<T, CCMenuItemSpriteExtra> {
    return Make(geode::cocos::CCMenuItemExt::createSpriteExtraWithFrameName(frameName, scale, std::move(callback)));
}
callP(CCMenuItemSpriteExtra, sizeMult, setSizeMult, (float mult), (mult))
callP(CCMenuItemSpriteExtra, sprite, setSprite, (cocos2d::CCSprite* sprite), (sprite))
call(CCMenuItemSpriteExtra, updateSprite, updateSprite)
callP(CCMenuItemSpriteExtra, animType, useAnimationType, (MenuAnimationType type), (type))
setMember(CCMenuItemSpriteExtra, scaleMult, m_scaleMultiplier, (float mult), mult)
setMember(CCMenuItemSpriteExtra, baseScale, m_baseScale, (float base), base)
setMember(CCMenuItemSpriteExtra, animEnabled, m_animationEnabled, (bool enabled), enabled)
setMember(CCMenuItemSpriteExtra, colorEnabled, m_colorEnabled, (bool enabled), enabled)
setMember(CCMenuItemSpriteExtra, soundVolume, m_volume, (float vol), vol)
setMember(CCMenuItemSpriteExtra, activateSound, m_activateSound, (std::string sound), sound)
setMember(CCMenuItemSpriteExtra, colorDip, m_colorDip, (float dip), dip)
setMember(CCMenuItemSpriteExtra, iconType, m_iconType, (IconType type), type)
// CCMenuItemToggler
static Make createCB(cocos2d::CCNode* onNode, cocos2d::CCNode* offNode, geode::Function<void(T*)> callback) requires std::is_same_v<T, CCMenuItemToggler> {
    return Make(geode::cocos::CCMenuItemExt::createToggler(onNode, offNode, std::move(callback)));
}
static Make createStandard(float scale , geode::Function<void(T*)> callback) requires std::is_same_v<T, CCMenuItemToggler> {
    return Make(geode::cocos::CCMenuItemExt::createTogglerWithStandardSprites(scale, std::move(callback)));
}
static Make createFileName(geode::ZStringView onFileName, geode::ZStringView offFileName, float scale, geode::Function<void(T*)> callback) requires std::is_same_v<T, CCMenuItemToggler> {
    return Make(geode::cocos::CCMenuItemExt::createTogglerWithFilename(onFileName, offFileName, scale, std::move(callback)));
}
static Make createFrameName(geode::ZStringView onFrameName, geode::ZStringView offFrameName, float scale, geode::Function<void(T*)> callback) requires std::is_same_v<T, CCMenuItemToggler> {
    return Make(geode::cocos::CCMenuItemExt::createTogglerWithFrameName(onFrameName, offFrameName, scale, std::move(callback)));
}
callP(CCMenuItemToggler, clickable, setClickable, (bool clickable), (clickable))
callP(CCMenuItemToggler, sizeMult, setSizeMult, (float mult), (mult))
call(CCMenuItemToggler, updateSprite, updateSprite)
callBase(CCMenuItemToggler, toggle, (bool on, bool callback = true)) {
    if (m_obj) {
        if (callback) m_obj->toggleWithCallback(on);
        else m_obj->toggle(on);
    }
    return *this;
}
withOther(CCMenuItemToggler, withOnBtn, CCMenuItemSpriteExtra, btn, m_obj->m_onButton)
withOther(CCMenuItemToggler, withOffBtn, CCMenuItemSpriteExtra, btn, m_obj->m_offButton)