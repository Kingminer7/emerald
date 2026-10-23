#pragma once

#define GivePopupStandardIdsWithModId(className, spr) \
    this->setID(spr #className); \
    if (m_title) m_title->setID("title-label"); \
    m_mainLayer->setID("main-layer"); \
    m_buttonMenu->setID("close-menu"); \
    m_closeBtn->setID("close-btn"); \
    m_bgSprite->setID("background")

#define GivePopupStandardIds(className) GivePopupStandardIdsWithModId(className, ""_spr)