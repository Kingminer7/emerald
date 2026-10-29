#pragma once

#include <concepts>
#include <Geode/ui/Button.hpp>
#include <Geode/ui/Label.hpp>

#include "Macros.hpp"

namespace emerald {
    template <class T> requires std::derived_from<T, cocos2d::CCObject>
    class Make {
    protected:
        T* m_obj;
    public:
        explicit Make(T* obj) : m_obj(obj) {}
        explicit Make(geode::Ref<T> obj) : m_obj(obj) {}

        // CCObject

        callSN(cocos2d::CCObject, retain)
        callSN(cocos2d::CCObject, release)
        call(cocos2d::CCObject, autorel, autorelease)
        call1(cocos2d::CCObject, tag, setTag, int, tag)
        callBase(cocos2d::CCObject, store, (T*& var)) {
            var = m_obj;
            return *this;
        }

        // CCNode
        call1(cocos2d::CCNode, zOrder, setZOrder, int, zOrder)
        call1(cocos2d::CCNode, scaleX, setScaleX, float, x)
        call1(cocos2d::CCNode, scaleY, setScaleY, float, y)
        call1(cocos2d::CCNode, scale, setScale, float, scale)
        call2(cocos2d::CCNode, scale, setScale, float, x, float, y)
        call1(cocos2d::CCNode, posX, setPositionX, float, x)
        call1(cocos2d::CCNode, posY, setPositionY, float, y)
        call1(cocos2d::CCNode, pos, setPosition, const cocos2d::CCPoint&, pos)
        call2(cocos2d::CCNode, pos, setPosition, float, x, float, y)
        call1(cocos2d::CCNode, skewX, setSkewX, float, x)
        call1(cocos2d::CCNode, skewY, setSkewY, float, y)
        callBase(cocos2d::CCNode, skew, (float x, float y)){
            this->m_obj->setSkewY(x);
            this->m_obj->setSkewY(y);
            return *this;
        }
        call1(cocos2d::CCNode, anchorPoint, setAnchorPoint, const cocos2d::CCPoint&, anchor)
        call2Comb(cocos2d::CCNode, anchorPoint, setAnchorPoint, float, x, float, y, cocos2d::CCPoint)
        call1(cocos2d::CCNode, width, setContentWidth, float, width)
        call1(cocos2d::CCNode, height, setContentHeight, float, height)
        call1(cocos2d::CCNode, size, setContentSize, const cocos2d::CCSize&, size)
        call2Comb(cocos2d::CCNode, size, setContentSize, float, x, float, y, cocos2d::CCSize)
        call1(cocos2d::CCNode, visible, setVisible, bool, vis)
        call1(cocos2d::CCNode, rotationX, setRotationX, float, x)
        call1(cocos2d::CCNode, rotationY, setRotationY, float, y)
        call1(cocos2d::CCNode, rotation, setRotation, float, rot)
        call1(cocos2d::CCNode, orderArrive, setOrderOfArrival, unsigned int, order)
        call1(cocos2d::CCNode, ignoreAnchor, ignoreAnchorPointForPosition, bool, ignore)
        call1(cocos2d::CCNode, child, addChild, cocos2d::CCNode*, child)
        call2(cocos2d::CCNode, child, addChild, cocos2d::CCNode*, child, int, zOrder)
        call3(cocos2d::CCNode, child, addChild, cocos2d::CCNode*, child, int, zOrder, int, tag)
        callP(cocos2d::CCNode, childAtPos, addChildAtPosition, (cocos2d::CCNode* child, geode::Anchor anchor, cocos2d::CCPoint const& offset = {}, bool useAnchorLayout = true), (child, anchor, offset, useAnchorLayout))
        callP(cocos2d::CCNode, childAtPos, addChildAtPosition, (cocos2d::CCNode* child, geode::Anchor anchor, cocos2d::CCPoint const& offset, cocos2d::CCPoint const& nodeAnchor, bool useAnchorLayout = true), (child, anchor, offset, nodeAnchor, useAnchorLayout))
        call1(cocos2d::CCNode, children, addChildren, std::span<cocos2d::CCNode* const>, children)
        template <typename ...Args>
        callBase(cocos2d::CCNode, children, (Args... children)) {
            this->m_obj->addChildren(children...);
            return *this;
        }
        call1(cocos2d::CCNode, userObj, setUserObject, cocos2d::CCObject*, obj)
        call2(cocos2d::CCNode, userObj, setUserObject, std::string, id, cocos2d::CCObject*, obj)
        callP(cocos2d::CCNode, flag, setUserFlag, (std::string id, bool state = false), (id, state))
        call1(cocos2d::CCNode, id, setID, std::string, id)
        call1(cocos2d::CCNode, layout, setLayout, geode::Layout*, layout)
        callP(cocos2d::CCNode, layoutOpts, setLayoutOptions, (geode::LayoutOptions* opts, bool update = true), (opts, update))
        callSN(cocos2d::CCNode, updateLayout)
        template <class Event, class Callback>
        callP(cocos2d::CCNode, listen, addEventListener, (Event const& event, Callback&& callback, int prio = 0), (event, callback, prio))
        template <class Event, class Callback>
        callP(cocos2d::CCNode, listen, addEventListener, (std::string_view id, Event const& event, Callback&& callback, int prio = 0), (id, event, callback, prio))
        template <class Callback>
        callP(cocos2d::CCNode, onEnter, addOnEnterCallback, (Callback&& callback, int prio = 0), (callback, prio))
        template <class Callback>
        callP(cocos2d::CCNode, onEnterTransFinished, addOnEnterTransitionDidFinishCallback, (Callback&& callback, int prio = 0), (callback, prio))
        template <class Callback>
        callP(cocos2d::CCNode, onExit, addOnExitCallback, (Callback&& callback, int prio = 0), (callback, prio))
        template <class Callback>
        callP(cocos2d::CCNode, onExitTransStart, addOnExitTransitionDidStartCallback, (Callback&& callback, int prio = 0), (callback, prio))
        template <class Callback>
        callP(cocos2d::CCNode, onCleanup, addCleanupCallback, (Callback&& callback, int prio = 0), (callback, prio))
        call1(cocos2d::CCNode, shader, setShaderProgram, cocos2d::CCGLProgram*, shader)
        call1(cocos2d::CCNode, action, runAction, cocos2d::CCAction*, action)

