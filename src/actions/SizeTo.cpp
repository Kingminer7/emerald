#include "emerald/actions/SizeTo.hpp"

using namespace geode::prelude;
using namespace emerald::actions;

SizeTo* SizeTo::create(float duration, const CCSize& size) {
    auto ret = new SizeTo();
    if (!ret || !ret->initWithDuration(duration, size)) {
        delete ret;
        return nullptr;
    }
    ret->autorelease();
    return ret;
}

bool SizeTo::initWithDuration(float duration, const CCSize& size) {
    if (!CCActionInterval::initWithDuration(duration)) return false;
    m_endSize = size;
    return true;
}

void SizeTo::startWithTarget(CCNode* pTarget) {
    CCActionInterval::startWithTarget(pTarget);
    m_startSize = pTarget->getContentSize();
    m_deltaSize = m_endSize - m_startSize;
}

void SizeTo::update(float time) {
    if (!m_pTarget) return;
    m_pTarget->setContentSize(m_startSize + m_deltaSize * time);
    m_pTarget->updateLayout();
}