#ifndef Runningmen_GameScene_H_
#define Runningmen_GameScene_H_

#include "cocos2d.h"
#include "GameController.h"
#include "PauseScene.h"
#include "GameoverScene.h"
USING_NS_CC;

class GameScene :public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	virtual void update(float dt);
	CREATE_FUNC(GameScene);
	void pauseCallFunc(Ref* pSender);
	void overCallFunc(Ref* pSender);
	

private:
	/*Hero* runHero;*/
	Vector<GameController*> gameControllers;
	Label* score;
	int counter;

};

#endif