#pragma once

static createP(geode::NineSlice, createFrame, createWithSpriteFrame, (cocos2d::CCSpriteFrame* frame, geode::NineSlice::Insets const& insets = {}), (frame, insets))
static createP(geode::NineSlice, createFrameName, createWithSpriteFrameName, (geode::ZStringView frameName, geode::NineSlice::Insets const& insets = {}), (frameName, insets))
callP(geode::NineSlice, scaleMult, setScaleMultiplier, (float mult), (mult))
callP(geode::NineSlice, repeatCenter, setRepeatCenter, (bool repeat), (repeat))
callP(geode::NineSlice, insets, setInsets, (geode::NineSlice::Insets const& insets), (insets))
callP(geode::NineSlice, insets, setInsets, (float top, float right, float bottom, float left), (geode::NineSlice::Insets{top, right, bottom, left}))
callP(geode::NineSlice, insetTop, setInsetTop, (float top), (top))
callP(geode::NineSlice, insetRight, setInsetRight, (float right), (right))
callP(geode::NineSlice, insetBottom, setInsetBottom, (float bottom), (bottom))
callP(geode::NineSlice, insetLeft, setInsetLeft, (float left), (left))