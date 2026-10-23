#pragma once

#include <Geode/cocos/actions/CCActionInterval.h>

namespace emerald::actions {
    class TextTo : public cocos2d::CCActionInterval {
    public:
        bool initWithDuration(float duration, std::string text);
        void startWithTarget(cocos2d::CCNode *pTarget) override;
        void update(float time) override;
        static TextTo* create(float duration, std::string text);
    protected:
        float m_timeToUntype = 0.f;
        float m_timeToType = 0.f;
        std::string m_startText;
        std::string m_endText;
    };
}