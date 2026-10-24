#pragma once

#include <Geode/ui/Button.hpp>

namespace emerald {
    /// A button that is draggable.
    class DragButton : public geode::Button {
    public:
        using ButtonMoveCallback = geode::Function<void (DragButton* button, const cocos2d::CCPoint& pos)>;
        enum class ClampMode {
            /// No clamping
            None,
            /// Clamps to its parent's bounds.
            Parent,
            /// Clamps to the window.
            Window
        };
    protected:
        ButtonMoveCallback m_moveCallback;
        bool m_smooth = false;
        float m_smoothRate = 10.f;
        ClampMode m_clampMode = ClampMode::Window;

        cocos2d::CCPoint m_realPos = cocos2d::CCPoint{0, 0};
        bool m_hasMoved = false;
    public:
        bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override;
        void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override;
        void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override;
        void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override;

        void update(float delta) override;

        /// Gets the position of the button ignoring the smooth movement.
        /// If smooth movement is disabled, this is the same as getPosition.
        const cocos2d::CCPoint& getRealPosition() const;

        /// Gets if the button moves smoothly.
        bool isSmooth() const;
        /// Sets if the button should move smoothly.
        /// Defaults to false.
        void setSmooth(bool smooth);

        /// Gets rate the button should move when smooth.
        float getSmoothRate() const;
        /// Sets the rate the button should move when smooth.
        /// Defaults to 10.f.
        void setSmoothRate(float smoothRate);

        /// Sets the callback that is called when the button is moved.
        void setMoveCallback(ButtonMoveCallback moveCallback);

        #ifdef EMERALD_DEVTOOLS
        /// Called automatically if EMERALD_DEVTOOLS is defined.
        /// You don't need to call this.
        static void registerDevTools();
        #endif

        // the following docs are honestly just copied from the Button header because it's the same thing

        /**
         * Create a DragButton with no nodes on it
         * You will need to add a child yourself and position accordingly.
         * @param activateCallback The callback for when the button is activated
         */
        static DragButton* create(ButtonCallback activateCallback = nullptr);

        /**
         * Create a DragButton with a nodes on it.
         * The node will be automatically positioned in the center.
         * @param node The node that will show on the button.
         * @param activateCallback The callback for when the button is activated
         */
        static DragButton* createWithNode(CCNode* node, ButtonCallback activateCallback = nullptr);

        /**
         * Create a DragButton with a sprite by file name
         * @param fileName The file name of the sprite (not in a spritesheet)
         * @param activateCallback The callback for when the button is activated
         */
        static DragButton* createWithSprite(geode::ZStringView fileName, ButtonCallback activateCallback = nullptr);

        /**
         * Create a DragButton with a sprite by frame name
         * @param frameName The frame name of the sprite (in a spritesheet)
         * @param activateCallback The callback for when the button is activated
         */
        static DragButton* createWithSpriteFrameName(geode::ZStringView frameName, ButtonCallback activateCallback = nullptr);

        /**
         * Create a DragButton with a label
         * @param text The text shown on the label
         * @param font The font of the label
         * @param activateCallback The callback for when the button is activated
         */
        static DragButton* createWithLabel(geode::ZStringView text, geode::ZStringView font, ButtonCallback activateCallback = nullptr);
    };
}