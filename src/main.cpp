#include <Geode/Geode.hpp>
#include <Geode/modify/EditorPauseLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/FLAlertLayer.hpp>
#include <Geode/modify/GJDropDownLayer.hpp>
#include <Geode/modify/OptionsLayer.hpp>
#include <Geode/modify/InfoLayer.hpp>
#include <Geode/modify/ShardsPage.hpp>
#include <Geode/modify/RewardsPage.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/modify/DailyLevelPage.hpp>
#include <Geode/modify/ChallengesPage.hpp>
#include <Geode/modify/HSVWidgetPopup.hpp>
#include <Geode/modify/GJOptionsLayer.hpp>
#include "CCBlurLayer.hpp"

using namespace geode::prelude;

class $modify (PauseLayer)
{
	void customSetup()
	{
		PauseLayer::customSetup();

		auto blur = CCBlurLayer::create();
		blur->setZOrder(-69);
		blur->setOpacity(255);

		this->addChild(blur);
	}
};

class $modify (EditorPauseLayer)
{
	void customSetup()
	{
		EditorPauseLayer::customSetup();

		Loader::get()->queueInMainThread([this] {
			auto blur = CCBlurLayer::create();
			blur->setZOrder(-69);
			blur->setOpacity(255);

			this->addChild(blur);
		});
	}
};

class $modify (FLAlertLayerExt, FLAlertLayer)
{

    struct Fields {
        FLAlertLayerExt* self;
		CCBlurLayer* blur;		
    };

	virtual void show()
	{
		FLAlertLayer::show();

		if (!m_fields->blur)
		{
			m_fields->blur = CCBlurLayer::create();
			m_fields->blur->setZOrder(-69);
			if (typeinfo_cast<MessagesProfilePage*>(this) || typeinfo_cast<FriendsProfilePage*>(this) || typeinfo_cast<FRequestProfilePage*>(this))
				m_fields->blur->setOpacity(255);
			else
				m_fields->blur->runAction(CCFadeTo::create(0.5f, 255));

			this->addChild(m_fields->blur);
		}
	}
};

class $modify (GJDropDownLayer)
{
    struct Fields{
        GJDropDownLayer* self;
		CCBlurLayer* blur;		
    };

	virtual void showLayer(bool p0)
	{
		GJDropDownLayer::showLayer(p0);

		if (!m_fields->blur)
		{
			m_fields->blur = CCBlurLayer::create();
			m_fields->blur->setZOrder(-69);
			m_fields->blur->runAction(CCFadeTo::create(2, 255));

			this->addChild(m_fields->blur);
		}
	}

	virtual void hideLayer(bool p0)
	{
		GJDropDownLayer::hideLayer(p0);

		if (m_fields->blur)
			m_fields->blur->runAction(CCFadeTo::create(2, 0));
	}

	virtual void exitLayer(cocos2d::CCObject* p0)
	{
		GJDropDownLayer::exitLayer(p0);

		if (m_fields->blur)
			m_fields->blur->runAction(CCFadeTo::create(2, 0));
	}
};

class $modify (InfoLayer)
{
    struct Fields {
        InfoLayer* self;
		CCBlurLayer* blur;		
    };

	virtual void show()
	{
		InfoLayer::show();

		if (!m_fields->blur)
		{
			m_fields->blur = CCBlurLayer::create();
			m_fields->blur->setZOrder(-69);
			m_fields->blur->runAction(CCFadeTo::create(0.5f, 255));

			this->addChild(m_fields->blur);
		}
	}
};

class $modify (ChallengesPage)
{
    struct Fields {
        ChallengesPage* self;
		CCBlurLayer* blur;		
    };

	virtual void show()
	{
		ChallengesPage::show();

		if (!m_fields->blur)
		{
			m_fields->blur = CCBlurLayer::create();
			m_fields->blur->setZOrder(-69);
			m_fields->blur->runAction(CCFadeTo::create(0.5f, 255));

			this->addChild(m_fields->blur);
		}
	}
};

class $modify (HSVWidgetPopup)
{
    struct Fields {
        HSVWidgetPopup* self;
		CCBlurLayer* blur;		
    };

	virtual void show()
	{
		HSVWidgetPopup::show();

		if (!m_fields->blur)
		{
			m_fields->blur = CCBlurLayer::create();
			m_fields->blur->setZOrder(-69);
			m_fields->blur->runAction(CCFadeTo::create(0.5f, 255));

			this->addChild(m_fields->blur);
		}
	}
};

class $modify (ProfilePage)
{
    struct Fields {
        ProfilePage* self;
		CCBlurLayer* blur;		
    };

	virtual void show()
	{
		ProfilePage::show();

		if (!m_fields->blur && !getChildByType<CCBlurLayer>(0))
		{
			m_fields->blur = CCBlurLayer::create();
			m_fields->blur->setZOrder(-69);
			m_fields->blur->runAction(CCFadeTo::create(0.5f, 255));

			this->addChild(m_fields->blur);
		}
	}
};

class $modify (RewardsPage)
{
    struct Fields {
        RewardsPage* self;
		CCBlurLayer* blur;		
    };

	virtual void show()
	{
		RewardsPage::show();

		if (!m_fields->blur)
		{
			m_fields->blur = CCBlurLayer::create();
			m_fields->blur->setZOrder(-69);
			m_fields->blur->runAction(CCFadeTo::create(0.5f, 255));

			this->addChild(m_fields->blur);
		}
	}
};

class $modify (DailyLevelPage)
{
    struct Fields {
        DailyLevelPage* self;
		CCBlurLayer* blur;		
    };

	virtual void show()
	{
		DailyLevelPage::show();

		if (!m_fields->blur)
		{
			m_fields->blur = CCBlurLayer::create();
			m_fields->blur->setZOrder(-69);
			m_fields->blur->runAction(CCFadeTo::create(0.5f, 255));

			this->addChild(m_fields->blur);
		}
	}
};

class $modify (GJOptionsLayer)
{
    struct Fields {
        GJOptionsLayer* self;
		CCBlurLayer* blur;		
    };

	virtual void show()
	{
		GJOptionsLayer::show();

		if (!m_fields->blur)
		{
			m_fields->blur = CCBlurLayer::create();
			m_fields->blur->setZOrder(-69);
			m_fields->blur->runAction(CCFadeTo::create(0.5f, 255));

			this->addChild(m_fields->blur);
		}
	}
};
