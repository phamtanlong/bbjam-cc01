/*
 * SplashScene.cpp
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 *		Edit: Long
 */

#include "SplashScene.h"
#include "AudioManager.h"
#include "GameConstant.h"
#include "MainGameScene.h"
#include "LoadingScene.h"
#include "MenuScene.h"
#include "GameData.h"

USING_NS_CC;
using namespace CocosDenshion;

SplashScene::SplashScene()
{
}

SplashScene::~SplashScene()
{
}

bool SplashScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	//GameData::sharedGameData()->readLevel();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	this->setTouchEnabled(true);

	CCSize s = CCDirector::sharedDirector()->getWinSize();

	//background

	//logo
	this->m_SprLogo = CCSprite::create("imgLogo.png");	
	m_SprLogo->setPosition(ccp(WIDTH >> 1, HEIGHT >> 1));

	//box
	m_SprBox[0] = CCSprite::create("megaboxz.png");
	m_SprBox[1] = CCSprite::create("rockboxz.png");
	m_SprBox[2] = CCSprite::create("spiderboxz.png");

	addChild(m_SprLogo, 2);
	addChild(m_SprBox[0], 9);
	addChild(m_SprBox[1], 9);
	addChild(m_SprBox[2], 9);	

	for (int i = 0; i < 3; ++i)
	{
		m_SprBox[i]->setPosition(ccp(WIDTH/2 + (i - 1) * 91, HEIGHT + 91));
	}
	
	//action
	CCFiniteTimeAction*  actionLogo = CCSequence::create(
		CCScaleBy::create(0.3, 1.2, 1.2),
		CCScaleTo::create(0.3, 1, 1),
		CCCallFuncN::create( this, callfuncN_selector(SplashScene::fallBlock) ),
		NULL);

	m_SprLogo->runAction(actionLogo);

	return true;
}

void SplashScene::fallBlock(CCNode* sender)
{
	scheduleUpdate();
	
	//preload background music
	AudioManager::sharedAudioManager()->LoadBackground("sndMenu.wav");
	AudioManager::sharedAudioManager()->LoadBackground("sndGame.wav");
}

void SplashScene::update(float delta)
{
	int i = -1;
	static float localTime = 0;

	if(localTime == 0)
	{
		i = 0;
	}

	if(localTime < 0.5 && localTime + delta >= 0.5)
	{
		i = 1;
		CCSprite* nut1 = CCSprite::create("scratch_1.png");
		nut1->setPosition(ccp(WIDTH/2 + 30, HEIGHT/2 + 30));
		addChild(nut1, 8);
	}

	if(localTime < 1  && localTime + delta >= 1)
	{
		i = 2;
		CCSprite* nut2 = CCSprite::create("scratch_2.png");
		nut2->setPosition(ccp(WIDTH/2 - 40, HEIGHT/2 - 40));
		addChild(nut2, 8);
	}

	localTime += delta;

	if(i >= 0 && i <= 2)
	{
		CCMoveTo* move1 = CCMoveTo::create(0.3, ccp(WIDTH/2, HEIGHT/2 + 306 / 2));
		CCAction*  jump5 = CCSpawn::create(
			CCJumpTo::create(0.6, //th?i gian r�i
			CCPointMake(WIDTH/2 + (i-1)*200, HEIGHT/2 - 306 / 2), //v? tr� r�i t?i
			120, //chi?u cao nh?y l�n tr�?c khi r�i
			1), //s? l?n bounce
			CCRotateBy::create(0.6, 180 * (i + 1)),
			NULL);

		CCAction*  jump6 = CCSpawn::create(
			CCJumpTo::create(0.4 + (i+1)*0.4, //th?i gian r�i
			CCPointMake(WIDTH/2 + (i-1)*200, HEIGHT/2 - 306 / 2), //v? tr� r�i t?i
			90, //chi?u cao nh?y l�n tr�?c khi r�i
			2), //s? l?n bounce
			CCRotateBy::create(0.4 + (i+1)*0.4, (i+1)*180),
			NULL);

		//CCAction*  jump7 = CCSpawn::create(
		//	CCJumpTo::create(0.6, //th?i gian r�i
		//	CCPointMake(WIDTH/2 + (i-1)*200, HEIGHT/2 - 306 / 2), //v? tr� r�i t?i
		//	60, //chi?u cao nh?y l�n tr�?c khi r�i
		//	1), //s? l?n bounce
		//	CCRotateBy::create(0.6, 360),
		//	NULL);
		
		CCAction*  jump8 = CCSpawn::create(
			CCJumpTo::create(0.4, //th?i gian r�i
			CCPointMake(WIDTH/2 + (i-1)*200, HEIGHT/2 - 306 / 2), //v? tr� r�i t?i
			30, //chi?u cao nh?y l�n tr�?c khi r�i
			1), //s? l?n bounce
			CCRotateBy::create(0.4, 180),
			NULL);

		if(i != 2)
		{
			CCFiniteTimeAction*  frequence = CCSequence::create(
				move1,
				jump5,
				jump6,
				//jump7,
				jump8,
				NULL);
			m_SprBox[i]->runAction(frequence);
		}
		else
		{
			CCFiniteTimeAction*  frequence = CCSequence::create(
				move1,
				jump5,
				jump6,
				//jump7,
				jump8,
				CCCallFuncN::create( this, callfuncN_selector(SplashScene::gotoMenu) ),
				NULL);
			m_SprBox[i]->runAction(frequence);
		}		
	}	
}

void SplashScene::gotoMenu(CCNode* sender)
{	
	CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
}

CCScene* SplashScene::scene()
{
	CCScene *scene = CCScene::create();
	SplashScene *layer = SplashScene::create();
	scene->addChild(layer);
	return scene;
}


bool SplashScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLog("SplashScene: touchdown");
	//CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
	return true;
}