        callBase(cocos2d::CCNode, parent, (cocos2d::CCNode* parent)) {
            parent->addChild(m_obj);
            return *this;
        }
        callBase(cocos2d::CCNode, parent, (cocos2d::CCNode* parent, int zOrder)) {
            parent->addChild(m_obj, zOrder);
            return *this;
        }
        callBase(cocos2d::CCNode, parent, (cocos2d::CCNode* parent, int zOrder, int tag)) {
            parent->addChild(m_obj, zOrder, tag);
            return *this;
        }
        callBase(cocos2d::CCNode, parentAtPos, (cocos2d::CCNode* parent, geode::Anchor anchor, cocos2d::CCPoint const& offset = {}, bool useAnchorLayout = true)) {
            parent->addChildAtPosition(m_obj, anchor, offset, useAnchorLayout);
            return *this;
        }
        callBase(cocos2d::CCNode, parentAtPos, (cocos2d::CCNode* parent, geode::Anchor anchor, cocos2d::CCPoint const& offset, cocos2d::CCPoint const& nodeAnchor, bool useAnchorLayout = true)) {
            parent->addChildAtPosition(m_obj, anchor, offset, nodeAnchor, useAnchorLayout);
            return *this;
        }

        template <typename P>
        callBase(cocos2d::CCNode, intoParent, (P* parent)) {
            parent->addChild(m_obj);
            return Make<P>(parent);
        }
        template <typename P>
        callBase(cocos2d::CCNode, intoParent, (P* parent, int zOrder)) {
            parent->addChild(m_obj, zOrder);
            return Make<P>(parent);
        }
        template <typename P>
        callBase(cocos2d::CCNode, intoParent, (P* parent, int zOrder, int tag)) {
            parent->addChild(m_obj, zOrder, tag);
            return Make<P>(parent);
        }
        template <typename P>
        callBase(cocos2d::CCNode, intoParentAtPos, (P* parent, geode::Anchor anchor, cocos2d::CCPoint const& offset = {}, bool useAnchorLayout = true)) {
            parent->addChildAtPosition(m_obj, anchor, offset, useAnchorLayout);
            return Make<P>(parent);
        }
        template <typename P>
        callBase(cocos2d::CCNode, intoParentAtPos, (P* parent, geode::Anchor anchor, cocos2d::CCPoint const& offset, cocos2d::CCPoint const& nodeAnchor, bool useAnchorLayout = true)) {
            parent->addChildAtPosition(m_obj, anchor, offset, nodeAnchor, useAnchorLayout);
            return Make<P>(parent);
        }

