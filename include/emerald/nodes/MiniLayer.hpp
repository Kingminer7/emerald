#pragma once

#include <emerald/utils/misc.hpp>
#include "Geode/utils/cocos.hpp"
#include <Geode/ui/Popup.hpp>

namespace emerald {
    /// A popup that contains a layer.
    /// Useful for situations like putting regular layers over PlayLayer.
    /// @tparam T The layer to contain.
    template <class T>
    class MiniLayer : public geode::Popup {
    protected:
        virtual bool init(T* layer, CCMenuItemSpriteExtra* closeBtn) {
            const auto ws = cocos2d::CCDirector::get()->getWinSize();
            if (!Popup::init(ws.width, ws.height)) return false;
            m_layer = layer;
            m_mainLayer->setVisible(false);
            addChild(m_layer);
            GivePopupStandardIdsWithModId(MiniLayer, "km7dev.emerald/");
            setUserFlag("undefined0.draggable-popups/undraggable-popup", true);
            setOpacity(0);

            if (closeBtn) {
                closeBtn->m_pfnSelector = menu_selector(MiniLayer::onClose);
                closeBtn->m_pListener = this;
            }

            return true;
        }

        bool m_closing = false;
        T* m_layer = nullptr;
    public:
        /// Creates a MiniLayer from a layer.
        /// @param layer The layer to contain.
        /// @param closeBtn The layer's back button so its callback can be replaced.
        static MiniLayer* create(T* layer, CCMenuItemSpriteExtra* closeBtn) {
            auto ret = new MiniLayer;
            if (ret->init(layer, closeBtn)) return ret->autorelease(), ret;
            return delete ret, nullptr;
        }

        /// Closes the popup.
        void onClose(CCObject* sender) override {
            if (m_closing) return;
            setKeyboardEnabled(false);
            setKeypadEnabled(false);
            setTouchEnabled(false);
            setMouseEnabled(false);
            m_layer->setKeyboardEnabled(false);
            m_layer->setKeypadEnabled(false);
            m_layer->setTouchEnabled(false);
            m_layer->setMouseEnabled(false);

            m_layer->stopAllActions();
            m_layer->runAction(cocos2d::CCSequence::createWithTwoActions(
                cocos2d::CCMoveTo::create(0.3, {0, cocos2d::CCDirector::sharedDirector()->getWinSize().height + 5}),
                geode::cocos::CallFuncExt::create([this]{
                    removeFromParent();
            })));
            m_closing = true;
        }

        /// Shows the popup.
        void show() override {
            if (m_noElasticity) return Popup::show();
            const auto dir = cocos2d::CCDirector::sharedDirector();
            m_noElasticity = true;
            Popup::show();
            m_mainLayer->setVisible(false);
            m_noElasticity = false;
            m_layer->setPosition({0, dir->getWinSize().height + 5});
            m_layer->stopAllActions();
            m_layer->runAction(cocos2d::CCEaseBounceOut::create(cocos2d::CCMoveTo::create(0.5, {0, 0})));
        }

        /// Gets if the popup is closing. Useful for not repeating logic on close.
        [[nodiscard]] virtual bool isClosing() const {
            return m_closing;
        }

        /// Gets the layer.
        /// What else could this possibly do?
        T* getLayer() {
            return m_layer;
        }
    };
}