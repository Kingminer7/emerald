#include "uilib/actions/SizeTo.hpp"

using namespace geode::prelude;
using namespace uilib::actions;

SizeTo* SizeTo::create(float duration, CCSize s) {
    SizeTo *ret = new SizeTo();
    if (!ret || !ret->initWithDuration(duration, s)) {
        delete ret;
        return nullptr;
    }
    ret->autorelease();
    return ret;
}

bool SizeTo::initWithDuration(float duration, CCSize s) {
    if (!CCActionInterval::initWithDuration(duration)) return false;
    m_endSize = s;
    return true;
}

void SizeTo::startWithTarget(CCNode *pTarget) {
    CCActionInterval::startWithTarget(pTarget);
    m_startSize = pTarget->getContentSize();
    m_deltaSize = m_endSize - m_startSize;
}

void SizeTo::update(float time) {
    if (!m_pTarget) return;
    m_pTarget->setContentSize(m_startSize + m_deltaSize * time);
    m_pTarget->updateLayout();
}