        callBase(cocos2d::CCNode, posAnchored, (geode::Anchor anchor, const cocos2d::CCPoint& pos)) {
            m_obj->setLayoutOptions(geode::AnchorLayoutOptions::create()
                ->setAnchor(anchor)
                ->setOffset(pos));
            return *this;
        }

        // Misc protocols
        call1(cocos2d::CCRGBAProtocol, opacity, setOpacity, GLubyte, opacity)
        call1(cocos2d::CCRGBAProtocol, color, setColor, const cocos2d::ccColor3B&, color)
        call1(cocos2d::CCRGBAProtocol, cascadeOpacity, setCascadeOpacityEnabled, bool, enabled)
        call1(cocos2d::CCRGBAProtocol, cascadeColor, setCascadeColorEnabled, bool, enabled)
        call1(cocos2d::CCRGBAProtocol, opacityModRGB, setOpacityModifyRGB, bool, enabled)
        call1(cocos2d::CCBlendProtocol, blend, setBlendFunc, cocos2d::ccBlendFunc, func)
        call1(cocos2d::CCTextureProtocol, texture, setTexture, cocos2d::CCTexture2D*, texture)
        call1(cocos2d::CCLabelProtocol, text, setString, const char*, text)
        // geode label has its own text method taking an std::string, so this one shouldnt apply to that
        callPWithReqs(cocos2d::CCLabelProtocol, text, setString, (const std::string& text), (text.c_str()), (!std::derived_from<T, geode::Label>))

        // CCLayer
        call(cocos2d::CCLayer, registerTouch, registerWithTouchDispatcher)
        call1(cocos2d::CCLayer, touchEnabled, setTouchEnabled, bool, enabled)
        call1(cocos2d::CCLayer, touchPrio, setTouchPriority, int, prio)
        call1(cocos2d::CCLayer, keypadEnabled, setKeypadEnabled, bool, enabled)
        call1(cocos2d::CCLayer, keyboardEnabled, setKeyboardEnabled, bool, enabled)
        call1(cocos2d::CCLayer, mouseEnabled, setMouseEnabled, bool, enabled)

        // CCSprite
        // if you wonder why these creates are templated,
        // some classes have extra args for creates like the BasedButtonSprite ones,
        // so why create specialized ones when you can just template
        template <typename ...Args>
        static createP(cocos2d::CCSprite, createTexture, createWithTexture, (cocos2d::CCTexture2D* texture, Args... args), (texture, args...))
        template <typename ...Args>
        static createP(cocos2d::CCSprite, createFrame, createWithSpriteFrame, (cocos2d::CCSpriteFrame* frame, Args... args), (frame, args...))
        template <typename ...Args> // Some classes have extra args like the BasedButtonSprite ones, so why create specialized ones
        static createP(cocos2d::CCSprite, createFrameName, createWithSpriteFrameName, (const char* frameName, Args... args), (frameName, args...))
        call1(cocos2d::CCSprite, batchNode, setBatchNode, cocos2d::CCSpriteBatchNode*, batch)
        call1(cocos2d::CCSprite, texRect, setTextureRect, const cocos2d::CCRect&, rect)
        call3(cocos2d::CCSprite, texRect, setTextureRect, const cocos2d::CCRect&, rect, bool, rotated, const cocos2d::CCSize&, untrimmedSize)
        call1(cocos2d::CCSprite, displayFrame, setDisplayFrame, cocos2d::CCSpriteFrame*, pNewFrame)
        call2(cocos2d::CCSprite, displayFrameAnimName, setDisplayFrameWithAnimationName, const char*, animationName, int, frameIndex)
        call1SN(cocos2d::CCSprite, setDirty, bool, dirty)
        call1(cocos2d::CCSprite, flipX, setFlipX, bool, flip)
        call1(cocos2d::CCSprite, flipY, setFlipY, bool, flip)

