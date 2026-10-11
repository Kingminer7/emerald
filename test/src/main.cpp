#include <Geode/Geode.hpp>

#include <emerald/nodes/DragButton.hpp>
#include <emerald/utils/Settings.hpp>
#include <emerald/nodes/MiniLayer.hpp>
#include <emerald/actions/TextTo.hpp>
#include <emerald/actions/SizeTo.hpp>
#include <emerald/utils/NodeQuery.hpp>

using namespace geode::prelude;
using namespace emerald;
using namespace emerald::actions;

class TestLayer : public CCLayer {
protected:
	bool init() override {
		if (!CCLayer::init()) return false;
		setTag(1);

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

		auto test1 = CCNode::create();
		test1->setID("test-1");
		auto tc1 = CCNode::create();
		test1->addChild(tc1);
		auto tc2 = CCNode::create();
		tc1->addChild(tc2);
		auto tc3 = CCNode::create();
		tc2->addChild(tc3);
		auto tc4 = CCNode::create();
		tc3->addChild(tc4);
		auto test2 = CCNode::create();
		test2->setID("test-2");
		tc4->addChild(test2);
		ns->addChild(test1);

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
		MiniLayer<TestLayer>::create(TestLayer::create(), nullptr)->show();
		auto query = NodeQuery(CCScene::get())
			.type<MiniLayer<TestLayer>>()
			.ifErr([] {
				log::info("TestLayer is nullptr");
			})
			.ifOk([] {
				log::info("TestLayer is ok");
			})
			.tag(1)
			.run([](auto result) {
				log::info("Tag: {}", result);
			})
			.index(0)
			.run([](auto result) {
				log::info("index: {}", result);
			})
			.id("test-1")
			.run([](auto result) {
				log::info("id: {}", result);
			})
			.idRec("test-2");
		if (query.exists()) {
			log::info("Exists");
			auto node = *query;
			if (query == node) {
				log::info("equal 1");
			}
			if (query == nullptr) {
				log::info("equal nullptr");
			}
			if (query) query->setPosition({5, 5});
		}
	}));
}