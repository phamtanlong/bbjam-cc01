
/*
 * Level.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef LEVEL_H_
#define LEVEL_H_
#include "cocos2d.h"
#include "GameResourceConstant.h"
USING_NS_CC;
#include "cocos2d.h"

class Level : public cocos2d::CCNode
{
private:
	unsigned int* m_ArrayID;

	unsigned int* getArrayID(int level);
	void initLevel();
public:
	Level(int level);
};

#endif /* LEVEL_H_ */