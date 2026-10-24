#pragma once

#include <Geode/cocos/actions/CCActionInterval.h>

namespace emerald::actions {
    class SizeTo : public cocos2d::CCActionInterval {
    public:
        bool initWithDuration(float duration, const cocos2d::CCSize& size);
        void startWithTarget(cocos2d::CCNode* pTarget) override;
        void update(float time) override;
        static SizeTo* create(float duration, const cocos2d::CCSize& size);
    protected:
        cocos2d::CCSize m_startSize;
        cocos2d::CCSize m_endSize;
        cocos2d::CCSize m_deltaSize;
    };
}