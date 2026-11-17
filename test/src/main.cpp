#include <Geode/Geode.hpp>

#include <emerald/actions/SizeTo.hpp>
#include <emerald/actions/TextTo.hpp>
#include <emerald/make/Make.hpp>
#include <emerald/nodes/DragButton.hpp>
#include <emerald/nodes/MiniLayer.hpp>
#include <emerald/utils/Intercepter.hpp>
#include <emerald/utils/NodeQuery.hpp>
#include <emerald/utils/Settings.hpp>

// using namespace geode::prelude;
using namespace emerald;
using namespace emerald::actions;

class TestLayer : public cocos2d::CCLayer {
protected:
	bool init() override {
		if (!CCLayer::init()) return false;
		setTag(1);

		auto ns = Make<geode::NineSlice>::create("GJ_square01.png")
			.size(300, 200)
			.action(cocos2d::CCRepeatForever::create(cocos2d::CCSequence::create(
				SizeTo::create(1, {200, 200}),
				SizeTo::create(1, {200, 300}),
				SizeTo::create(1, {300, 300}),
				SizeTo::create(1, {300, 200}),
				nullptr)))
			.parentAtPos(this, geode::Anchor::Center);

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
		ns.child(test1);

		auto cfg = NPMake<geode::MDConfig>()
			.blockQuoteIndent(4)
			.get();

		auto lab = cocos2d::CCLabelBMFont::create("Hello world!", "bigFont.fnt");
		addChild(lab);
		lab->runAction(cocos2d::CCRepeatForever::create(
			cocos2d::CCSequence::create(
				TextTo::create(1, "String 1 Lmao"),
				cocos2d::CCDelayTime::create(1),
				TextTo::create(1, "Other String Lmao2"),
				cocos2d::CCDelayTime::create(1),
				nullptr)));

		lab->setPosition(getContentSize() / 2);
		geode::log::info("{}", getSettingFast<"A", bool>());

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
	geode::OverlayManager::get()->addChild(DragButton::createWithNode(geode::CircleButtonSprite::createWithSpriteFrameName("GJ_bigStar_001.png", 1.f, geode::CircleBaseColor::Blue, geode::CircleBaseSize::Small), [](auto) {
		MiniLayer<TestLayer>::create(TestLayer::create(), nullptr)->show();
		auto query = NodeQuery(cocos2d::CCScene::get())
			.type<MiniLayer<TestLayer>>()
			.ifErr([] {
				geode::log::info("TestLayer is nullptr");
			})
			.ifOk([](auto) {
				geode::log::info("TestLayer is ok");
			})
			.tag(1)
			.run([](auto result) {
				geode::log::info("Tag: {}", result);
			})
			.index(0)
			.run([](auto result) {
				geode::log::info("index: {}", result);
			})
			.id("test-1")
			.run([](auto result) {
				geode::log::info("id: {}", result);
			})
			.idRec("test-2");
		if (query.exists()) {
			geode::log::info("Exists");
			auto node = *query;
			if (query == node) {
				geode::log::info("equal 1");
			}
			if (query == nullptr) {
				geode::log::info("equal nullptr");
			}
			if (query) query->setPosition({5, 5});
		}
	}));
}

#include <Geode/modify/MenuLayer.hpp>

class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;
		NodeQuery(this).id("bottom-menu").id<CCMenuItemSpriteExtra>("newgrounds-button").ifOk([](auto btn) {
			Intercepter::create(btn, [](Intercepter* self, CCObject* sender) {
				geode::createQuickPopup("Test", "uh do you wanna open newgrounds", "YEs", "No", [self, sender](auto, bool sec) {
					if (sec) return;
					self->original(sender);
				});
			});
		});
		return true;
	}
};

