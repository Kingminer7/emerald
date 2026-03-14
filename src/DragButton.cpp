#include <uilib/DragButton.hpp>

#include <Geode/Geode.hpp>
#include <utility>

using namespace geode::prelude;
using namespace uilib;

bool DragButton::ccTouchBegan(CCTouch* touch, CCEvent* event) {
    if (!nodeIsVisible(this)) return false;

    float multiplier = getTouchMultiplier();

    auto local = convertToNodeSpace(touch->getLocation());

    float width = getContentWidth();
    float height = getContentHeight();

    float scaledWidth = width * multiplier;
    float scaledHeight = height * multiplier;

    float dx = (scaledWidth - width) * 0.5f;
    float dy = (scaledHeight - height) * 0.5f;

    auto rect = CCRect{-dx, -dy, scaledWidth, scaledHeight};

    if (rect.containsPoint(local)) {
        // m_diff = this->getParent()->convertToNodeSpace(touch->getLocation()) - this->getPosition();
        m_hasMoved = false;
        m_realPos = getPosition();
        selected();
        return true;
    }
    return false;
}

void DragButton::ccTouchMoved(CCTouch* touch, CCEvent* event) {
    if (!m_hasMoved) {
        if ((touch->getLocation() - touch->getStartLocation()).getLength() > 3.f) m_hasMoved = true;
        else return;
    }
    m_realPos += touch->getDelta();
    if (m_moveCallback) m_moveCallback(this, m_realPos);
}

void DragButton::ccTouchEnded(CCTouch* touch, CCEvent* event) {
    unselected();
    if (m_hasMoved) return;
    activate();
}

void DragButton::ccTouchCancelled(CCTouch* touch, CCEvent* event) {
    unselected();
}

void DragButton::update(const float delta) {
    if (m_smooth) {
        setPosition(ccp(
            std::lerp<double>(getPositionX(), m_realPos.x, m_smoothRate * delta),
            std::lerp<double>(getPositionY(), m_realPos.y, m_smoothRate * delta)
        ));
    } else {
        setPosition(m_realPos);
    }
}

void DragButton::setPosition(const CCPoint& position) {
    if (m_clampMode == ClampMode::Window) {
        auto pos = position;
        const auto max = CCDirector::get()->getWinSize();
        const auto inWorld = getParent()->convertToWorldSpace(pos);
        pos.x = std::clamp(inWorld.x, 0.f, max.width);
        pos.y = std::clamp(inWorld.y, 0.f, max.height);
        Button::setPosition(pos);
    } else if (m_clampMode == ClampMode::Parent && m_pParent) {
        auto pos = position;
        const CCPoint max = m_pParent->getContentSize();
        pos.x = std::clamp(pos.x, 0.f, max.x);
        pos.y = std::clamp(pos.y, 0.f, max.y);
        Button::setPosition(pos);
    } else {
        Button::setPosition(position);
    }
}

const CCPoint& DragButton::getRealPosition() const {
    return m_realPos;
}

bool DragButton::isSmooth() const {
    return m_smooth;
}

void DragButton::setSmooth(const bool smooth) {
    m_smooth = smooth;
}

float DragButton::getSmoothRate() const {
    return m_smoothRate;
}

void DragButton::setSmoothRate(const float smoothRate) {
    m_smoothRate = smoothRate;
}

void DragButton::setMoveCallback(ButtonMoveCallback moveCallback) {
    m_moveCallback = std::move(moveCallback);
}

const DragButton::ButtonMoveCallback& DragButton::getMoveCallback() const {
    return m_moveCallback;
}

DragButton* DragButton::create(ButtonCallback activateCallback) {
    auto ret = new DragButton();
    if (ret->init(std::move(activateCallback))) {
        ret->autorelease();
        ret->scheduleUpdate();
        return ret;
    }
    delete ret;
    return nullptr;
}

DragButton* DragButton::createWithNode(CCNode* node, ButtonCallback activateCallback) {
    auto ret = new DragButton();
    if (ret->initWithNode(node, std::move(activateCallback))) {
        ret->autorelease();
        ret->scheduleUpdate();
        return ret;
    }
    delete ret;
    return nullptr;
}

DragButton* DragButton::createWithSprite(ZStringView fileName, ButtonCallback activateCallback) {
    auto ret = new DragButton();
    if (ret->initWithSprite(std::move(fileName), std::move(activateCallback))) {
        ret->autorelease();
        ret->scheduleUpdate();
        return ret;
    }
    delete ret;
    return nullptr;
}

DragButton* DragButton::createWithSpriteFrameName(ZStringView frameName, ButtonCallback activateCallback) {
    auto ret = new DragButton();
    if (ret->initWithSpriteFrameName(std::move(frameName),std::move(activateCallback))) {
        ret->autorelease();
        ret->scheduleUpdate();
        return ret;
    }
    delete ret;
    return nullptr;
}

DragButton* DragButton::createWithLabel(ZStringView text, ZStringView font, ButtonCallback activateCallback) {
    auto ret = new DragButton();
    if (ret->initWithLabel(std::move(text), std::move(font), std::move(activateCallback))) {
        ret->autorelease();
        ret->scheduleUpdate();
        return ret;
    }
    delete ret;
    return nullptr;
}

#ifdef UILIB_DEVTOOLS
#include <geode.devtools/include/API.hpp>

void DragButton::registerDevTools() {
    devtools::registerNode<DragButton>([](DragButton* node) {
        devtools::label("Drag Button");
        devtools::enumerable("Clamp Mode", node->m_clampMode, {
            { ClampMode::None, "None" },
            { ClampMode::Parent, "Parent" },
            { ClampMode::Window, "Window" }
        });
        devtools::property("Smooth", node->m_smooth);
        devtools::sameLine();
        devtools::property("Rate", node->m_smoothRate);
    });
}

$on_mod(Loaded) {
    devtools::waitForDevTools([] {
        DragButton::registerDevTools();
    });
}

#endif