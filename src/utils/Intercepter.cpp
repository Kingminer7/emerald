#include "emerald/utils/Intercepter.hpp"

using namespace geode::prelude;
using namespace emerald;

void Intercepter::original(CCObject* sender) const {
    (m_origListener->*m_origSel)(sender);
}

void Intercepter::execute(CCObject* sender) {
    if (callback) callback(this, sender);
}

Intercepter* Intercepter::create(CCMenuItem* menuItem, Callback callback) {
    auto ret = new Intercepter(menuItem, std::move(callback));
    ret->autorelease();
    return ret;
}

Intercepter::Intercepter(CCMenuItem* btn, Callback callback) {
    this->callback = std::move(callback);
    this->m_btn = btn;
    this->m_origListener = btn->m_pListener;
    this->m_origSel = btn->m_pfnSelector;
    btn->m_pListener = this;
    btn->m_pfnSelector = menu_selector(Intercepter::execute);

    if (auto arr = typeinfo_cast<CCArray*>(m_btn->getUserObject("km7dev.emerald/interceptors"))) {
        arr->addObject(this);
    } else {
        arr = CCArray::createWithObject(this);
        m_btn->setUserObject("km7dev.emerald/interceptors", arr);
    }
}
