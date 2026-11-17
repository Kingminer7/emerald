#pragma once

call(geode::MDTextArea, updateLabel, updateLabel)
callP(geode::MDTextArea, text, setText, (std::string text), (std::move(text)))
withOther(geode::MDTextArea, withScroll, geode::ScrollLayer, scroll, m_obj->getScrollLayer())
call(geode::MDTextArea, scrollToTop, scrollToTop)

callP(geode::SimpleTextArea, font, setFont, (std::string font), (std::move(font)))
callP(geode::SimpleTextArea, color, setColor, (const cocos2d::ccColor4B& color), (color))
callP(geode::SimpleTextArea, align, setAlignment, (cocos2d::CCTextAlignment alignment), (alignment))
callP(geode::SimpleTextArea, wrappingMode, setWrappingMode, (geode::WrappingMode mode), (mode))
callP(geode::SimpleTextArea, text, setText, (std::string text), (std::move(text)))
callP(geode::SimpleTextArea, maxLines, setMaxLines, (size_t maxLines), (maxLines))
callP(geode::SimpleTextArea, areaWidth, setWidth, (float width), (width))
callP(geode::SimpleTextArea, linePadding, setLinePadding, (float padding), (padding))