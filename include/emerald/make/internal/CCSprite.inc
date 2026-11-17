#pragma once

// if you wonder why these creates are templated,
// some classes have extra args for creates like the BasedButtonSprite ones,
// so why create specialized ones when you can just template
template <typename ...Args>
static createP(cocos2d::CCSprite, createTexture, createWithTexture, (cocos2d::CCTexture2D* texture, Args... args), (texture, args...))
template <typename ...Args>
static createP(cocos2d::CCSprite, createFrame, createWithSpriteFrame, (cocos2d::CCSpriteFrame* frame, Args... args), (frame, args...))
template <typename ...Args> // Some classes have extra args like the BasedButtonSprite ones, so why create specialized ones
static createP(cocos2d::CCSprite, createFrameName, createWithSpriteFrameName, (const char* frameName, Args... args), (frameName, args...))
callP(cocos2d::CCSprite, batchNode, setBatchNode, (cocos2d::CCSpriteBatchNode* batch), (batch))
callP(cocos2d::CCSprite, texRect, setTextureRect, (const cocos2d::CCRect& rect), (rect))
callP(cocos2d::CCSprite, texRect, setTextureRect, (const cocos2d::CCRect& rect, bool rotated, const cocos2d::CCSize& untrimmedSize), (rect, rotated, untrimmedSize))
callP(cocos2d::CCSprite, displayFrame, setDisplayFrame, (cocos2d::CCSpriteFrame* pNewFrame), (pNewFrame))
callP(cocos2d::CCSprite, displayFrameAnimName, setDisplayFrameWithAnimationName, (const char* animationName, int frameIndex), (animationName, frameIndex))
callP(cocos2d::CCSprite, setDirty, setDirty, (bool dirty), (dirty))
callP(cocos2d::CCSprite, flipX, setFlipX, (bool flip), (flip))
callP(cocos2d::CCSprite, flipY, setFlipY, (bool flip), (flip))
callBase(cocos2d::CCSprite, flip, (bool x, bool y)) {
    if (m_obj) {
        m_obj->setFlipX(x);
        m_obj->setFlipY(y);
    }
    return *this;
}

// LazySprite
callP(geode::LazySprite, fromUrl, loadFromUrl, (std::string url, geode::LazySprite::Format format = geode::LazySprite::Format::kFmtUnKnown, bool ignoreCache = false), (std::move(url), format, ignoreCache))
callP(geode::LazySprite, fromFile, loadFromFile, (asp::fs::Path path, geode::LazySprite::Format format = geode::LazySprite::Format::kFmtUnKnown, bool ignoreCache = false), (std::move(path), format, ignoreCache))
callP(geode::LazySprite, fromData, loadFromData, (std::span<uint8_t const> data, geode::LazySprite::Format format = geode::LazySprite::Format::kFmtUnKnown), (std::move(data), format))
callP(geode::LazySprite, fromData, loadFromData, (uint8_t const* ptr, geode::LazySprite::Format format = geode::LazySprite::Format::kFmtUnKnown), (ptr, format))
callP(geode::LazySprite, setOnLoad, setLoadCallback, (geode::LazySprite::Callback callback), (std::move(callback)))
callP(geode::LazySprite, autoResize, setAutoResize, (bool resize), (resize))

// BasedButtonSprite
template <typename ...Args>
// BasedButtonSprite does not have createWithSprite but every subclass does, so thats why it is not same as.
static createPWithReqs(geode::BasedButtonSprite, createFileName, createWithSprite, (char const* sprName, float sprScale = 1.f, Args... args), (sprName, sprScale, args...), (!std::is_same_v<T, geode::BasedButtonSprite>))
callP(geode::BasedButtonSprite, topOffset, setTopOffset, (cocos2d::CCPoint const& offset), (offset));
callP(geode::BasedButtonSprite, topOffset, setTopOffset, (float x, float y), (cocos2d::CCPoint{x, y}));
callP(geode::BasedButtonSprite, topScale, setTopRelativeScale, (float scale), (scale));
// dont need creates for each class because the templated methods should cover it all