        // CCMenu and its buttons
        call(cocos2d::CCMenu, giveTouchPrio, giveMenuTouchPriority)
        call1(cocos2d::CCMenu, handlerPrio, setHandlerPriority, int, prio)
        call1(cocos2d::CCMenu, enabled, setEnabled, bool, enabled)
        // CCMenuItem
        static Make createCB(geode::Function<void(T*)> callback) requires std::is_same_v<T, cocos2d::CCMenuItem> {
            return Make(geode::cocos::CCMenuItemExt::create(std::move(callback)));
        }
        callSN(cocos2d::CCMenuItem, activate)
        call(cocos2d::CCMenuItem, select, selected) // no clue why youd want to call these but might as well include em
        call(cocos2d::CCMenuItem, unselect, unselected)
        call1(cocos2d::CCMenuItem, enabled, setEnabled, bool, enabled)
        call2(cocos2d::CCMenu, target, setTarget, cocos2d::CCObject*, listener, cocos2d::SEL_MenuHandler, selector)
        callBase(cocos2d::CCMenu, setCallback, (geode::Function<void(T* obj)> callback)) {
            geode::cocos::CCMenuItemExt::assignCallback(m_obj, std::move(callback));
            return *this;
        }
        callP(cocos2d::CCMenuItem, addCallback, addActivateCallback, (geode::Function<void(T* obj)>&& callback, int prio = 0), (callback, prio))
        // CCMenuItemSprite
        static Make createCB(cocos2d::CCNode* normal, cocos2d::CCNode* selected, geode::Function<void(T*)> callback) requires std::is_same_v<T, cocos2d::CCMenuItemSprite> {
            return Make(geode::cocos::CCMenuItemExt::createSprite(normal, selected, std::move(callback)));
        }
        static Make createCB(cocos2d::CCNode* normal, cocos2d::CCNode* selected, cocos2d::CCNode* disabled, geode::Function<void(T*)> callback) requires std::is_same_v<T, cocos2d::CCMenuItemSprite> {
            return Make(geode::cocos::CCMenuItemExt::createSprite(normal, selected, disabled, std::move(callback)));
        }
        call1(cocos2d::CCMenuItemSprite, displayNode, setNormalImage, cocos2d::CCNode*, node)
        call1(cocos2d::CCMenuItemSprite, selectedNode, setSelectedImage, cocos2d::CCNode*, node)
        call1(cocos2d::CCMenuItemSprite, disabledNode, setDisabledImage, cocos2d::CCNode*, node)
        withOther(cocos2d::CCMenuItemSprite, withDisplayNode, cocos2d::CCNode, node, m_obj->getNormalImage())
        withOther(cocos2d::CCMenuItemSprite, withSelectedNode, cocos2d::CCNode, node, m_obj->getSelectedImage())
        withOther(cocos2d::CCMenuItemSprite, withDisabledNode, cocos2d::CCNode, node, m_obj->getDisabledImage())
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
        call1(CCMenuItemSpriteExtra, sizeMult, setSizeMult, float, mult)
        call1(CCMenuItemSpriteExtra, sprite, setSprite, cocos2d::CCSprite*, sprite)
        callSN(CCMenuItemSpriteExtra, updateSprite)
        call1(CCMenuItemSpriteExtra, animType, useAnimationType, MenuAnimationType, type)
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
        call1(CCMenuItemToggler, clickable, setClickable, bool, clickable)
        call1(CCMenuItemToggler, sizeMult, setSizeMult, float, mult)
        callSN(CCMenuItemToggler, updateSprite)
        callBase(CCMenuItemToggler, toggle, (bool on, bool callback = true)) {
            if (callback) m_obj->toggleWithCallback(on);
            else m_obj->toggle(on);
            return *this;
        }
        withOther(CCMenuItemToggler, withOnBtn, CCMenuItemSpriteExtra, btn, m_obj->m_onButton)
        withOther(CCMenuItemToggler, withOffBtn, CCMenuItemSpriteExtra, btn, m_obj->m_offButton)


        // Button
        static createP(geode::Button, createNode, createWithNode, (cocos2d::CCNode* topNode, geode::Button::ButtonCallback callback = nullptr), (topNode, std::move(callback)))
        static createP(geode::Button, createFileName, createWithSprite, (geode::ZStringView fileName, geode::Button::ButtonCallback callback = nullptr), (fileName, std::move(callback)))
        static createP(geode::Button, createFrameName, createWithSpriteFrameName, (geode::ZStringView frameName, geode::Button::ButtonCallback callback = nullptr), (frameName, std::move(callback)))
        static createP(geode::Button, createLabel, createWithLabel, (geode::ZStringView text, geode::Button::ButtonCallback callback = nullptr), (text, std::move(callback)))
        call1(geode::Button, displayNode, setDisplayNode, cocos2d::CCNode*, node)
        call1(geode::Button, animType, setAnimationType, geode::Button::AnimationType, type)
        call1(geode::Button, clickAnim, setClickAnimation, cocos2d::CCActionInterval*, action)
        call1(geode::Button, releaseAnim, setReleaseAnimation, cocos2d::CCActionInterval*, action)
        call1(geode::Button, setOnActivate, setActivateCallback, geode::Button::ButtonCallback, callback)
        call1(geode::Button, setOnSelect, setSelectCallback, geode::Button::ButtonCallback, callback)
        call1(geode::Button, setOnUnselect, setUnselectCallback, geode::Button::ButtonCallback, callback)
        call1(geode::Button, touchPrio, setTouchPriority, int, prio)
        call1(geode::Button, touchMult, setTouchMultiplier, float, mult)
        call1(geode::Button, scaleMult, setScaleMultiplier, float, mult)
        call1(geode::Button, moveOffset, setMoveOffset, cocos2d::CCPoint const&, offset)
        call2Comb(geode::Button, moveOffset, setMoveOffset, float, x, float, y, cocos2d::CCPoint)
        call1(geode::Button, selectDuration, setSelectedDuration, float, dur)
        call1(geode::Button, unselectDuration, setUnselectedDuration, float, dur)
        call1(geode::Button, enable, setEnabled, bool, enabled)
        withOther(geode::Button, withDisplayNode, cocos2d::CCNode, node, m_obj->getDisplayNode())

