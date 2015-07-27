#ifndef _Runningmen_GameoverScene_H_
#define _Runningmen_GameoverScene_H_

#include "cocos2d.h"
#include "GameScene.h"
#include "MainScene.h"
USING_NS_CC;

class GameoverScene :public Layer
{
public:
	virtual bool init();
	static Scene* overScene(RenderTexture* RenderTexture);
	CREATE_FUNC(GameoverScene);
	void overSelCallFunc(Ref* pSender);
};

#endif