// Just making sure everything compiles, most of these are meaningless.
// PLEASE never call this, it will probably crash.
// actually, not probably, definitely. i love passing ccscene into random stuff for tests
void tests() {
	// CCObject tests
	cocos2d::CCObject* var1;
	geode::Ref<cocos2d::CCObject> var2;

	Make(new cocos2d::CCObject)
		.autorel()
		.tag(4)
		.retain()
		.store(var1)
		.store(var2)
		.release();

	// CCNode tests
	Make<cocos2d::CCNode>::create()
		.zOrder(4)
		.scaleX(7.f)
		.scaleY(3.f)
		.scale(3.f)
		.scale(2.f, 4.f)
		.scale(cocos2d::CCSize{3.f, 5.f})
		.posX(3)
		.posY(0)
		.pos(cocos2d::CCPoint{3.f, 7.f})
		.pos(3.f, 7.f)
		.skewX(5.f)
		.skewY(3.f)
		.skew(7.f, 8.f)
		.skew(cocos2d::CCPoint{3.f, 7.f})
		.anchor(.5f, .5f)
		.anchor(cocos2d::CCPoint{.5f, .5f})
		.width(60.f)
		.height(80.f)
		.size(cocos2d::CCSize{50.f, 40.f})
		.size(50.f, 40.f)
		.visible(true)
		.rotationX(3.f)
		.rotationY(3.f)
		.rotation(3.f)
		.rotation(7.f, 3.f)
		.rotation(cocos2d::CCPoint{7.f, 3.f})
		.orderArrive(6)
		.ignoreAnchor(false)
		.child(Make<cocos2d::CCNode>::create())
		.child(Make<cocos2d::CCNode>::create(), 3)
		.child(Make<cocos2d::CCNode>::create(), 3, 7)
		.childAtPos(Make<cocos2d::CCNode>::create(), geode::Anchor::Center, {300.f, 400.f}, true)
		.childAtPos(Make<cocos2d::CCNode>::create(), geode::Anchor::Center, {300.f, 400.f}, {0.5f, 0.5f}, true)
		.children({{cocos2d::CCNode::create(), cocos2d::CCNode::create(), cocos2d::CCNode::create()}})
		.children(Make<cocos2d::CCNode>::create(), Make<cocos2d::CCNode>::create(), Make<cocos2d::CCNode>::create())
		.userObj(cocos2d::CCNode::create())
		.userObj("test"_spr, cocos2d::CCNode::create())
		.flag("test"_spr, true)
		.id("Test")
		.layout(geode::AxisLayout::create())
		.layoutOpts(geode::AxisLayoutOptions::create())
		.updateLayout()
		.listen(geode::KeyboardInputEvent(), [](geode::KeyboardInputData& data) {
			return true;
		}, 5)
		.listen("Test", geode::KeyboardInputEvent(), [](geode::KeyboardInputData& data) {
			return true;
		}, 5)
		.onEnter([] {
			return true;
		}, 6)
		.onEnterTransFinished([] {
			return true;
		}, 6)
		.onExit([] {
			return true;
		}, 6)
		.onExitTransStart([] {
			return true;
		}, 6)
		.onCleanup([] {
			return true;
		})
		.shader(cocos2d::CCShaderCache::sharedShaderCache()->programForKey(kCCShader_PositionTextureColor))
		.action(cocos2d::CCMoveTo::create(.5f, cocos2d::CCPoint{30.f, 40.f}))
		.parent(cocos2d::CCScene::get())
		.removeParent()
		.parent(cocos2d::CCScene::get(), 7).removeParent()
		.parent(cocos2d::CCScene::get(), 7, 3).removeParent()
		.parentAtPos(cocos2d::CCScene::get(), geode::Anchor::Center, {3.f, 5.f}).removeParent()
		.parentAtPos(cocos2d::CCScene::get(), geode::Anchor::Center, {4.f, 7.f}, {3.f, 5.f})
		.intoParent(cocos2d::CCScene::get())
		.intoParent(cocos2d::CCScene::get(), 7)
		.intoParent(cocos2d::CCScene::get(), 7, 3)
		.intoParentAtPos(cocos2d::CCScene::get(), geode::Anchor::Center, {3.f, 5.f})
		.intoParentAtPos(cocos2d::CCScene::get(), geode::Anchor::Center, {4.f, 7.f}, {3.f, 5.f})
		.posAnchored(geode::Anchor::Center, {3.f, 5.f})
		.withLayout<geode::AxisLayout>([](Make<geode::AxisLayout> layout) {
			layout.autoScale(true);
		})
		.withLayoutOpts<geode::AxisLayoutOptions>([](Make<geode::AxisLayoutOptions> opts) {
			opts.nextGap(4.f);
		});

	// Protocol tests

	Make<cocos2d::CCLabelBMFont>::create("hi", "bigFont.fnt")
		.opacity(7)
		.color(cocos2d::ccColor3B{36, 37, 39})
		.color(36, 37, 39)
		.color(cocos2d::ccColor4B{36, 37, 39, 7})
		.color(36, 37, 39, 7)
		.cascadeOpacity(true)
		.cascadeColor(true)
		.opacityModRGB(true)
		.blend(cocos2d::kCCBlendFuncDisable)
		.texture(cocos2d::CCTextureCache::get()->textureForKey("test.png"_spr))
		.text("Test")
		.text(std::string("Test"));

	// CCLayer tests
	Make<cocos2d::CCLayer>::create()
		.registerTouch()
		.touchEnabled(true)
		.touchPrio(-4)
		.keypadEnabled(true)
		.keyboardEnabled(true)
		.mouseEnabled(true)
		.push();

	// Sprite tests
	Make<cocos2d::CCSprite>::createTexture(cocos2d::CCTextureCache::get()->textureForKey("test.png"_spr));
	Make<cocos2d::CCSprite>::createFrame(cocos2d::CCSpriteFrameCache::get()->spriteFrameByName("test.png"_spr));
	Make<cocos2d::CCSprite>::createFrameName("test.png")
		.batchNode(cocos2d::CCSpriteBatchNode::create("test.png"))
		.texRect({3.f, 3.f, 3.f, 3.f})
		.texRect({3.f, 3.f, 3.f, 3.f}, true, {4.f, 4.f})
		.displayFrame(cocos2d::CCSpriteFrameCache::get()->spriteFrameByName("test.png"_spr))
		.displayFrameAnimName("test", 3)
		.setDirty(true)
		.flipX(true)
		.flipY(true)
		.flip(true, true);

	Make<geode::LazySprite>::create(cocos2d::CCSize{30.f, 30.f}, true)
		.fromUrl("https://example.com")
		.fromFile(geode::dirs::getResourcesDir() / "square_01.png")
		.fromData({{7, 7, 7}})
		.fromData(new uint8_t(7))
		.setOnLoad([](const auto& ret) {
			ret.unwrapErr();
		})
		.autoResize(true);

	Make<geode::CircleButtonSprite>::createFileName("test.png", 4.f, geode::CircleBaseColor::Green, geode::CircleBaseSize::Big)
		.topOffset(cocos2d::CCPoint{3.f, 4.f})
		.topOffset(3.f, 4.f)
		.scale(.3f);

	// Menus / Buttons

	Make<cocos2d::CCMenu>::create()
		.giveTouchPrio(5.f)
		.handlerPrio(5)
		.enabled(true);

	Make<cocos2d::CCMenuItem>::createCB([](auto btn) {})
		.activate()
		.select()
		.unselect()
		.enabled(true)
		.target(cocos2d::CCScene::get(), menu_selector(MenuLayer::onPlay))
		.setCallback([](auto){})
		.addCallback([](const auto&){}, 7);

	Make<cocos2d::CCMenuItemSprite>::createCB(cocos2d::CCNode::create(), cocos2d::CCNode::create(), [](auto){});
	Make<cocos2d::CCMenuItemSprite>::createCB(cocos2d::CCNode::create(), cocos2d::CCNode::create(), cocos2d::CCNode::create(), [](auto){})
		.displayNode(cocos2d::CCNode::create())
		.selectedNode(cocos2d::CCNode::create())
		.disabledNode(cocos2d::CCNode::create())
		.withDisplayNode([](Make<cocos2d::CCNode> node) {
			node.visible(false);
		})
		.withDisplayNodeCast<cocos2d::CCSprite>([](Make<cocos2d::CCSprite> node) {
			node.visible(false);
		})
		.withSelectedNode([](Make<cocos2d::CCNode> node) {
			node.visible(false);
		})
		.withSelectedNodeCast<cocos2d::CCSprite>([](Make<cocos2d::CCSprite> node) {
			node.visible(false);
		})
		.withDisabledNode([](Make<cocos2d::CCNode> node) {
			node.visible(false);
		})
		.withDisabledNodeCast<cocos2d::CCSprite>([](Make<cocos2d::CCSprite> node) {
			node.visible(false);
		});

	Make<CCMenuItemSpriteExtra>::createCB(cocos2d::CCNode::create(), [](auto){});
	Make<CCMenuItemSpriteExtra>::createFileName("Test", 1.f, [](auto){});
	Make<CCMenuItemSpriteExtra>::createFrameName("Test", 1.f, [](auto){})
		.sizeMult(7.f)
		.sprite(cocos2d::CCSprite::create())
		.updateSprite()
		.animType(MenuAnimationType::Move)
		.scaleMult(4.f)
		.baseScale(3.f)
		.animEnabled(true)
		.colorEnabled(true)
		.soundVolume(3.f)
		.activateSound("test")
		.colorDip(.4f)
		.iconType(IconType::Ball);

	Make<CCMenuItemToggler>::createCB(cocos2d::CCNode::create(), cocos2d::CCNode::create(), [](auto){});
	Make<CCMenuItemToggler>::createFileName("Test", "Test", 1.f, [](auto){});
	Make<CCMenuItemToggler>::createFrameName("Test", "Test", 1.f, [](auto){});
	Make<CCMenuItemToggler>::createStandard(1.f, [](auto){})
		.clickable(true)
		.sizeMult(.4f)
		.updateSprite()
		.toggle(true, false)
		.withOnBtn([](Make<CCMenuItemSpriteExtra> btn) {
			btn.visible(true);
		})
		.withOnBtn([](Make<CCMenuItemSpriteExtra> btn) {
			btn.visible(true);
		})
		.withOffBtn([](Make<CCMenuItemSpriteExtra> btn) {
			btn.visible(true);
		})
		.withOffBtn([](Make<CCMenuItemSpriteExtra> btn) {
			btn.visible(true);
		});

	// SimplePlayer
	Make<SimplePlayer>::create(1)
		.loadAsync(5, IconType::Cube)
		.createRobot(6)
		.createSpider(7)
		.hideAll()
		.hideSecondary()
		.colors(cocos2d::ccColor3B{3, 4, 5}, cocos2d::ccColor3B{3, 4, 5})
		.frames("test", "test2", "test3", "test4", "test5")
		.glowColor(cocos2d::ccColor3B{3, 4, 5})
		.disableGlowColor()
		.glowOutline(cocos2d::ccColor3B{3, 4, 5})
		.disableGlowOutline()
		.secondColor(cocos2d::ccColor3B{3, 4, 5})
		.tryGlowColor(5)
		.updateColors()
		.updateFrame(9, IconType::Ball);

	// Border
	Make<geode::Border>::create(cocos2d::CCNode::create(), cocos2d::ccColor4B{3, 4, 5, 6})
		.padding(cocos2d::CCPoint{3.f, 4.f})
		.padding(3.f, 4.f)
		.padding(3.f)
		.paddingX(3.f)
		.paddingY(4.f)
		.paddingTop(5.f)
		.paddingRight(4.f)
		.paddingBottom(3.f)
		.paddingLeft(2.f)
		.bgColor(cocos2d::ccColor4B{3, 4, 5, 6})
		.node(cocos2d::CCNode::create())
		.withNode([](Make<cocos2d::CCNode> node) {
			node.visible(true);
		})
		.withNodeCast<cocos2d::CCMenu>([](Make<cocos2d::CCMenu> node) {
			node.visible(true);
		})
		.bSize(cocos2d::CCPoint{5.f, 4.f})
		.bSize(5.f, 4.f);

	// Button

	Make<geode::Button>::createNode(cocos2d::CCNode::create());
	Make<geode::Button>::createFileName("test.png");
	Make<geode::Button>::createFrameName("test.png");
	Make<geode::Button>::createLabel("Test", "test.fnt", [](auto){})
		.displayNode(cocos2d::CCNode::create())
		.animType(geode::Button::AnimationType::Custom)
		.clickAnim(cocos2d::CCMoveTo::create(.3f, cocos2d::CCPoint{3, 3}))
		.releaseAnim(cocos2d::CCMoveTo::create(.3f, cocos2d::CCPoint{3, 3}))
		.setOnActivate([](auto){})
		.setOnSelect([](auto){})
		.setOnUnselect([](auto){})
		.onActivate("test", [](auto, auto){}, 7)
		.onSelect("test", [](auto, auto){}, 7)
		.onUnselect("test", [](auto, auto){}, 7)
		.touchPrio(7)
		.touchMult(8)
		.scaleMult(6)
		.moveOffset(cocos2d::CCPoint{30, 40})
		.moveOffset(30.f, 40.f)
		.selectDuration(4)
		.unselectDuration(3)
		.enable(true)
		.withDisplayNode([](Make<cocos2d::CCNode> node) {
			node.visible(true);
		})
		.withDisplayNodeCast<cocos2d::CCSprite>([](Make<cocos2d::CCSprite> node) {
			node.visible(true);
		});

	// BoxedLabel

	Make<geode::BoxedLabel>::create("test", "test.fnt")
		.text("hi")
		.font("yo.fnt")
		.textScale(.5f)
		.align(geode::Label::Alignment::Center)
		.maxWidth(40.f)
		.padding(100.f)
		.boxSprite("test.png")
		.boxOpacity(40.f)
		.boxScale(.6f)
		.lockWidth(true)
		.withLabel([](Make<geode::Label> lab) {
			lab.text("hi");
		})
		.withBox([](Make<geode::NineSlice> bg) {
			bg.visible("hi");
		});

	// Label
	Make<geode::Label>::createRich("Hi", "Hi.fnt");
	Make<geode::Label>::createRich("Hi", geode::BitmapFont::load("test.fnt"))
		.textDirty(true)
		.layoutDirty(true)
		.quadsDirty(true)
		.addFont(geode::BitmapFont::load("test.fnt"))
		.addFont("test.fnt")
		.removeFont(1)
		.removeFont("test.fnt")
		.setFont("test.fnt")
		.setFont(geode::BitmapFont::load("test.fnt"))
		.text("Hi")
		.richText("Hi")
		.richTextEnabled(true)
		.align(geode::Label::Alignment::Center)
		.maxWidth(100.f)
		.breakWords(true)
		.limitWidth(50.f)
		.limitHeight(50.f)
		.limitSize({50.f, 50.f})
		.removeSizeLimit()
		.fitBox({30.f, 50.f})
		.extraKern(40.f)
		.lineSpace(50.f)
		.charColor(30, cocos2d::ccColor4B{30, 45, 60, 75})
		.emojiReg(geode::EmojiRegistry::vanillaEmojis())
		.colorEmojis(true)
		.colorNodes(true)
		.disableEmojis();

	// Layouts / LayoutOptions
	Make<geode::AxisLayout>::create()
		.apply(cocos2d::CCScene::get())
		.axis(geode::Axis::Column)
		.align(geode::AxisAlignment::Center)
		.crossAlign(geode::AxisAlignment::Center)
		.gap(30.f)
		.reverse(true)
		.crossReverse(true)
		.autoScale(true)
		.growCross(true)
		.crossOverflow(true)
		.autoGrow(3.f)
		.defaultScaleLimits(3.f, 4.f)
		.ignoreInvisible(true)
		.padding(geode::Padding{3.f, 4.f, 5.f, 6.f})
		.padding(3.f, 4.f, 5.f, 6.f)
		.useBoundingBox(true);

	Make<geode::CopySizeLayout>::create()
		.add(cocos2d::CCScene::get())
		.remove(cocos2d::CCScene::get());

	Make<geode::SimpleAxisLayout>::create(geode::Axis::Column)
		.axis(geode::Axis::Column)
		.scaling(geode::AxisScaling::Fit)
		.crossScaling(geode::AxisScaling::Fit)
		.align(geode::MainAxisAlignment::Between)
		.crossAlign(geode::CrossAxisAlignment::Center)
		.dir(geode::AxisDirection::BackToFront)
		.crossDir(geode::AxisDirection::BottomToTop)
		.gap(3.f)
		.minRelScale(4.f)
		.maxRelScale(5.f)
		.ignoreInvisible(true)
		.padding(geode::Padding{3.f, 4.f, 5.f, 6.f})
		.padding(3.f, 4.f, 5.f, 6.f)
		.useBoundingBox(true);

	Make<geode::AxisLayoutOptions>::create()
		.scaleLimits(4.f, 5.f)
		.relativeScale(3.f)
		.autoScale(5.f)
		.length(6.f)
		.prevGap(7.f)
		.nextGap(4.f)
		.breakLine(true)
		.sameLine(true)
		.scalePrio(400)
		.crossAlign(geode::AxisAlignment::Between);

	Make<geode::AnchorLayoutOptions>::create()
		.anchor(geode::Anchor::Bottom)
		.offset(30.f, 50.f)
		.offset(cocos2d::CCPoint{30.f, 50.f});

	Make<geode::SimpleAxisLayoutOptions>::create()
		.minRelScale(5.f)
		.maxRelScale(5.f)
		.scalePrio(geode::ScalingPriority::Early);

	Make<geode::AxisGap>::create(5.f)
		.gap(4.f);

	Make<geode::NineSlice>::createFrame(cocos2d::CCSpriteFrameCache::get()->spriteFrameByName("Test.png"));
	Make<geode::NineSlice>::createFrameName("test.png")
		.scaleMult(5.f)
		.repeatCenter(true)
		.insets(geode::NineSlice::Insets{3.f, 4.f, 5.f, 7.f})
		.insets(3.f, 4.f, 6.f, 5.f)
		.insetTop(4.f)
		.insetRight(4.f)
		.insetBottom(4.f)
		.insetLeft(4.f);

	Make<geode::ProgressBar>::create()
		.style(geode::ProgressBar::Style::Level)
		.fillColor(cocos2d::ccColor3B{30, 40, 30})
		.precision(30)
		.progress(30.f)
		.progress(30.f, 20.f)
		.stopAnim()
		.showLabel(true)
		.withProgressLabel([](Make<geode::Label> lab) {
			lab.visible(true);
		})
		.withBarFill([](Make<cocos2d::CCSprite> bg) {
			bg.visible(true);
		});

	auto scroll = Make<geode::ScrollLayer>::create(cocos2d::CCPoint{30.f, 50.f})
		.enableScrollWheel(true)
		.scrollToTop()
		.scrollFromTop(4.f)
		.cancelTouchLimit(4)
		.stealTouches(true)
		.defaultLayout()
		.withContentLayer([](Make<geode::GenericContentLayer> layer) {
			layer.visible(true);
		})
		.createScrollbar(cocos2d::CCScene::get(), cocos2d::CCPoint{30.f, 40.f})
		.createScrollbar(cocos2d::CCScene::get(), geode::Anchor::Left, cocos2d::CCPoint{30.f, 40.f}, [](Make<geode::Scrollbar> bar) {
			bar.visible(true);
		})
		.withClippingNode([](Make<cocos2d::CCClippingNode> node) {
			node.visible(true);
		})
		.enableTouchClipping(true)
		.enableScrollClipping(true)
		.stencil(cocos2d::CCScene::get())
		.withStencil([](Make<cocos2d::CCNode> stencil) {
			stencil.visible(true);
		})
		.withStencilCast<cocos2d::CCSprite>([](Make<cocos2d::CCSprite> stencil) {
			stencil.visible(true);
		});

	Make<geode::Scrollbar>::create(scroll)
		.target(scroll)
		.track(geode::NineSlice::create("test"))
		.thumb(geode::NineSlice::create("test"))
		#ifdef SCROLLBAR_CHANGES_MERGED
		.overscrollShrink(true)
		.touchInThumb(true)
		.style(geode::Scrollbar::Style::Geode)
		.thumbColors(cocos2d::ccColor4B{30, 40, 50, 60}, cocos2d::ccColor4B{30, 40, 50, 60})
		#endif
		.withTarget([](Make<CCScrollLayerExt> scroll) {
			scroll.visible(true);
		})
		.withTargetCast<geode::ScrollLayer>([](Make<geode::ScrollLayer> scroll) {
			scroll.visible(true);
		})
		.withTrack([](Make<geode::NineSlice> track) {
			track.visible(true);
		})
		.withThumb([](Make<geode::NineSlice> thumb) {
			thumb.visible(true);
		});

	Make<geode::SliderNode>::createCustom(cocos2d::CCSprite::create(), cocos2d::CCSprite::create(), geode::NineSlice::create(""), "test", [](auto, auto){})
		.setSlideCallback([](auto, auto){})
		.setClickCallback([](auto, auto){})
		.setReleaseCallback([](auto, auto){})
		.slideCallback("", [](auto, auto, auto){}, 4)
		.clickCallback("", [](auto, auto, auto){}, 4)
		.releaseCallback("", [](auto, auto, auto){}, 4)
		.min(5.f)
		.max(5.f)
		.enabled(true)
		.value(5.f)
		.percent(5.f)
		.snapStep(4.f)
		.linkInput(geode::TextInput::create(50.f, "hi"), 5)
		.unlinkInput()
		.inputPrecision(5)
		.linkLabel(geode::Label::create("hi", "bigFont.fnt"), 5)
		.labelPrecision(5)
		.readOnly(true)
		.bypass(true)
		.touchPrio(true);

	auto mdconfig = NPMake<geode::MDConfig>()
		.regFont(geode::BitmapFont::load("test"))
		.boldFont(geode::BitmapFont::load("test"))
		.italicFont(geode::BitmapFont::load("test"))
		.boldItalicFont(geode::BitmapFont::load("test"))
		.monoFont(geode::BitmapFont::load("test"))
		.fontScale(5.f)
		.headingScale({5, 5, 5, 4, 3})
		.headingScale(5, 3.f)
		.linkColor(cocos2d::ccColor3B{7, 7, 7})
		.linkActiveColor(cocos2d::ccColor3B{7, 7, 7})
		.paragraphSpacing(3.f)
		.listIndent(5)
		.listBulletMarker("hi")
		.listOrderedSeparator("hi")
		.listMarkerOpacity(53)
		.codeBlockIndent(5.f)
		.codeBlockPadding(5.f)
		.codeBlockBgScale(5.f)
		.codeBlockBgOpacity(5)
		.codeBlockBgColor(cocos2d::ccColor3B{30, 40, 50})
		.codeSpanBgScale(5.f)
		.codeSpanBgExtraWidth(5.f)
		.codeSpanBgOffsetY(5.f)
		.codeSpanTextOffsetY(5.f)
		.codeSpanBgOpacity(5)
		.codeSpanBgColor(cocos2d::ccColor3B{30, 40, 50})
		.hrPaddingAfter(3.f)
		.hrPaddingAfter(3.f)
		.imageDefaultScale(5.f)
		.imageMinScale(5.f)
		.imageMaxDim(5.f)
		.blockQuoteIndent(5.f)
		.blockQuoteRuleWidth(5.f)
		.blockQuoteRuleColor(cocos2d::ccColor3B{30, 40, 50})
		.tableCellPadding(5.f)
		.tableBorderWidth(5.f)
		.tableHeaderBgOpacity(5)
		.tableBorderColor(cocos2d::ccColor3B{30, 40, 50})
		.tableHeaderBgColor(cocos2d::ccColor3B{30, 40, 50});

	Make<geode::MDTextArea>::create("Test", 5.f, std::move(mdconfig.move()))
		.updateLabel()
		.text("test")
		.withScroll([](Make<geode::ScrollLayer> scroll) {
			scroll.visible(true);
		})
		.scrollToTop();

	Make<geode::SimpleTextArea>::create("test")
		.font("test.fnt")
		.color(cocos2d::ccColor4B{30, 40, 50, 60})
		.align(cocos2d::CCTextAlignment::kCCTextAlignmentLeft)
		.wrappingMode(geode::WORD_WRAP)
		.text("test")
		.maxLines(5)
		.areaWidth(50.f)
		.linePadding(50.f);

	Make<geode::TextInput>::createMultiline(cocos2d::CCSize{30.f, 40.f}, "hi")
		.placeholder("Hi")
		.placeholderColor(cocos2d::ccColor4B{30, 40, 50, 60})
		.selectColor(cocos2d::ccColor4B{30, 40, 50, 60})
		.caretColor(cocos2d::ccColor4B{30, 40, 50, 60})
		.caretWidth(50.f)
		.textColor(cocos2d::ccColor4B{30, 40, 50, 60})
		.padding(cocos2d::CCPoint{50.f, 50.f})
		.padding(50.f, 50.f)
		.align(geode::Label::Alignment::Left)
		.filter("hi")
		.filter(geode::CommonFilter::Any)
		.label("Hi")
		.maxChars(40)
		.passwordMode(true)
		.numberMode(true)
		.multiline(true)
		.enabled(true)
		.wrap(true)
		.overflow(geode::TextInput::OverflowMode::Clip)
		.fontScale(40.f)
		.placeholderScale(4.f)
		.emojis(true)
		.hideBG()
		.setOnInput([](const auto&){})
		.setOnEnter([](const auto&){})
		.setOnFocus([](auto){})
		.onInput("", [](const auto&){}, 5)
		.onFocus("", [](auto, auto){}, 5)
		.onUnfocus("", [](auto, auto){}, 5)
		.text("Hi")
		.cursorPos(3)
		.select(3, 4)
		.focus()
		.unfocus()
		.withContentLabel([](Make<geode::Label> lab) {
			lab.visible(true);
		})
		.withPlaceholderLabel([](Make<geode::Label> lab) {
			lab.visible(true);
		})
		.withCaptionLabel([](Make<geode::Label> lab) {
			lab.visible(true);
		})
		.withBG([](Make<geode::NineSlice> ns) {
			ns.visible(true);
		});

	Make<geode::Toggler>::createStandard();
	Make<geode::Toggler>::createStandard(5.f);
	Make<geode::Toggler>::createFileNames("test", "test");
	Make<geode::Toggler>::createFileNames("test", "test", 5.f);
	Make<geode::Toggler>::createFrameNames("test", "test");
	Make<geode::Toggler>::createFrameNames("test", "test", 5.f)
		.toggle(true, false)
		.offNode(cocos2d::CCNode::create())
		.onNode(cocos2d::CCNode::create())
		.setOnToggle([](auto, auto) {})
		.onToggle("", [](auto, auto) {})
		.withOnNode([](Make<cocos2d::CCNode> node) {
			node.visible(true);
		})
		.withOnNodeCast<cocos2d::CCSprite>([](Make<cocos2d::CCSprite> node) {
			node.visible(true);
		})
		.withOffNode([](Make<cocos2d::CCNode> node) {
			node.visible(true);
		})
		.withOffNodeCast<cocos2d::CCSprite>([](Make<cocos2d::CCSprite> node) {
			node.visible(true);
		});

	Make<cocos2d::CCNode>::create()
		.sideArt(geode::SideArt::All, false)
		.sideArt(geode::SideArt::All, geode::SideArtStyle::LayerGray, false)
		.listBorders({30.f, 30.f}, {40.f, 40.f})
		.backButton()
		.backButton([](auto){})
		.with([](cocos2d::CCNode* node) {
			node->setVisible(true);
		});

	Make<FLAlertLayer>::create("hi", "hi2", "hi3").show();
}