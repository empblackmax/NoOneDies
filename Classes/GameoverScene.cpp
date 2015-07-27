#include "GameoverScene.h"


bool GameoverScene::init()
{
	Layer::init();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//GameOver
	auto label = Label::create("GameOver", "Arial", 40);
	label->setPosition(Point(160, 270));
	label->setColor(Color3B::BLACK);
	this->addChild(label);


	//�˵���Ŀ
	auto mainItem = MenuItemImage::create("mainmenu.png", "mainmenu.png", this, menu_selector(GameoverScene::overSelCallFunc));
	auto restartItem = MenuItemImage::create("restart.png", "restart.png", this, menu_selector(GameoverScene::overSelCallFunc));
	mainItem->setPosition(Point(160, 140));
	restartItem->setPosition(Point(160, 190));

	mainItem->setTag(1);
	restartItem->setTag(2);

	// create menu, it's an autorelease object
	auto menu = Menu::create( restartItem, mainItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 2);

	return true;
}

Scene* GameoverScene::overScene(RenderTexture* pSender)
{
	Scene* myscene = Scene::create();
	Layer* mylayer = GameoverScene::create();
	myscene->addChild(mylayer, 1);

	//ʹ��Game�����н�ͼ������ͼƬ����Sprite
	//����Sprite��ӵ�pausescene��������
	Sprite* mysprite = Sprite::createWithTexture(pSender->getSprite()->getTexture());
	mysprite->setPosition(Point(160, 240));
	mysprite->setFlipY(true);            //��ת
	mysprite->setColor(cocos2d::ccGRAY); //ͼƬ��ɫ���ɫ
	myscene->addChild(mysprite);

	return myscene;
}

void GameoverScene::overSelCallFunc(Ref* pSender)
{
	MenuItem* selItem = (MenuItem*)pSender;
	switch (selItem->getTag())
	{
	case 1:
		Director::getInstance()->replaceScene(TransitionMoveInL::create(0.5f, MainScene::createScene()));
		break;
	case 2:
		Director::sharedDirector()->replaceScene(TransitionMoveInR::create(0.5f, GameScene::createScene()));
		break;
	default:
		break;
	}
}