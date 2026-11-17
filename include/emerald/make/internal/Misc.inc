#pragma once

callBase(cocos2d::CCNode, sideArt, (geode::SideArt sides = geode::SideArt::All, bool useAnchorLayout = false)) {
    geode::addSideArt(m_obj, sides, useAnchorLayout);
    return *this;
}

callBase(cocos2d::CCNode, sideArt, (geode::SideArt sides, geode::SideArtStyle style, bool useAnchorLayout = false)) {
    geode::addSideArt(m_obj, sides, style, useAnchorLayout);
    return *this;
}

callBase(cocos2d::CCNode, listBorders, (cocos2d::CCPoint const& center, cocos2d::CCSize const& size)) {
    geode::addListBorders(m_obj, center, size);
    return *this;
}

callBase(cocos2d::CCNode, backButton, (geode::BackButtonStyle style = geode::BackButtonStyle::Green)) {
    geode::addBackButton(m_obj, style);
    return *this;
}

callBase(cocos2d::CCNode, backButton, (geode::Button::ButtonCallback callback, geode::BackButtonStyle style = geode::BackButtonStyle::Green)) {
    geode::addBackButton(m_obj, std::move(callback), style);
    return *this;
}

call(FLAlertLayer, show, show)


Make with(geode::Function<void(T* obj)> callback) {
    callback(m_obj);
    return *this;
}

Make onlyIf(bool condition, geode::Function<void(Make obj)> callback) {
    if (condition) callback(*this);
    return *this;
}

template <typename ...Args>
static Make create(Args... args) {
    return Make(T::create(args...));
}