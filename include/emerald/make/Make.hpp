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

        call(cocos2d::CCObject, retain, retain)
        call(cocos2d::CCObject, release, release)
        call(cocos2d::CCObject, autorel, autorelease)
        callP(cocos2d::CCObject, tag, setTag, (int tag), (tag))
        callBase(cocos2d::CCObject, store, (T*& var)) {
            var = m_obj;
            return *this;
        }

        // CCNode
        callP(cocos2d::CCNode, zOrder, setZOrder, (int zOrder), (zOrder))
        callP(cocos2d::CCNode, scaleX, setScaleX, (float x), (x))
        callP(cocos2d::CCNode, scaleY, setScaleY, (float y), (y))
        callP(cocos2d::CCNode, scale, setScale, (float scale), (scale))
        callP(cocos2d::CCNode, scale, setScale, (float x, float y), (x, y))
        callP(cocos2d::CCNode, posX, setPositionX, (float x), (x))
        callP(cocos2d::CCNode, posY, setPositionY, (float y), (y))
        callP(cocos2d::CCNode, pos, setPosition, (const cocos2d::CCPoint& pos), (pos))
        callP(cocos2d::CCNode, pos, setPosition, (float x, float y), (cocos2d::CCPoint{x, y}))
        callP(cocos2d::CCNode, skewX, setSkewX, (float x), (x))
        callP(cocos2d::CCNode, skewY, setSkewY, (float y), (y))
        callBase(cocos2d::CCNode, skew, (float x, float y)){
            if (this->m_obj) {
                this->m_obj->setSkewY(x);
                this->m_obj->setSkewY(y);
            }
            return *this;
        }
        callP(cocos2d::CCNode, anchor, setAnchorPoint, (const cocos2d::CCPoint& anchor), (anchor))
        callP(cocos2d::CCNode, anchor, setAnchorPoint, (float x, float y), (cocos2d::CCPoint{x, y}))
        callP(cocos2d::CCNode, width, setContentWidth, (float width), (width))
        callP(cocos2d::CCNode, height, setContentHeight, (float height), (height))
        callP(cocos2d::CCNode, size, setContentSize, (const cocos2d::CCSize& size), (size))
        callP(cocos2d::CCNode, size, setContentSize, (float x, float y), (cocos2d::CCSize{x, y}))
        callP(cocos2d::CCNode, visible, setVisible, (bool vis), (vis))
        callP(cocos2d::CCNode, rotationX, setRotationX, (float x), (x))
        callP(cocos2d::CCNode, rotationY, setRotationY, (float y), (y))
        callP(cocos2d::CCNode, rotation, setRotation, (float rot), (rot))
        callP(cocos2d::CCNode, orderArrive, setOrderOfArrival, (unsigned int order), (order))
        callP(cocos2d::CCNode, ignoreAnchor, ignoreAnchorPointForPosition, (bool ignore), (ignore))
        callP(cocos2d::CCNode, child, addChild, (cocos2d::CCNode* child), (child))
        callP(cocos2d::CCNode, child, addChild, (cocos2d::CCNode* child, int zOrder), (child, zOrder) )
        callP(cocos2d::CCNode, child, addChild, (cocos2d::CCNode* child, int zOrder, int tag), (child, zOrder, tag))
        callP(cocos2d::CCNode, childAtPos, addChildAtPosition, (cocos2d::CCNode* child, geode::Anchor anchor, cocos2d::CCPoint const& offset = {}, bool useAnchorLayout = true), (child, anchor, offset, useAnchorLayout))
        callP(cocos2d::CCNode, childAtPos, addChildAtPosition, (cocos2d::CCNode* child, geode::Anchor anchor, cocos2d::CCPoint const& offset, cocos2d::CCPoint const& nodeAnchor, bool useAnchorLayout = true), (child, anchor, offset, nodeAnchor, useAnchorLayout))
        callP(cocos2d::CCNode, children, addChildren, (std::span<cocos2d::CCNode* const> children), (std::move(children)))
        template <typename ...Args>
        callBase(cocos2d::CCNode, children, (Args... children)) {
            if (this->m_obj) this->m_obj->addChildren(children...);
            return *this;
        }
        callP(cocos2d::CCNode, userObj, setUserObject, (cocos2d::CCObject* obj), (obj))
        callP(cocos2d::CCNode, userObj, setUserObject, (std::string id, cocos2d::CCObject* obj), (std::move(id), obj))
        callP(cocos2d::CCNode, flag, setUserFlag, (std::string id, bool state = false), (id, state))
        callP(cocos2d::CCNode, id, setID, (std::string id), (std::move(id)))
        callP(cocos2d::CCNode, layout, setLayout, (geode::Layout* layout), (layout))
        callP(cocos2d::CCNode, layoutOpts, setLayoutOptions, (geode::LayoutOptions* opts, bool update = true), (opts, update))
        call(cocos2d::CCNode, updateLayout, updateLayout)
        template <class Event, class Callback>
        callBase(cocos2d::CCNode, listen,  (Event const& event, Callback&& callback, int prio = 0)) {
            if (this->m_obj) {
                m_obj->addEventListener(event, [this, cb = std::forward<Callback>(callback)]<typename... Args>(Args&&... args) {
                    return cb(m_obj, std::forward<Args>(args)...);
                }, prio);
            }
            return *this;
        }
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
        callP(cocos2d::CCNode, shader, setShaderProgram, (cocos2d::CCGLProgram* shader), (shader))
        callP(cocos2d::CCNode, action, runAction, (cocos2d::CCAction* action), (action))

        callBase(cocos2d::CCNode, parent, (cocos2d::CCNode* parent)) {
            if (m_obj && parent) parent->addChild(m_obj);
            return *this;
        }
        callBase(cocos2d::CCNode, parent, (cocos2d::CCNode* parent, int zOrder)) {
            if (m_obj && parent) parent->addChild(m_obj, zOrder);
            return *this;
        }
        callBase(cocos2d::CCNode, parent, (cocos2d::CCNode* parent, int zOrder, int tag)) {
            if (m_obj && parent) parent->addChild(m_obj, zOrder, tag);
            return *this;
        }
        callBase(cocos2d::CCNode, parentAtPos, (cocos2d::CCNode* parent, geode::Anchor anchor, cocos2d::CCPoint const& offset = {}, bool useAnchorLayout = true)) {
            if (m_obj && parent) parent->addChildAtPosition(m_obj, anchor, offset, useAnchorLayout);
            return *this;
        }
        callBase(cocos2d::CCNode, parentAtPos, (cocos2d::CCNode* parent, geode::Anchor anchor, cocos2d::CCPoint const& offset, cocos2d::CCPoint const& nodeAnchor, bool useAnchorLayout = true)) {
            if (m_obj && parent) parent->addChildAtPosition(m_obj, anchor, offset, nodeAnchor, useAnchorLayout);
            return *this;
        }

        template <typename P>
        callBase(cocos2d::CCNode, intoParent, (P* parent)) {
            if (m_obj && parent) parent->addChild(m_obj);
            return Make<P>(parent);
        }
        template <typename P>
        callBase(cocos2d::CCNode, intoParent, (P* parent, int zOrder)) {
            if (m_obj && parent) parent->addChild(m_obj, zOrder);
            return Make<P>(parent);
        }
        template <typename P>
        callBase(cocos2d::CCNode, intoParent, (P* parent, int zOrder, int tag)) {
            if (m_obj && parent) parent->addChild(m_obj, zOrder, tag);
            return Make<P>(parent);
        }
        template <typename P>
        callBase(cocos2d::CCNode, intoParentAtPos, (P* parent, geode::Anchor anchor, cocos2d::CCPoint const& offset = {}, bool useAnchorLayout = true)) {
            if (m_obj && parent) parent->addChildAtPosition(m_obj, anchor, offset, useAnchorLayout);
            return Make<P>(parent);
        }
        template <typename P>
        callBase(cocos2d::CCNode, intoParentAtPos, (P* parent, geode::Anchor anchor, cocos2d::CCPoint const& offset, cocos2d::CCPoint const& nodeAnchor, bool useAnchorLayout = true)) {
            if (m_obj && parent) parent->addChildAtPosition(m_obj, anchor, offset, nodeAnchor, useAnchorLayout);
            return Make<P>(parent);
        }

        callBase(cocos2d::CCNode, posAnchored, (geode::Anchor anchor, const cocos2d::CCPoint& pos)) {
            if (m_obj) m_obj->setLayoutOptions(geode::AnchorLayoutOptions::create()
                ->setAnchor(anchor)
                ->setOffset(pos));
            return *this;
        }

        // Misc protocols
        callP(cocos2d::CCRGBAProtocol, opacity, setOpacity, (GLubyte opacity), (opacity))
        callP(cocos2d::CCRGBAProtocol, color, setColor, (const cocos2d::ccColor3B& color), (color))
        callP(cocos2d::CCRGBAProtocol, cascadeOpacity, setCascadeOpacityEnabled, (bool enabled), (enabled))
        callP(cocos2d::CCRGBAProtocol, cascadeColor, setCascadeColorEnabled, (bool enabled), (enabled))
        callP(cocos2d::CCRGBAProtocol, opacityModRGB, setOpacityModifyRGB, (bool enabled), (enabled))
        callP(cocos2d::CCBlendProtocol, blend, setBlendFunc, (cocos2d::ccBlendFunc func), (func))
        callP(cocos2d::CCTextureProtocol, texture, setTexture, (cocos2d::CCTexture2D* texture), (texture))
        callP(cocos2d::CCLabelProtocol, text, setString, (const char* text), (text))
        // geode label has its own text method taking an std::string, so this one shouldnt apply to that
        callPWithReqs(cocos2d::CCLabelProtocol, text, setString, (const std::string& text), (text.c_str()), (!std::derived_from<T, geode::Label>))

        // CCLayer
        call(cocos2d::CCLayer, registerTouch, registerWithTouchDispatcher)
        callP(cocos2d::CCLayer, touchEnabled, setTouchEnabled, (bool enabled), (enabled))
        callP(cocos2d::CCLayer, touchPrio, setTouchPriority, (int prio), (prio))
        callP(cocos2d::CCLayer, keypadEnabled, setKeypadEnabled, (bool enabled), (enabled))
        callP(cocos2d::CCLayer, keyboardEnabled, setKeyboardEnabled, (bool enabled), (enabled))
        callP(cocos2d::CCLayer, mouseEnabled, setMouseEnabled, (bool enabled), (enabled))

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
        callP(cocos2d::CCSprite, batchNode, setBatchNode, (cocos2d::CCSpriteBatchNode* batch), (batch))
        callP(cocos2d::CCSprite, texRect, setTextureRect, (const cocos2d::CCRect& rect), (rect))
        callP(cocos2d::CCSprite, texRect, setTextureRect, (const cocos2d::CCRect& rect, bool rotated, const cocos2d::CCSize& untrimmedSize), (rect, rotated, untrimmedSize))
        callP(cocos2d::CCSprite, displayFrame, setDisplayFrame, (cocos2d::CCSpriteFrame* pNewFrame), (pNewFrame))
        callP(cocos2d::CCSprite, displayFrameAnimName, setDisplayFrameWithAnimationName, (const char* animationName, int frameIndex), (animationName, frameIndex))
        callP(cocos2d::CCSprite, setDirty, setDirty, (bool dirty), (dirty))
        callP(cocos2d::CCSprite, flipX, setFlipX, (bool flip), (flip))
        callP(cocos2d::CCSprite, flipY, setFlipY, (bool flip), (flip))

        // CCMenu and its buttons
        call(cocos2d::CCMenu, giveTouchPrio, giveMenuTouchPriority)
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
        callP(cocos2d::CCMenu, target, setTarget, (cocos2d::CCObject* listener, cocos2d::SEL_MenuHandler selector), (listener, selector))
        callBase(cocos2d::CCMenu, setCallback, (geode::Function<void(T* obj)> callback)) {
            if (m_obj) geode::cocos::CCMenuItemExt::assignCallback(m_obj, std::move(callback));
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
        callP(cocos2d::CCMenuItemSprite, displayNode, setNormalImage, (cocos2d::CCNode* node), (node))
        callP(cocos2d::CCMenuItemSprite, selectedNode, setSelectedImage, (cocos2d::CCNode* node), (node))
        callP(cocos2d::CCMenuItemSprite, disabledNode, setDisabledImage, (cocos2d::CCNode* node), (node))
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


        // Button
        static createP(geode::Button, createNode, createWithNode, (cocos2d::CCNode* topNode, geode::Button::ButtonCallback callback = nullptr), (topNode, std::move(callback)))
        static createP(geode::Button, createFileName, createWithSprite, (geode::ZStringView fileName, geode::Button::ButtonCallback callback = nullptr), (fileName, std::move(callback)))
        static createP(geode::Button, createFrameName, createWithSpriteFrameName, (geode::ZStringView frameName, geode::Button::ButtonCallback callback = nullptr), (frameName, std::move(callback)))
        static createP(geode::Button, createLabel, createWithLabel, (geode::ZStringView text, geode::Button::ButtonCallback callback = nullptr), (text, std::move(callback)))
        callP(geode::Button, displayNode, setDisplayNode, (cocos2d::CCNode* node), (node))
        callP(geode::Button, animType, setAnimationType, (geode::Button::AnimationType type), (type))
        callP(geode::Button, clickAnim, setClickAnimation, (cocos2d::CCActionInterval* action), (action))
        callP(geode::Button, releaseAnim, setReleaseAnimation, (cocos2d::CCActionInterval* action), (action))
        callP(geode::Button, setOnActivate, setActivateCallback, (geode::Button::ButtonCallback callback), (callback))
        callP(geode::Button, setOnSelect, setSelectCallback, (geode::Button::ButtonCallback callback), (callback))
        callP(geode::Button, setOnUnselect, setUnselectCallback, (geode::Button::ButtonCallback callback), (callback))
        callP(geode::Button, touchPrio, setTouchPriority, (int prio), (prio))
        callP(geode::Button, touchMult, setTouchMultiplier, (float mult), (mult))
        callP(geode::Button, scaleMult, setScaleMultiplier, (float mult), (mult))
        callP(geode::Button, moveOffset, setMoveOffset, (cocos2d::CCPoint const& offset), (offset))
        callP(geode::Button, moveOffset, setMoveOffset, (float x, float y), (cocos2d::CCPoint{x, y}))
        callP(geode::Button, selectDuration, setSelectedDuration, (float dur), (dur))
        callP(geode::Button, unselectDuration, setUnselectedDuration, (float dur), (dur))
        callP(geode::Button, enable, setEnabled, (bool enabled), (enabled))
        withOther(geode::Button, withDisplayNode, cocos2d::CCNode, node, m_obj->getDisplayNode())

        // Label
        static createP(geode::Label, createRich, createRich, (std::string text, geode::BitmapFont* font), (std::move(text), font))
        static createP(geode::Label, createRich, createRich, (std::string text, geode::ZStringView font), (std::move(text), font))
        callP(geode::Label, textDirty, setTextDirty, (bool dirty), (dirty))
        callP(geode::Label, layoutDirty, setLayoutDirty, (bool dirty), (dirty))
        callP(geode::Label, quadsDirty, setQuadsDirty, (bool dirty), (dirty))
        callP(geode::Label, addFont, registerFont, (geode::BitmapFont* font), (font))
        callP(geode::Label, addFont, registerFont, (geode::ZStringView* font), (font))
        callP(geode::Label, removeFont, removeFont, (size_t index = 0), (index))
        callP(geode::Label, removeFont, removeFont, (geode::ZStringView font), (font))
        callP(geode::Label, setFont, setFont, (geode::BitmapFont* font, size_t index = 0), (font, index))
        callP(geode::Label, setFont, setFont, (geode::ZStringView font, size_t index = 0), (font, index))
        callP(geode::Label, text, setText, (std::string text), (text))
        callP(geode::Label, richText, setRichText, (std::string text), (text))
        callP(geode::Label, align, setAlignment, (geode::Label::Alignment alignment), (alignment))
        callP(geode::Label, maxWidth, setMaxWidth, (float max), (max))
        callP(geode::Label, breakWords, setBreakWords, (bool breakWords), (breakWords))
        callP(geode::Label, limitWidth, setLimitLabelWidth, (float width, float maxScale = 1.f, float minScale = 0.f), (width, maxScale, minScale))
        callP(geode::Label, limitHeight, setLimitLabelHeight, (float height, float maxScale = 1.f, float minScale = 0.f), (height, maxScale, minScale))
        callP(geode::Label, limitSize, setLimitLabelSize, (cocos2d::CCSize size, float maxScale = 1.f, float minScale = 0.f), (std::move(size), maxScale, minScale))
        call(geode::Label, removeSizeLimit, removeLabelSizeLimit)
        callP(geode::Label, fitBox, setFitBox, (cocos2d::CCSize size, float maxScale = 1.f), (size, maxScale))
        callP(geode::Label, extraKern, setExtraKerning, (float kerning), (kerning))
        callP(geode::Label, lineSpace, setLineSpacing, (float spacing), (spacing))
        callP(geode::Label, charColor, setCharColor, (uint32_t index, cocos2d::ccColor4B color), (index, color))
        callP(geode::Label, emojiReg, setEmojiRegistry, (geode::EmojiRegistry const& reg), (reg))
        callP(geode::Label, colorEmojis, setUseColoredEmojis, (bool color), (color))
        callP(geode::Label, colorNodes, setUseColoredNodes, (bool color), (color))

        // NineSlice
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

        // TODO: v6 text input stuff
        // TextInput
        callP(geode::TextInput, placeholder, setPlaceholder, (std::string text), (text))
        callP(geode::TextInput, label, setLabel, (geode::ZStringView text), (text))
        callP(geode::TextInput, filter, setFilter, (std::string filter), (filter))
        callP(geode::TextInput, filter, setCommonFilter, (geode::CommonFilter filter), (filter))
        callP(geode::TextInput, maxChars, setMaxCharCount, (size_t max), (max))
        callP(geode::TextInput, passwordMode, setPasswordMode, (bool enabled), (enabled))
        callP(geode::TextInput, width, setWidth, (float width), (width))
        callP(geode::TextInput, delegate, setDelegate, (TextInputDelegate* delegate, std::optional<int> tag = std::nullopt), (delegate, std::move(tag)))
        callP(geode::TextInput, callback, setCallback, (geode::Function<void(std::string const&)> onInput), (onInput))
        callP(geode::TextInput, callbackEnabled, setCallbackEnabled, (bool enabled), (enabled))
        callP(geode::TextInput, enabled, setEnabled, (bool enabled), (enabled))
        callP(geode::TextInput, align, setTextAlign, (geode::TextInputAlign alignment), (alignment))
        call(geode::TextInput, hideBG, hideBG)
        callP(geode::TextInput, text, setString, (std::string text, bool triggerCallback), (std::move(text), triggerCallback))
        call(geode::TextInput, focus, focus)
        call(geode::TextInput, defocus, defocus)

        // SliderNode
        static createP(geode::SliderNode, createCustom, createCustom, (cocos2d::CCSprite* thumb, cocos2d::CCSprite* thumbSelected, geode::NineSlice* groove, geode::ZStringView bar, geode::SliderNode::SliderCallback callback, cocos2d::CCSize const& barOffset = {2.f, 2.f}), (thumb, thumbSelected, groove, bar, std::move(callback), barOffset))
        callP(geode::SliderNode, slideCallback, setSlideCallback, (geode::SliderNode::SliderCallback callback), (callback))
        callP(geode::SliderNode, clickCallback, setClickCallback, (geode::SliderNode::SliderCallback callback), (callback))
        callP(geode::SliderNode, releaseCallback, setReleaseCallback, (geode::SliderNode::SliderCallback callback), (callback))
        callP(geode::SliderNode, min, setMin, (float min), (min))
        callP(geode::SliderNode, max, setMax, (float max), (max))
        callP(geode::SliderNode, enabled, setEnabled, (bool enabled), (enabled))
        callP(geode::SliderNode, value, setValue, (float value), (value))
        callP(geode::SliderNode, percent, setPercent, (float percent), (percent))
        callP(geode::SliderNode, snapStep, setSnapStep, (float step), (step))
        callP(geode::SliderNode, linkInput, linkTextInput, (geode::TextInput* input, unsigned int precision), (input, precision))
        call(geode::SliderNode, unlinkInput, unlinkTextInput)
        callP(geode::SliderNode, inputPrecision, setTextInputPrecision, (unsigned int precision), (precision))
        callP(geode::SliderNode, linkLabel, linkLabel, (geode::Label* label, unsigned int precision), (label, precision))
        callP(geode::SliderNode, labelPrecision, setLabelPrecision, (unsigned int precision), (precision))
        callP(geode::SliderNode, readOnly, setReadOnly, (bool readOnly), (readOnly))
        callP(geode::SliderNode, bypass, setSliderBypass, (bool enabled), (enabled))
        callP(geode::SliderNode, touchPrio, setTouchPriority, (int prio), (prio))

        // ScrollLayer
        callP(geode::ScrollLayer, enableScrollWheel, enableScrollWheel, (bool enable = true), (enable))
        call(geode::ScrollLayer, scrollToTop, scrollToTop)
        callP(geode::ScrollLayer, scrollFromTop, scrollToFromTop, (float distance), (distance))
        callP(geode::ScrollLayer, cancelTouchLimit, setCancelTouchLimit, (float limit), (limit))
        callP(geode::ScrollLayer, stealTouches, setStealingTouches, (bool stealing), (stealing))
        callBase(geode::ScrollLayer, defaultLayout, (float gap = 2.5f)) {
            if (m_obj && m_obj->m_mainLayer)
                m_obj->m_mainLayer->setLayout(geode::ScrollLayer::createDefaultListLayout(gap));
            return *this;
        }
        withOther(geode::ScrollLayer, withContentLayer, geode::GenericContentLayer, contentLayer, static_cast<geode::GenericContentLayer*>(m_obj->m_contentLayer))
        callBase(geode::ScrollLayer, createScrollbar, (const cocos2d::CCPoint& pos, geode::Function<void(Make<geode::Scrollbar> bar)> callback = nullptr)) {
            auto bar = Make<geode::Scrollbar>::create(m_obj)
                .pos(pos);
            if (callback) callback(bar);
            return *this;
        }

        // Scrollbar
        callP(geode::Scrollbar, target, setTarget, (CCScrollLayerExt* list), (list))
        callP(geode::Scrollbar, track, setTrack, (geode::NineSlice* track), (track))
        callP(geode::Scrollbar, thumb, setThumb, (geode::NineSlice* thumb), (thumb))

        // LazySprite
        callP(geode::LazySprite, fromUrl, loadFromUrl, (std::string url, geode::LazySprite::Format format = geode::LazySprite::Format::kFmtUnKnown, bool ignoreCache = false), (std::move(url), format, ignoreCache))
        callP(geode::LazySprite, fromFile, loadFromFile, (asp::fs::Path path, geode::LazySprite::Format format = geode::LazySprite::Format::kFmtUnKnown, bool ignoreCache = false), (std::move(path), format, ignoreCache))
        callP(geode::LazySprite, fromData, loadFromData, (std::span<uint8_t const> data, geode::LazySprite::Format format = geode::LazySprite::Format::kFmtUnKnown), (std::move(data), format))
        callP(geode::LazySprite, fromData, loadFromData, (uint8_t const* ptr, geode::LazySprite::Format format = geode::LazySprite::Format::kFmtUnKnown), (ptr, format))
        callP(geode::LazySprite, setOnLoad, setLoadCallback, (geode::LazySprite::Callback callback), (callback))
        callP(geode::LazySprite, autoResize, setAutoResize, (bool resize), (resize))

        // BasedButtonSprite
        template <typename ...Args>
        // BasedButtonSprite does not have createWithSprite but every subclass does,
        // so thats why it is not same as.
        static createPWithReqs(geode::BasedButtonSprite, createFileName, createWithSprite, (char const* sprName, float sprScale = 1.f, Args... args), (sprName, sprScale, args...), (!std::is_same_v<T, geode::BasedButtonSprite>()))
        callP(geode::BasedButtonSprite, topOffset, setTopOffset, (cocos2d::CCPoint const& offset), (offset));
        callP(geode::BasedButtonSprite, topScale, setTopRelativeScale, (float scale), (scale));
        // dont need creates for each class because the templated methods should cover it all

        // TODO: geode::Toggler when its merged

        // Layout and its subclasses
        callP(geode::Layout, apply, apply, (cocos2d::CCNode* node), (node))
        // AxisLayout
        callP(geode::AxisLayout, axis, setAxis, (geode::Axis axis), (axis))
        callP(geode::AxisLayout, align, setAxisAlignment, (geode::AxisAlignment align), (align))
        callP(geode::AxisLayout, crossAlign, setCrossAxisAlignment, (geode::AxisAlignment align), (align))
        callP(geode::AxisLayout, gap, setGap, (float gap), (gap))
        callP(geode::AxisLayout, reverse, setAxisReverse, (bool reverse), (reverse))
        callP(geode::AxisLayout, crossReverse, setCrossAxisReverse, (bool reverse), (reverse))
        callP(geode::AxisLayout, autoScale, setAutoScale, (bool enabled), (enabled))
        callP(geode::AxisLayout, growCross, setGrowCrossAxis, (bool enabled), (enabled))
        callP(geode::AxisLayout, crossOverflow, setCrossAxisOverflow, (bool enabled), (enabled))
        callP(geode::AxisLayout, autoGrow, setAutoGrowAxis, (std::optional<float> allowAndMinLength), (allowAndMinLength))
        callP(geode::AxisLayout, defaultScaleLimits, setDefaultScaleLimits, (float min, float max), (min, max))
        callP(geode::AxisLayout, ignoreInvisible, ignoreInvisibleChildren, (bool ignore), (ignore))
        callP(geode::AxisLayout, padding, setPadding, (geode::Padding const& padding), (padding))
        callP(geode::AxisLayout, padding, setPadding, (float left, float top, float right, float bottom), (geode::Padding{left, top, right, bottom}))
        // CopySizeLayout
        callP(geode::CopySizeLayout, add, add, (cocos2d::CCNode* target), (target))
        callP(geode::CopySizeLayout, remove, remove, (cocos2d::CCNode* target), (target))
        // SimpleAxisLayout
        callP(geode::SimpleAxisLayout, axis, setAxis, (geode::Axis axis), (axis))
        callP(geode::SimpleAxisLayout, scaling, setMainAxisScaling, (geode::AxisScaling scaling), (scaling))
        callP(geode::SimpleAxisLayout, crossScaling, setCrossAxisScaling, (geode::AxisScaling scaling), (scaling))
        callP(geode::SimpleAxisLayout, align, setMainAxisAlignment, (geode::MainAxisAlignment align), (align))
        callP(geode::SimpleAxisLayout, crossAlign, setCrossAxisAlignment, (geode::CrossAxisAlignment align), (align))
        callP(geode::SimpleAxisLayout, dir, setMainAxisDirection, (geode::AxisDirection dir), (dir))
        callP(geode::SimpleAxisLayout, crossDir, setCrossAxisDirection, (geode::AxisDirection dir), (dir))
        callP(geode::SimpleAxisLayout, gap, setGap, (float gap), (gap))
        callP(geode::SimpleAxisLayout, minRelScale, setMinRelativeScale, (std::optional<float> scale), (scale))
        callP(geode::SimpleAxisLayout, maxRelScale, setMaxRelativeScale, (std::optional<float> scale), (scale))
        callP(geode::SimpleAxisLayout, ignoreInvisible, ignoreInvisibleChildren, (bool ignore), (ignore))
        callP(geode::SimpleAxisLayout, padding, setPadding, (geode::Padding const& padding), (padding))
        callP(geode::SimpleAxisLayout, padding, setPadding, (float left, float top, float right, float bottom), (geode::Padding{left, top, right, bottom}))

        // LayoutOptions subclasses (base one does not have anything in it)
        // AxisLayoutOptions
        callP(geode::AxisLayoutOptions, scaleLimits, setScaleLimits, (std::optional<float> min, std::optional<float> max), (min, max))
        callP(geode::AxisLayoutOptions, relativeScale, setRelativeScale, (float scale), (scale))
        callP(geode::AxisLayoutOptions, autoScale, setAutoScale, (std::optional<bool> enabled), (enabled))
        callP(geode::AxisLayoutOptions, length, setAutoScale, (std::optional<float> length), (length))
        callP(geode::AxisLayoutOptions, prevGap, setPrevGap, (std::optional<float> gap), (gap))
        callP(geode::AxisLayoutOptions, nextGap, setNextGap, (std::optional<float> gap), (gap))
        callP(geode::AxisLayoutOptions, breakLine, setBreakLine, (bool enable), (enable))
        callP(geode::AxisLayoutOptions, sameLine, setSameLine, (bool enable), (enable))
        callP(geode::AxisLayoutOptions, scalePrio, setScalePriority, (int prio), (prio))
        callP(geode::AxisLayoutOptions, crossAlign, setCrossAxisAlignment, (std::optional<geode::AxisAlignment> alignment), (alignment))
        // AnchorLayoutOptions
        callP(geode::AnchorLayoutOptions, anchor, setAnchor, (geode::Anchor anchor), (anchor))
        callP(geode::AnchorLayoutOptions, offset, setAnchor, (cocos2d::CCPoint const& offset), (offset))
        // SimpleAxisLayoutOptions
        callP(geode::SimpleAxisLayoutOptions, minRelScale, setMinRelativeScale, (std::optional<float> scale), (scale))
        callP(geode::SimpleAxisLayoutOptions, maxRelScale, setMaxRelativeScale, (std::optional<float> scale), (scale))
        callP(geode::SimpleAxisLayoutOptions, scalePrio, setScalingPriority, (geode::ScalingPriority priority), (priority))
        // AxisGap (this really doesnt need its own area...)
        callP(geode::AxisGap, gap, setGap, (float gap), (gap))

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

#undef callBase
#undef callBaseWithReqs
#undef call
#undef callP
#undef callPWithReqs
#undef withOther
#undef createP
#undef createPWithReqs
#undef setMember