        // Label
        static createP(geode::Label, createRich, createRich, (std::string text, geode::BitmapFont* font), (std::move(text), font))
        static createP(geode::Label, createRich, createRich, (std::string text, geode::ZStringView font), (std::move(text), font))
        call1(geode::Label, textDirty, setTextDirty, bool, dirty)
        call1(geode::Label, layoutDirty, setLayoutDirty, bool, dirty)
        call1(geode::Label, quadsDirty, setQuadsDirty, bool, dirty)
        call1(geode::Label, addFont, registerFont, geode::BitmapFont*, font)
        call1(geode::Label, addFont, registerFont, geode::ZStringView*, font)
        callPSN(geode::Label, removeFont, (size_t index = 0), (index))
        call1SN(geode::Label, removeFont, geode::ZStringView, font)
        callPSN(geode::Label, setFont, (geode::BitmapFont* font, size_t index = 0), (font, index))
        callPSN(geode::Label, setFont, (geode::ZStringView font, size_t index = 0), (font, index))
        call1(geode::Label, text, setText, std::string, text)
        call1(geode::Label, richText, setRichText, std::string, text)
        call1(geode::Label, align, setAlignment, geode::Label::Alignment, alignment)
        call1(geode::Label, maxWidth, setMaxWidth, float, max)
        call1(geode::Label, breakWords, setBreakWords, bool, breakWords)
        callP(geode::Label, limitWidth, setLimitLabelWidth, (float width, float maxScale = 1.f, float minScale = 0.f), (width, maxScale, minScale))
        callP(geode::Label, limitHeight, setLimitLabelHeight, (float height, float maxScale = 1.f, float minScale = 0.f), (height, maxScale, minScale))
        callP(geode::Label, limitSize, setLimitLabelSize, (cocos2d::CCSize size, float maxScale = 1.f, float minScale = 0.f), (std::move(size), maxScale, minScale))
        call(geode::Label, removeSizeLimit, removeLabelSizeLimit)
        callP(geode::Label, fitBox, setFitBox, (cocos2d::CCSize size, float maxScale = 1.f), (size, maxScale))
        call1(geode::Label, extraKern, setExtraKerning, float, kerning)
        call1(geode::Label, lineSpace, setLineSpacing, float, spacing)
        call2(geode::Label, charColor, setCharColor, uint32_t, index, cocos2d::ccColor4B, color)
        call1(geode::Label, emojiReg, setEmojiRegistry, geode::EmojiRegistry const&, reg)
        call1(geode::Label, colorEmojis, setUseColoredEmojis, bool, color)
        call1(geode::Label, colorNodes, setUseColoredNodes, bool, color)

        // NineSlice
        static createP(geode::NineSlice, createFrame, createWithSpriteFrame, (cocos2d::CCSpriteFrame* frame, geode::NineSlice::Insets const& insets = {}), (frame, insets))
        static createP(geode::NineSlice, createFrameName, createWithSpriteFrameName, (geode::ZStringView frameName, geode::NineSlice::Insets const& insets = {}), (frameName, insets))
        call1(geode::NineSlice, scaleMult, setScaleMultiplier, float, mult)
        call1(geode::NineSlice, repeatCenter, setRepeatCenter, bool, repeat)
        call1(geode::NineSlice, insets, setInsets, geode::NineSlice::Insets const&, insets)
        call4Comb(geode::NineSlice, insets, setInsets, float, top, float, right, float, bottom, float, left, geode::NineSlice::Insets)
        call1(geode::NineSlice, insetTop, setInsetTop, float, top)
        call1(geode::NineSlice, insetRight, setInsetRight, float, right)
        call1(geode::NineSlice, insetBottom, setInsetBottom, float, bottom)
        call1(geode::NineSlice, insetLeft, setInsetLeft, float, left)

