/*
 * AboutScene.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
		Edit: long
 */

#include "AboutScene.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include "AudioManager.h"

USING_NS_CC;
using namespace CocosDenshion;

AboutScene::AboutScene()
{
}

AboutScene::~AboutScene()
{

}

CCScene* AboutScene::scene()
{
	CCScene *scene = CCScene::create();
	AboutScene *layer = AboutScene::create();
	scene->addChild(layer);
	return scene;
}


bool AboutScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	//init here
	CCSize s = CCDirector::sharedDirector()->getWinSize();

	//background
	CCSprite* sprBackground;
	sprBackground = CCSprite::create("background1.png");
	sprBackground->setPosition(ccp(s.width/2, s.height/2));
	addChild(sprBackground);

	//logo
	CCSprite* sprLogo = CCSprite::create("imgLogo.png");
	sprLogo->setPosition(ccp(s.width/2, 860));
	addChild(sprLogo);

	//text
	CCLabelBMFont* gameName = CCLabelBMFont::create("Mind Boxz", "idevice_r_50.fnt");
	CCLabelBMFont* teamName = CCLabelBMFont::create("GameUit team", "idevice_r_50.fnt");
	CCLabelBMFont* version = CCLabelBMFont::create("Version 1.0.0", "idevice_r_50.fnt");

	gameName->setPosition(ccp(s.width/2, s.height/2));
	teamName->setPosition(ccp(s.width/2, s.height/2 - 70));
	version->setPosition(ccp(s.width/2, s.height/2 - 140));

	addChild(gameName);
	addChild(teamName);
	addChild(version);

	//menu
	CCMenuItemImage* itemBack = CCMenuItemImage::create("btn_home.png", "btn_home.png", this, menu_selector(AboutScene::gotoMenu) );
	//CCLabelBMFont* back = CCLabelBMFont::create("Back", "idevice_r_50.fnt");

	itemBack->setPosition(0, - s.height/2 + 70);
	//back->setPosition(s.width/2, 75);

	CCMenu* menu = CCMenu::create(itemBack, NULL);

	addChild(menu);
	//addChild(back);

	//
	return true;
}

void AboutScene::gotoMenu(CCObject* sender)
{
	//
	AudioManager::sharedAudioManager()->PlayEffect("sndButton.wav", 0);
	//

	CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
}

