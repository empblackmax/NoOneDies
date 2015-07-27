#ifndef _Runningmen_HeroL_H_
#define _Runningmen_HeroL_H_

#include "cocos2d.h"
USING_NS_CC;

class HeroL :public Sprite
{
public:
	CREATE_FUNC(HeroL);
	virtual bool init();
	void runL();
	void bindHeroL(Sprite* sprite);

private:
	Sprite* runHeroL;


};

#endif
