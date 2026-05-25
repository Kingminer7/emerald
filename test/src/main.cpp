#include <Geode/Geode.hpp>

#include <emerald/nodes/DragButton.hpp>
#include <emerald/utils/Settings.hpp>
#include <emerald/nodes/MiniLayer.hpp>
#include <emerald/actions/TextTo.hpp>
#include <emerald/actions/SizeTo.hpp>

using namespace geode::prelude;
using namespace emerald;
using namespace emerald::actions;

class TestLayer : public CCLayer {
protected:
	bool init() override {
		if (!CCLayer::init()) return false;

		auto ns = NineSlice::create("GJ_square01.png");
		ns->setContentSize({300, 200});
		ns->runAction(CCRepeatForever::create(
			CCSequence::create(
				SizeTo::create(1, {200, 200}),
				SizeTo::create(1, {200, 300}),
				SizeTo::create(1, {300, 300}),
				SizeTo::create(1, {300, 200}),
				nullptr)));
		addChild(ns);
		ns->setPosition(getContentSize() / 2);

		auto lab = CCLabelBMFont::create("Hello world!", "bigFont.fnt");
		addChild(lab);
		lab->runAction(CCRepeatForever::create(
			CCSequence::create(
				TextTo::create(1, "String 1 Lmao"),
				CCDelayTime::create(1),
				TextTo::create(1, "Other String Lmao2"),
				CCDelayTime::create(1),
				nullptr)));
		lab->setPosition(getContentSize() / 2);
		log::info("{}", getSettingFast<"A", bool>());
		return true;
	}
public:
	static TestLayer* create() {
		auto ret = new TestLayer();
		if (!ret->init()) return delete ret, nullptr;
		return ret->autorelease(), ret;
	}
};

$on_game(Loaded) {
	OverlayManager::get()->addChild(DragButton::createWithNode(CircleButtonSprite::createWithSpriteFrameName("GJ_bigStar_001.png", 1.f, CircleBaseColor::Blue, CircleBaseSize::Small), [](auto) {
		MiniLayer<TestLayer>::create(TestLayer::create(), nullptr)->show();;
	}));
}