        // TODO: v6 text input stuff
        // TextInput
        call1(geode::TextInput, placeholder, setPlaceholder, std::string, text)
        call1(geode::TextInput, label, setLabel, geode::ZStringView, text)
        call1(geode::TextInput, filter, setFilter, std::string, filter)
        call1(geode::TextInput, filter, setCommonFilter, geode::CommonFilter, filter)
        call1(geode::TextInput, maxChars, setMaxCharCount, size_t, max)
        call1(geode::TextInput, passwordMode, setPasswordMode, bool, enabled)
        call1(geode::TextInput, width, setWidth, float, width)
        callP(geode::TextInput, delegate, setDelegate, (TextInputDelegate* delegate, std::optional<int> tag = std::nullopt), (delegate, std::move(tag)))
        call1(geode::TextInput, callback, setCallback, geode::Function<void(std::string const&)>, onInput)
        call1(geode::TextInput, callbackEnabled, setCallbackEnabled, bool, enabled)
        call1(geode::TextInput, enabled, setEnabled, bool, enabled)
        call1(geode::TextInput, align, setTextAlign, geode::TextInputAlign, alignment)
        callSN(geode::TextInput, hideBG)
        callP(geode::TextInput, text, setString, (std::string text, bool triggerCallback), (std::move(text), triggerCallback))
        callSN(geode::TextInput, focus)
        callSN(geode::TextInput, defocus)

        // SliderNode
        static createP(geode::SliderNode, createCustom, createCustom, (cocos2d::CCSprite* thumb, cocos2d::CCSprite* thumbSelected, geode::NineSlice* groove, geode::ZStringView bar, geode::SliderNode::SliderCallback callback, cocos2d::CCSize const& barOffset = {2.f, 2.f}), (thumb, thumbSelected, groove, bar, std::move(callback), barOffset))
        call1(geode::SliderNode, slideCallback, setSlideCallback, geode::SliderNode::SliderCallback, callback)
        call1(geode::SliderNode, clickCallback, setClickCallback, geode::SliderNode::SliderCallback, callback)
        call1(geode::SliderNode, releaseCallback, setReleaseCallback, geode::SliderNode::SliderCallback, callback)
        call1(geode::SliderNode, min, setMin, float, min)
        call1(geode::SliderNode, max, setMax, float, max)
        call1(geode::SliderNode, enabled, setEnabled, bool, enabled)
        call1(geode::SliderNode, value, setValue, float, value)
        call1(geode::SliderNode, percent, setPercent, float, percent)
        call1(geode::SliderNode, snapStep, setSnapStep, float, step)
        call2(geode::SliderNode, linkInput, linkTextInput, geode::TextInput*, input, unsigned int, precision)
        call(geode::SliderNode, unlinkInput, unlinkTextInput)
        call1(geode::SliderNode, inputPrecision, setTextInputPrecision, unsigned int, precision)
        call2SN(geode::SliderNode, linkLabel, geode::Label*, label, unsigned int, precision)
        call1(geode::SliderNode, labelPrecision, setLabelPrecision, unsigned int, precision)
        call1(geode::SliderNode, readOnly, setReadOnly, bool, readOnly)
        call1(geode::SliderNode, bypass, setSliderBypass, bool, enabled)
        call1(geode::SliderNode, touchPrio, setTouchPriority, int, prio)

        // ScrollLayer
        callPSN(geode::ScrollLayer, enableScrollWheel, (bool enable = true), (enable))
        callSN(geode::ScrollLayer, scrollToTop)
        call1(geode::ScrollLayer, scrollFromTop, scrollToFromTop, float, distance)
        call1(geode::ScrollLayer, cancelTouchLimit, setCancelTouchLimit, float, limit)
        call1(geode::ScrollLayer, stealTouches, setStealingTouches, bool, stealing)
        callBase(geode::ScrollLayer, defaultLayout, (float gap = 2.5f)) {
            m_obj->m_mainLayer->setLayout(geode::ScrollLayer::createDefaultListLayout(gap));
            return *this;
        }
        withOther(geode::ScrollLayer, withContentLayer, geode::GenericContentLayer, contentLayer, static_cast<geode::GenericContentLayer*>(m_obj->m_contentLayer))
        callBase(geode::ScrollLayer, createScrollbar, (const cocos2d::CCPoint& pos, geode::Function<void(Make<geode::Scrollbar> bar)> callback = nullptr)) {
            auto bar = Make<geode::Scrollbar>(geode::Scrollbar::create(m_obj))
                .pos(pos);
            if (callback) callback(bar);
            return *this;
        }

