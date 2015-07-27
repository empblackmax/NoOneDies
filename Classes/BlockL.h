#ifndef Runningmen_BlockL_H_
#define Runningmen_BlockL_H_

#include "cocos2d.h"
USING_NS_CC;

class BlockL :public Sprite
{
public:
	CREATE_FUNC(BlockL);
	virtual bool init();
	void Lmove(float dt);
	
private:
	
};

#endif