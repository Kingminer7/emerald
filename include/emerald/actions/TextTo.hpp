#pragma once

#include <Geode/cocos/actions/CCActionInterval.h>

namespace emerald::actions {
    class TextTo : public cocos2d::CCActionInterval {
    public:
        bool initWithDuration(float duration, std::string text);
        virtual void startWithTarget(cocos2d::CCNode *pTarget);
        virtual void update(float time);
        static TextTo* create(float duration, std::string text);
    protected:;
        float m_timeToUntype;
        float m_timeToType;
        std::string m_startText;
        std::string m_endText;
    };
}