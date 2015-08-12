#ifndef _Runningmen_GameController_H_
#define _Runningmen_GameController_H_

#include "cocos2d.h"
#include "HeroR.h"
#include "HeroL.h"
#include "Edge.h"
#include "BlockL.h"
#include "BlockR.h"
USING_NS_CC;

 
class GameController :public Ref
{
public:
	
	static GameController* create(Layer* layer, float positionX, float positionY,int flag);
	virtual bool init(Layer* layer, float positionX, float positionY, int flag);
	void onUpdate(float dt);
	bool hitTestPoint(Vec2 point);
	void onTouch();
	

private:
	void resetFrame();
	void addBlock();
private:
	Layer* gc_layer;
	float gc_positionX;
	float gc_positionY;
	int gc_flag;
	Size visibleSize;
	int currentFrameIndex;
	int nextFrameCount;
	Edge* edge;
	HeroL* runHeroL;
	HeroR* runHeroR;
	bool isJumping;
	
};

#endif
