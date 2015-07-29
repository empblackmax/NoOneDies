#include "PauseScene.h"


bool PauseScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//菜单条目
	auto mainItem = MenuItemImage::create("mainmenu.png", "mainmenu.png", this, menu_selector(PauseScene::pauseSelCallFunc));
	auto continueItem = MenuItemImage::create("continue.png", "continue.png", this, menu_selector(PauseScene::pauseSelCallFunc));
	auto restartItem = MenuItemImage::create("restart.png", "restart.png", this, menu_selector(PauseScene::pauseSelCallFunc));
	mainItem->setPosition(Point(visibleSize.width / 2, visibleSize.height / 4));
	continueItem->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	restartItem->setPosition(Point(visibleSize.width / 2, visibleSize.height / 3));
	
	mainItem->setTag(1);
	continueItem->setTag(2);
	restartItem->setTag(3);

	// create menu, it's an autorelease object
	auto menu = Menu::create( continueItem,restartItem,mainItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 2);
	
	return true;
}

Scene* PauseScene::pauseScene(RenderTexture* pSender)
{
	Scene* myscene = Scene::create();
	Layer* mylayer = PauseScene::create();
	myscene->addChild(mylayer,1);

	//使用Game界面中截图的纹理图片创建Sprite
	//并将Sprite添加到pausescene场景层中
	Sprite* mysprite = Sprite::createWithTexture(pSender->getSprite()->getTexture());
	mysprite->setPosition(Point(160, 240));
	mysprite->setFlipY(true);            //翻转
	mysprite->setColor(cocos2d::ccGRAY); //图片颜色变灰色
	myscene->addChild(mysprite);

	return myscene;
}

void PauseScene::pauseSelCallFunc(Ref* pSender)
{
	MenuItem* selItem = (MenuItem*)pSender;
	switch (selItem->getTag())
	{
	case 1:
		Director::getInstance()->replaceScene(TransitionMoveInL::create(0.5f, MainScene::createScene()));
		break;
	case 2:
		Director::sharedDirector()->popScene();
		break;
	case 3:
		Director::sharedDirector()->replaceScene(TransitionMoveInR::create(0.5f,GameScene::createScene()));
		break;
	default:
		break;
	}
}