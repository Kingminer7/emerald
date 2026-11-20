#pragma once

callP(cocos2d::CCNode, zOrder, setZOrder, (int zOrder), (zOrder))
callP(cocos2d::CCNode, scaleX, setScaleX, (float x), (x))
callP(cocos2d::CCNode, scaleY, setScaleY, (float y), (y))
callP(cocos2d::CCNode, scale, setScale, (float scale), (scale))
callP(cocos2d::CCNode, scale, setScale, (float x, float y), (x, y))
callP(cocos2d::CCNode, scale, setScale, (const cocos2d::CCSize& size), (size.width, size.height))
callP(cocos2d::CCNode, posX, setPositionX, (float x), (x))
callP(cocos2d::CCNode, posY, setPositionY, (float y), (y))
callP(cocos2d::CCNode, pos, setPosition, (const cocos2d::CCPoint& pos), (pos))
callP(cocos2d::CCNode, pos, setPosition, (float x, float y), (cocos2d::CCPoint{x, y}))
callP(cocos2d::CCNode, skewX, setSkewX, (float x), (x))
callP(cocos2d::CCNode, skewY, setSkewY, (float y), (y))
callBase(cocos2d::CCNode, skew, (float x, float y)){
    if (this->m_obj) {
        this->m_obj->setSkewX(x);
        this->m_obj->setSkewY(y);
    }
    return *this;
}
callBase(cocos2d::CCNode, skew, (const cocos2d::CCPoint& skew)){
    if (this->m_obj) {
        this->m_obj->setSkewX(skew.x);
        this->m_obj->setSkewY(skew.y);
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
callBase(cocos2d::CCNode, rotation, (float x, float y)){
    if (this->m_obj) {
        this->m_obj->setRotationX(x);
        this->m_obj->setRotationY(y);
    }
    return *this;
}
callBase(cocos2d::CCNode, rotation, (const cocos2d::CCPoint& rot)){
    if (this->m_obj) {
        this->m_obj->setRotationX(rot.x);
        this->m_obj->setRotationY(rot.y);
    }
    return *this;
}
callP(cocos2d::CCNode, orderArrive, setOrderOfArrival, (unsigned int order), (order))
callP(cocos2d::CCNode, ignoreAnchor, ignoreAnchorPointForPosition, (bool ignore), (ignore))
callP(cocos2d::CCNode, child, addChild, (cocos2d::CCNode* child), (child))
callP(cocos2d::CCNode, child, addChild, (cocos2d::CCNode* child, int zOrder), (child, zOrder) )
callP(cocos2d::CCNode, child, addChild, (cocos2d::CCNode* child, int zOrder, int tag), (child, zOrder, tag))
callP(cocos2d::CCNode, childAtPos, addChildAtPosition, (cocos2d::CCNode* child, geode::Anchor anchor, cocos2d::CCPoint const& offset = {}, bool useAnchorLayout = true), (child, anchor, offset, useAnchorLayout))
callP(cocos2d::CCNode, childAtPos, addChildAtPosition, (cocos2d::CCNode* child, geode::Anchor anchor, cocos2d::CCPoint const& offset, cocos2d::CCPoint const& nodeAnchor, bool useAnchorLayout = true), (child, anchor, offset, nodeAnchor, useAnchorLayout))
callP(cocos2d::CCNode, children, addChildren, (std::span<cocos2d::CCNode* const> children), (std::move(children)))
callPT(cocos2d::CCNode, children, addChildren, ...Args, (Args... children), (children...))
callP(cocos2d::CCNode, userObj, setUserObject, (cocos2d::CCObject* obj), (obj))
callP(cocos2d::CCNode, userObj, setUserObject, (std::string id, cocos2d::CCObject* obj), (std::move(id), obj))
callP(cocos2d::CCNode, flag, setUserFlag, (std::string id, bool state = false), (id, state))
callP(cocos2d::CCNode, id, setID, (std::string id), (std::move(id)))
callP(cocos2d::CCNode, layout, setLayout, (geode::Layout* layout), (layout))
callP(cocos2d::CCNode, layoutOpts, setLayoutOptions, (geode::LayoutOptions* opts, bool update = true), (opts, update))
call(cocos2d::CCNode, updateLayout, updateLayout)
template <class Event, class Callback>
callP(cocos2d::CCNode, listen, addEventListener, (Event const& event, Callback&& callback, int prio = 0), (event, std::forward<Callback>(callback), prio))
template <class Event, class Callback>
callP(cocos2d::CCNode, listen, addEventListener, (std::string_view id, Event const& event, Callback&& callback, int prio = 0), (id, event, std::forward<Callback>(callback), prio))
callPT(cocos2d::CCNode, onEnter, addOnEnterCallback, Callback, (Callback&& callback, int prio = 0), (std::forward<Callback>(callback), prio))
callPT(cocos2d::CCNode, onEnterTransFinished, addOnEnterTransitionDidFinishCallback, Callback, (Callback&& callback, int prio = 0), (std::forward<Callback>(callback), prio))
callPT(cocos2d::CCNode, onExit, addOnExitCallback, Callback, (Callback&& callback, int prio = 0), (std::forward<Callback>(callback), prio))
callPT(cocos2d::CCNode, onExitTransStart, addOnExitTransitionDidStartCallback, Callback, (Callback&& callback, int prio = 0), (std::forward<Callback>(callback), prio))
callPT(cocos2d::CCNode, onCleanup, addCleanupCallback, Callback, (Callback&& callback, int prio = 0), (std::forward<Callback>(callback), prio))
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
callBaseTo(cocos2d::CCNode, intoParent, (P* parent), P) {
    if (m_obj && parent) parent->addChild(m_obj);
    return Make<P>(parent);
}
template <typename P>
callBaseTo(cocos2d::CCNode, intoParent, (P* parent, int zOrder), P) {
    if (m_obj && parent) parent->addChild(m_obj, zOrder);
    return Make<P>(parent);
}
template <typename P>
callBaseTo(cocos2d::CCNode, intoParent, (P* parent, int zOrder, int tag), P) {
    if (m_obj && parent) parent->addChild(m_obj, zOrder, tag);
    return Make<P>(parent);
}
template <typename P>
callBaseTo(cocos2d::CCNode, intoParentAtPos, (P* parent, geode::Anchor anchor, cocos2d::CCPoint const& offset = {}, bool useAnchorLayout = true), P) {
    if (m_obj && parent) parent->addChildAtPosition(m_obj, anchor, offset, useAnchorLayout);
    return Make<P>(parent);
}
template <typename P>
callBaseTo(cocos2d::CCNode, intoParentAtPos, (P* parent, geode::Anchor anchor, cocos2d::CCPoint const& offset, cocos2d::CCPoint const& nodeAnchor, bool useAnchorLayout = true), P) {
    if (m_obj && parent) parent->addChildAtPosition(m_obj, anchor, offset, nodeAnchor, useAnchorLayout);
    return Make<P>(parent);
}

callBase(cocos2d::CCNode, posAnchored, (geode::Anchor anchor, const cocos2d::CCPoint& pos = {})) {
    if (m_obj) m_obj->setLayoutOptions(geode::AnchorLayoutOptions::create()
        ->setAnchor(anchor)
        ->setOffset(pos));
    return *this;
}

call(cocos2d::CCNode, removeParent, removeFromParent)

template <typename N = geode::Layout> requires std::derived_from<N, geode::Layout>
withOther(cocos2d::CCNode, withLayout, N, layout, m_obj->template getLayout<N>())
template <typename N = geode::LayoutOptions> requires std::derived_from<N, geode::LayoutOptions>
withOther(cocos2d::CCNode, withLayoutOpts, N, layout, static_cast<N*>(m_obj->getLayoutOptions()))