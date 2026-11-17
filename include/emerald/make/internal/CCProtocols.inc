#pragma once

callP(cocos2d::CCRGBAProtocol, opacity, setOpacity, (GLubyte opacity), (opacity))
callP(cocos2d::CCRGBAProtocol, color, setColor, (const cocos2d::ccColor3B& color), (color))
callP(cocos2d::CCRGBAProtocol, color, setColor, (GLubyte r, GLubyte g, GLubyte b), (cocos2d::ccColor3B{r, g, b}))
callBase(cocos2d::CCRGBAProtocol, color, (const cocos2d::ccColor4B& color)) {
    if (m_obj) {
        m_obj->setColor(cocos2d::ccColor3B{color.r, color.g, color.b});
        m_obj->setOpacity(color.a);
    }
    return *this;
}
callBase(cocos2d::CCRGBAProtocol, color, (GLubyte r, GLubyte g, GLubyte b, GLubyte a)) {
    if (m_obj) {
        m_obj->setColor(cocos2d::ccColor3B{r, g, b});
        m_obj->setOpacity(a);
    }
    return *this;
}
callP(cocos2d::CCRGBAProtocol, cascadeOpacity, setCascadeOpacityEnabled, (bool enabled), (enabled))
callP(cocos2d::CCRGBAProtocol, cascadeColor, setCascadeColorEnabled, (bool enabled), (enabled))
callP(cocos2d::CCRGBAProtocol, opacityModRGB, setOpacityModifyRGB, (bool enabled), (enabled))
callP(cocos2d::CCBlendProtocol, blend, setBlendFunc, (cocos2d::ccBlendFunc func), (func))
callP(cocos2d::CCTextureProtocol, texture, setTexture, (cocos2d::CCTexture2D* texture), (texture))
callP(cocos2d::CCLabelProtocol, text, setString, (const char* text), (text))
// yeah some stuff have methods that take in std::string already so those shouldnt have this
callPWithReqs(cocos2d::CCLabelProtocol, text, setString, (const std::string& text), (text.c_str()),
    !(std::derived_from<T, geode::Label> && std::derived_from<T, geode::MDTextArea>))