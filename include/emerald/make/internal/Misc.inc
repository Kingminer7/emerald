#pragma once

callBase(cocos2d::CCNode, sideArt, (geode::SideArt sides = geode::SideArt::All, bool useAnchorLayout = false)) {
    geode::addSideArt(m_obj, sides, useAnchorLayout);
    return this->self();
}

callBase(cocos2d::CCNode, sideArt, (geode::SideArt sides, geode::SideArtStyle style, bool useAnchorLayout = false)) {
    geode::addSideArt(m_obj, sides, style, useAnchorLayout);
    return this->self();
}

callBase(cocos2d::CCNode, listBorders, (cocos2d::CCPoint const& center, cocos2d::CCSize const& size)) {
    geode::addListBorders(m_obj, center, size);
    return this->self();
}

callBase(cocos2d::CCNode, backButton, (geode::BackButtonStyle style = geode::BackButtonStyle::Green)) {
    geode::addBackButton(m_obj, style);
    return this->self();
}

callBase(cocos2d::CCNode, backButton, (geode::Button::ButtonCallback callback, geode::BackButtonStyle style = geode::BackButtonStyle::Green)) {
    geode::addBackButton(m_obj, std::move(callback), style);
    return this->self();
}

call(FLAlertLayer, show, show)


Derived with(geode::Function<void(T* obj)> callback) {
    callback(m_obj);
    return this->self();
}

Derived withMake(geode::Function<void(Derived obj)> callback) {
    callback(this->self());
    return this->self();
}

Derived onlyIf(bool condition, geode::Function<void(Derived obj)> callback) {
    if (condition) callback(this->self());
    return this->self();
}

template <typename ...Args>
static Derived create(Args... args) {
    return Derived(T::create(args...));
}