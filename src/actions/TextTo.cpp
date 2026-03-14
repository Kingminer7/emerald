#include <utility>

#include "uilib/actions/TextTo.hpp"
#include "Geode/cocos/label_nodes/CCLabelBMFont.h"

using namespace geode::prelude;
using namespace uilib::actions;

TextTo* TextTo::create(float duration, std::string text) {
    const auto ret = new TextTo();
    if (!ret->initWithDuration(duration, std::move(text))) {
        delete ret;
        return nullptr;
    }
    ret->autorelease();
    return ret;
}

bool TextTo::initWithDuration(float duration, std::string text) {
    if (!CCActionInterval::initWithDuration(duration)) return false;
    m_endText = std::move(text);
    return true;
}

void TextTo::startWithTarget(CCNode *pTarget) {
    if (auto target = static_cast<CCLabelBMFont*>(pTarget)) {
        CCActionInterval::startWithTarget(pTarget);
        m_startText = target->getString();
        auto totalChars = m_startText.length() + m_endText.length();
        m_timeToUntype = (float) m_startText.length() / totalChars;
        m_timeToType = (float) m_endText.length() / totalChars;
    }
    
}

void TextTo::update(float time) {
    if (!m_pTarget) return;
    if (auto target = static_cast<CCLabelBMFont*>(m_pTarget)) {
        if (time < m_timeToUntype) {
            auto chars = round((time / m_timeToUntype) * m_startText.length());
            target->setString(m_startText.substr(0,  m_startText.length() - chars).c_str());
        } else if (time > m_timeToUntype) {
            auto chars = round(((time - m_timeToUntype) / m_timeToType) * m_endText.length());
            target->setString(m_endText.substr(0, chars).c_str());
        }
    }
}