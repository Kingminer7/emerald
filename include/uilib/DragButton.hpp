#pragma once

#include <Geode/ui/Button.hpp>

namespace uilib {
    class DragButton : public geode::Button {
    public:
        using ButtonMoveCallback = geode::Function<void (DragButton* button, const cocos2d::CCPoint& pos)>;
        enum class ClampMode {
            // No clamping
            None,
            // Clamp to parent
            Parent,
            // Clamp to window
            Window
        };
    protected:
        ButtonMoveCallback m_moveCallback;
        bool m_smooth = false;
        float m_smoothRate = 10.f;
        ClampMode m_clampMode = ClampMode::Window;

        cocos2d::CCPoint m_realPos = cocos2d::CCPoint{0, 0};
        bool m_hasMoved = false;

        bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override;
        void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override;
        void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override;
        void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override;

        void update(float delta) override;
    public:
        const cocos2d::CCPoint& getRealPosition() const;

        bool isSmooth() const;
        void setSmooth(bool smooth);

        float getSmoothRate() const;
        void setSmoothRate(float smoothRate);

        void setMoveCallback(ButtonMoveCallback moveCallback);
        const ButtonMoveCallback& getMoveCallback() const;

        #ifdef UILIB_DEVTOOLS
        static void registerDevTools();
        #endif

        static DragButton* create(ButtonCallback activateCallback = nullptr);
        static DragButton* createWithNode(CCNode* node, ButtonCallback activateCallback = nullptr);
        static DragButton* createWithSprite(geode::ZStringView fileName, ButtonCallback activateCallback = nullptr);
        static DragButton* createWithSpriteFrameName(geode::ZStringView frameName, ButtonCallback activateCallback = nullptr);
        static DragButton* createWithLabel(geode::ZStringView text, geode::ZStringView font, ButtonCallback activateCallback = nullptr);
    };
}