        // Scrollbar
        call1(geode::Scrollbar, target, setTarget, CCScrollLayerExt*, list)
        call1(geode::Scrollbar, track, setTrack, geode::NineSlice*, track)
        call1(geode::Scrollbar, thumb, setThumb, geode::NineSlice*, thumb)

        // LazySprite
        callP(geode::LazySprite, fromUrl, loadFromUrl, (std::string url, geode::LazySprite::Format format = geode::LazySprite::Format::kFmtUnKnown, bool ignoreCache = false), (std::move(url), format, ignoreCache))
        callP(geode::LazySprite, fromFile, loadFromFile, (asp::fs::Path path, geode::LazySprite::Format format = geode::LazySprite::Format::kFmtUnKnown, bool ignoreCache = false), (std::move(path), format, ignoreCache))
        callP(geode::LazySprite, fromData, loadFromData, (std::span<uint8_t const> data, geode::LazySprite::Format format = geode::LazySprite::Format::kFmtUnKnown), (std::move(data), format))
        callP(geode::LazySprite, fromData, loadFromData, (uint8_t const* ptr, geode::LazySprite::Format format = geode::LazySprite::Format::kFmtUnKnown), (ptr, format))
        call1(geode::LazySprite, setOnLoad, setLoadCallback, geode::LazySprite::Callback, callback)
        call1(geode::LazySprite, autoResize, setAutoResize, bool, resize)

        // BasedButtonSprite
        template <typename ...Args>
        // BasedButtonSprite does not have createWithSprite but every subclass does,
        // so thats why it is not same as.
        static createPWithReqs(geode::BasedButtonSprite, createFileName, createWithSprite, (char const* sprName, float sprScale = 1.f, Args... args), (sprName, sprScale, args...), (!std::is_same_v<T, geode::BasedButtonSprite>()))
        call1(geode::BasedButtonSprite, topOffset, setTopOffset, cocos2d::CCPoint const&, offset);
        call1(geode::BasedButtonSprite, topScale, setTopRelativeScale, float, scale);
        // dont need creates for each class because the templated methods should cover it all

        // TODO: geode::Toggler when its merged

        // Layout and its subclasses
        call1SN(geode::Layout, apply, cocos2d::CCNode*, node)
        // AxisLayout
        call1(geode::AxisLayout, axis, setAxis, geode::Axis, axis)
        call1(geode::AxisLayout, align, setAxisAlignment, geode::AxisAlignment, align)
        call1(geode::AxisLayout, crossAlign, setCrossAxisAlignment, geode::AxisAlignment, align)
        call1(geode::AxisLayout, gap, setGap, float, gap)
        call1(geode::AxisLayout, reverse, setAxisReverse, bool, reverse)
        call1(geode::AxisLayout, crossReverse, setCrossAxisReverse, bool, reverse)
        call1(geode::AxisLayout, autoScale, setAutoScale, bool, enabled)
        call1(geode::AxisLayout, growCross, setGrowCrossAxis, bool, enabled)
        call1(geode::AxisLayout, crossOverflow, setCrossAxisOverflow, bool, enabled)
        call1(geode::AxisLayout, autoGrow, setAutoGrowAxis, std::optional<float>, allowAndMinLength)
        call2(geode::AxisLayout, defaultScaleLimits, setDefaultScaleLimits, float, min, float, max)
        call1(geode::AxisLayout, ignoreInvisible, ignoreInvisibleChildren, bool, ignore)
        call1(geode::AxisLayout, padding, setPadding, geode::Padding const&, padding)
        call4Comb(geode::AxisLayout, padding, setPadding, float, left, float, top, float, right, float, bottom, geode::Padding)
        // CopySizeLayout
        call1SN(geode::CopySizeLayout, add, cocos2d::CCNode*, target)
        call1SN(geode::CopySizeLayout, remove, cocos2d::CCNode*, target)
        // SimpleAxisLayout
        call1(geode::SimpleAxisLayout, axis, setAxis, geode::Axis, axis)
        call1(geode::SimpleAxisLayout, scaling, setMainAxisScaling, geode::AxisScaling, scaling)
        call1(geode::SimpleAxisLayout, crossScaling, setCrossAxisScaling, geode::AxisScaling, scaling)
        call1(geode::SimpleAxisLayout, align, setMainAxisAlignment, geode::MainAxisAlignment, align)
        call1(geode::SimpleAxisLayout, crossAlign, setCrossAxisAlignment, geode::CrossAxisAlignment, align)
        call1(geode::SimpleAxisLayout, dir, setMainAxisDirection, geode::AxisDirection, dir)
        call1(geode::SimpleAxisLayout, crossDir, setCrossAxisDirection, geode::AxisDirection, dir)
        call1(geode::SimpleAxisLayout, gap, setGap, float, gap)
        call1(geode::SimpleAxisLayout, minRelScale, setMinRelativeScale, std::optional<float>, scale)
        call1(geode::SimpleAxisLayout, maxRelScale, setMaxRelativeScale, std::optional<float>, scale)
        call1(geode::SimpleAxisLayout, ignoreInvisible, ignoreInvisibleChildren, bool, ignore)
        call1(geode::SimpleAxisLayout, padding, setPadding, geode::Padding const&, padding)
        call4Comb(geode::SimpleAxisLayout, padding, setPadding, float, left, float, top, float, right, float, bottom, geode::Padding)

