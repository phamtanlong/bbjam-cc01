/*
 * Obj_Player.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef OBJ_PLAYER_H_
#define OBJ_PLAYER_H_

#include "GameObject.h"

class Obj_Player : public GameObject
{
public:
	Obj_Player(float x, float y);
	int GetID();
	CCSprite* CreateSprite();

	void changePlayerType(int playerID);
	int getPlayerType();
	void updateGravity();
	void updateAngle();
	float getTargetAngle();
	bool isRotateDone();
	void back();

private:
	int m_PlayerType;
	float m_fTargetAngle;
	bool m_bRotateDone;

	void onDoneRotate(CCNode* sender);
};

#endif
