#ifndef _Runningmen_PauseScene_H_
#define _Runningmen_PauseScene_H_

#include "cocos2d.h"
#include "MainScene.h"
#include "GameScene.h"
USING_NS_CC;

class PauseScene :Layer
{
public:
	virtual bool init();
	CREATE_FUNC(PauseScene);
	static Scene* pauseScene(RenderTexture* pSender);
	void pauseSelCallFunc(Ref* pSender);

};

#endif