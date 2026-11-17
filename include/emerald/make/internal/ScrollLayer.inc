#pragma once

callP(geode::ScrollLayer, enableScrollWheel, enableScrollWheel, (bool enable = true), (enable))
call(geode::ScrollLayer, scrollToTop, scrollToTop)
callP(geode::ScrollLayer, scrollFromTop, scrollToFromTop, (float distance), (distance))
callP(geode::ScrollLayer, cancelTouchLimit, setCancelTouchLimit, (float limit), (limit))
callP(geode::ScrollLayer, stealTouches, setStealingTouches, (bool stealing), (stealing))
callBase(geode::ScrollLayer, defaultLayout, (float gap = 2.5f)) {
    if (m_obj && m_obj->m_contentLayer)
        m_obj->m_contentLayer->setLayout(geode::ScrollLayer::createDefaultListLayout(gap));
    return *this;
}
withOther(geode::ScrollLayer, withContentLayer, geode::GenericContentLayer, contentLayer, static_cast<geode::GenericContentLayer*>(m_obj->m_contentLayer))
callBase(geode::ScrollLayer, createScrollbar, (cocos2d::CCNode* parent, const cocos2d::CCPoint& pos, geode::Function<void(Make<geode::Scrollbar> bar)> callback = nullptr)) {
    auto bar = Make<geode::Scrollbar>::create(m_obj)
        .pos(pos)
        .parent(parent);
    if (callback) callback(bar);
    return *this;
}
callBase(geode::ScrollLayer, createScrollbar, (cocos2d::CCNode* parent, geode::Anchor anchor, const cocos2d::CCPoint& offset, geode::Function<void(Make<geode::Scrollbar> bar)> callback = nullptr)) {
    auto bar = Make<geode::Scrollbar>::create(m_obj)
        .parentAtPos(parent, anchor, offset);
    if (callback) callback(bar);
    return *this;
}
withOther(geode::ScrollLayer, withClippingNode, cocos2d::CCClippingNode, clippingNode, m_obj->getClippingNode())
callP(geode::ScrollLayer, enableTouchClipping, enableTouchClipping, (bool clip), (clip))
callP(geode::ScrollLayer, enableScrollClipping, enableScrollClipping, (bool clip), (clip))
callP(geode::ScrollLayer, stencil, setStencil, (cocos2d::CCNode* stencil), (stencil))
withOtherC(geode::ScrollLayer, withStencil, cocos2d::CCNode, stencil, m_obj->getStencil())

// Scrollbar
callP(geode::Scrollbar, target, setTarget, (CCScrollLayerExt* list), (list))
callP(geode::Scrollbar, track, setTrack, (geode::NineSlice* track), (track))
callP(geode::Scrollbar, thumb, setThumb, (geode::NineSlice* thumb), (thumb))
#ifdef SCROLLBAR_CHANGES_MERGED
callP(geode::Scrollbar, overscrollShrink, setShrinkWithOverscroll, (bool shrink), (shrink))
callP(geode::Scrollbar, touchInThumb, setTouchInThumb, (bool onlyInThumb), (onlyInThumb))
callP(geode::Scrollbar, style, setStyle, (geode::Scrollbar::Style style), (style))
callP(geode::Scrollbar, thumbColors, setShrinkWithOverscroll, (cocos2d::ccColor4B normal, cocos2d::ccColor4B selected), (std::move(normal), std::move(selected)))
#endif
withOtherC(geode::Scrollbar, withTarget, CCScrollLayerExt, scroll, m_obj->getTarget())
withOther(geode::Scrollbar, withTrack, geode::NineSlice, track, m_obj->getTrack())
withOther(geode::Scrollbar, withThumb, geode::NineSlice, thumb, m_obj->getThumb())