        // LayoutOptions subclasses (base one does not have anything in it)
        // AxisLayoutOptions
        call2(geode::AxisLayoutOptions, scaleLimits, setScaleLimits, std::optional<float>, min, std::optional<float>, max)
        call1(geode::AxisLayoutOptions, relativeScale, setRelativeScale, float, scale)
        call1(geode::AxisLayoutOptions, autoScale, setAutoScale, std::optional<bool>, enabled)
        call1(geode::AxisLayoutOptions, length, setAutoScale, std::optional<float>, length)
        call1(geode::AxisLayoutOptions, prevGap, setPrevGap, std::optional<float>, gap)
        call1(geode::AxisLayoutOptions, nextGap, setNextGap, std::optional<float>, gap)
        call1(geode::AxisLayoutOptions, breakLine, setBreakLine, bool, enable)
        call1(geode::AxisLayoutOptions, sameLine, setSameLine, bool, enable)
        call1(geode::AxisLayoutOptions, scalePrio, setScalePriority, int, prio)
        call1(geode::AxisLayoutOptions, crossAlign, setCrossAxisAlignment, std::optional<geode::AxisAlignment>, alignment)
        // AnchorLayoutOptions
        call1(geode::AnchorLayoutOptions, anchor, setAnchor, geode::Anchor, anchor)
        call1(geode::AnchorLayoutOptions, offset, setAnchor, cocos2d::CCPoint const&, offset)
        // SimpleAxisLayoutOptions
        call1(geode::SimpleAxisLayoutOptions, minRelScale, setMinRelativeScale, std::optional<float>, scale)
        call1(geode::SimpleAxisLayoutOptions, maxRelScale, setMaxRelativeScale, std::optional<float>, scale)
        call1(geode::SimpleAxisLayoutOptions, scalePrio, setScalingPriority, geode::ScalingPriority, priority)
        // AxisGap (this really doesnt need its own area...)
        call1(geode::AxisGap, gap, setGap, float, gap)

        // generic util stuff
        Make with(geode::Function<void(T* obj)> callback) {
            callback(m_obj);
            return *this;
        }

        template <typename ...Args>
        static Make create(Args... args) {
            return Make(T::create(args...));
        }

        T* get() {
            return m_obj;
        }

        geode::Ref<T> ref() {
            return Ref(m_obj);
        }


        explicit operator bool() const noexcept {
            return m_obj != nullptr;
        }

        T* operator->() const noexcept {
            return m_obj;
        }

        T* operator*() const noexcept {
            return m_obj;
        }

        bool operator==(Make const& other) const noexcept {
            return m_obj == other.m_obj;
        }

        bool operator==(cocos2d::CCObject const* other) const noexcept {
            return m_obj == other;
        }

        bool operator==(std::nullptr_t) const noexcept {
            return m_obj == nullptr;
        }

        operator T*() const { return m_obj; }
    };
}

// i probably need to figure out a solution with less macros...
#undef callBase
#undef callBaseWithReqs
#undef call
#undef callSN
#undef call1
#undef call1SN
#undef call2
#undef call2SN
#undef call2Comb
#undef call3
#undef call4Comb
#undef callP
#undef callPWithReqs
#undef callPSN
#undef withOther
#undef createP
#undef createPWithReqs
#undef setMember