#ifndef Runningmen_BlockR_H_
#define Runningmen_BlockR_H_

#include "cocos2d.h"
USING_NS_CC;

class BlockR :public Sprite
{
public:
	CREATE_FUNC(BlockR);
	virtual bool init();
	void Rmove(float dt);

private:

};

#endif