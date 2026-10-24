#pragma once

/// Gives the popup standard IDs, with a mod id that you specify.
/// Useful for popups created by libraries (such as minilayer) or just templated popups in api headers.
#define GivePopupStandardIdsWithModId(className, spr) \
    this->setID(spr #className); \
    if (m_title) m_title->setID("title-label"); \
    m_mainLayer->setID("main-layer"); \
    m_buttonMenu->setID("close-menu"); \
    m_closeBtn->setID("close-btn"); \
    m_bgSprite->setID("background")

/// Gives the popup standard IDs, using the mod id from _spr.
#define GivePopupStandardIds(className) GivePopupStandardIdsWithModId(className, ""_spr)