#include <Geode/Geode.hpp>
#include "CCBlurLayer.hpp"

#define SHOULD_PLACE_LAYER !this->getChildByType<CCBlurLayer>(0) && Mod::get()->getSettingValue<bool>("switch")

using namespace geode::prelude;

#include <Geode/modify/PauseLayer.hpp>
class $modify (MyPauseLayer, PauseLayer) {
	struct Fields {
		CCBlurLayer* m_blur = nullptr;
	};
	void customSetup() {
		PauseLayer::customSetup();
		if (SHOULD_PLACE_LAYER) {
			auto blur = CCBlurLayer::create();
			blur->setID("pause-blur-layer");
			blur->setZOrder(-69);
			blur->runAction(CCFadeTo::create(0.5f, 255));
			this->addChild(blur);
			m_fields->m_blur = blur;

			auto spr = CCSprite::create("logo.png"_spr);
			spr->setScale(0.32);
			auto btn = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MyPauseLayer::onHideBlur));
			if (auto menu = this->getChildByID("left-button-menu"))
				menu->addChild(btn);
		}
	}
	void onHideBlur(CCObject*) {
		if (m_fields->m_blur->getOpacity())
			m_fields->m_blur->runAction(CCEaseExponentialOut::create(CCFadeOut::create(0.5f)));
		else
			m_fields->m_blur->runAction(CCFadeIn::create(0.5f));
	}
};

#include <Geode/modify/EditorPauseLayer.hpp>
class $modify (EditorPauseLayer) {
	void customSetup() {
		EditorPauseLayer::customSetup();
		Loader::get()->queueInMainThread([this] {
			if (SHOULD_PLACE_LAYER) {
				auto blur = CCBlurLayer::create();
				blur->setID("editor-pause-blur-layer");
				blur->setZOrder(-69);
				blur->setOpacity(255);
				this->addChild(blur);				
			}
		});
	}
};

#include <Geode/modify/FLAlertLayer.hpp>
class $modify (FLAlertLayerExt, FLAlertLayer) {
	virtual void show() {
		FLAlertLayer::show();
		if (SHOULD_PLACE_LAYER) {
			auto blur = CCBlurLayer::create();
			blur->setID("alert-blur-layer");
			blur->setZOrder(-69);
			if (typeinfo_cast<ProfilePage*>(this) || typeinfo_cast<MessagesProfilePage*>(this) || typeinfo_cast<FriendsProfilePage*>(this) || typeinfo_cast<FRequestProfilePage*>(this))
				blur->setOpacity(255);
			else
				blur->runAction(CCFadeTo::create(0.5f, 255));
			this->addChild(blur);
		}
	}
};

#include <Geode/modify/GJDropDownLayer.hpp>
class $modify (GJDropDownLayer) {
	virtual void showLayer(bool p0) {
		GJDropDownLayer::showLayer(p0);

		if (SHOULD_PLACE_LAYER) {
			auto blur = CCBlurLayer::create();
			blur->setID("drop-down-blur-layer");
			blur->setZOrder(-69);
			blur->runAction(CCFadeTo::create(2, 255));
			this->addChild(blur);
		}
	}

	virtual void hideLayer(bool p0) {
		GJDropDownLayer::hideLayer(p0);
		if (auto blur = this->getChildByType<CCBlurLayer>(0))
			blur->runAction(CCFadeTo::create(2, 0));
	}

	virtual void exitLayer(cocos2d::CCObject* p0) {
		GJDropDownLayer::exitLayer(p0);
		if (auto blur = this->getChildByType<CCBlurLayer>(0))
			blur->runAction(CCFadeTo::create(2, 0));
	}
};

#include <Geode/modify/InfoLayer.hpp>
class $modify (InfoLayer) {
	virtual void show() {
		InfoLayer::show();
		if (SHOULD_PLACE_LAYER) {
			auto blur = CCBlurLayer::create();
			blur->setID("info-blur-layer");
			blur->setZOrder(-69);
			blur->runAction(CCFadeTo::create(0.5f, 255));
			this->addChild(blur);
		}
	}
};

#include <Geode/modify/ChallengesPage.hpp>
class $modify (ChallengesPage) {
	virtual void show() {
		ChallengesPage::show();
		if (SHOULD_PLACE_LAYER) {
			auto blur = CCBlurLayer::create();
			blur->setID("challenge-blur-layer");
			blur->setZOrder(-69);
			blur->runAction(CCFadeTo::create(0.5f, 255));
			this->addChild(blur);
		}
	}
};

#include <Geode/modify/HSVWidgetPopup.hpp>
class $modify (HSVWidgetPopup) {
	virtual void show() {
		HSVWidgetPopup::show();
		if (SHOULD_PLACE_LAYER) {
			auto blur = CCBlurLayer::create();
			blur->setID("hsv-blur-layer");
			blur->setZOrder(-69);
			blur->runAction(CCFadeTo::create(0.5f, 255));

			this->addChild(blur);
		}
	}
};

#include <Geode/modify/RewardsPage.hpp>
class $modify (RewardsPage) {
	virtual void show() {
		RewardsPage::show();

		if (SHOULD_PLACE_LAYER) {
			auto blur = CCBlurLayer::create();
			blur->setID("rewards-blur-layer");
			blur->setZOrder(-69);
			blur->runAction(CCFadeTo::create(0.5f, 255));
			this->addChild(blur);
		}
	}
};

#include <Geode/modify/DailyLevelPage.hpp>
class $modify (DailyLevelPage) {
	virtual void show() {
		DailyLevelPage::show();
		if (SHOULD_PLACE_LAYER) {
			auto blur = CCBlurLayer::create();
			blur->setID("daily-blur-layer");
			blur->setZOrder(-69);
			blur->runAction(CCFadeTo::create(0.5f, 255));
			this->addChild(blur);
		}
	}
};


#include <Geode/modify/GJOptionsLayer.hpp>
class $modify (GJOptionsLayer) {
	virtual void show() {
		GJOptionsLayer::show();
		if (SHOULD_PLACE_LAYER) {
			auto blur = CCBlurLayer::create();
			blur->setID("options-blur-layer");
			blur->setZOrder(-69);
			blur->runAction(CCFadeTo::create(0.5f, 255));
			this->addChild(blur);
		}
	}
};

#include <Geode/modify/SetupTriggerPopup.hpp>
class $modify (SetupTriggerPopup) {
	virtual bool init(EffectGameObject *trigger, cocos2d::CCArray *triggers, float width, float height, int unkEnum) {
		if (!SetupTriggerPopup::init(trigger, triggers, width, height, unkEnum)) return false;
		if (SHOULD_PLACE_LAYER) {
			auto blur = CCBlurLayer::create();
			blur->setID("setup-trigger-blur-layer");
			blur->setZOrder(-69);
			blur->runAction(CCFadeTo::create(0.5f, 255));
			this->addChild(blur);
		}
		return true;
	}
};

#include <Geode/modify/SetTextPopup.hpp>
class $modify (SetTextPopup) {
	virtual void show() {
		SetTextPopup::show();
		if (SHOULD_PLACE_LAYER) {
			auto blur = CCBlurLayer::create();
			blur->setID("set-text-blur-layer");
			blur->setZOrder(-69);
			blur->runAction(CCFadeTo::create(0.5f, 255));
			this->addChild(blur);
		}
	}
};