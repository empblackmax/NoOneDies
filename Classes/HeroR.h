#ifndef _Runningmen_HeroR_H_
#define _Runningmen_HeroR_H_

#include "cocos2d.h"
USING_NS_CC;

class HeroR :public Sprite
{
public:
	
	CREATE_FUNC(HeroR);
	virtual bool init();
	void runR();
	void jumpR();
	void bindHeroR(Sprite* sprite);

private:
	Sprite* runHeroR;


};

#endif
