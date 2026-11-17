#pragma once

callP(geode::BoxedLabel, text, setText, (std::string text), (std::move(text)))
callP(geode::BoxedLabel, font, setFont, (geode::ZStringView font), (font))
callP(geode::BoxedLabel, textScale, setTextScale, (float scale), (scale))
callP(geode::BoxedLabel, align, setTextAlignment, (geode::Label::Alignment alignment), (alignment))
callP(geode::BoxedLabel, maxWidth, setMaxWidth, (float max), (max))
callP(geode::BoxedLabel, padding, setPadding, (float padding), (padding))
callP(geode::BoxedLabel, boxSprite, setBoxSprite, (geode::ZStringView sprite), (sprite))
callP(geode::BoxedLabel, boxOpacity, setBoxOpacity, (GLubyte opacity), (opacity))
callP(geode::BoxedLabel, boxScale, setBoxScale, (float scale), (scale))
callP(geode::BoxedLabel, lockWidth, lockWidth, (bool lock), (lock))
withOther(geode::BoxedLabel, withLabel, geode::Label, label, m_obj->getLabelNode())
withOther(geode::BoxedLabel, withBox, geode::NineSlice, label, m_obj->getBoxSprite())