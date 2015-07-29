#include "GameScene.h"



bool GameScene::init()
{
	if (!LayerColor::initWithColor(Color4B(255,255,255,255)))
	{
		return false;
	}
	counter = 0;//��ʼ��������

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//gameControllers.pushBack(GameController::create(this, 100, 0, 1));
	//gameControllers.pushBack(GameController::create(this, 220, 150, 2));
	auto gamecontroller1= GameController::create(this, visibleSize.width*5/16, visibleSize.height/48, 1);
	gameControllers.insert(0,gamecontroller1);

	//��ͣ
	auto pauseItem = MenuItemFont::create("Pause", CC_CALLBACK_1(GameScene::pauseCallFunc, this));
	pauseItem->setPosition(Point(visibleSize.width - visibleSize.width / 8, visibleSize.height-pauseItem->getContentSize().height));
	pauseItem->setColor(Color3B::BLACK);

	auto menu = Menu::create(pauseItem, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 7);

	//����
	auto labScore = Label::create("Score:", "Arial", 30);
	labScore->setPosition(Point(visibleSize.width / 8, visibleSize.height - pauseItem->getContentSize().height));
	labScore->setColor(Color3B::BLACK);
	this->addChild(labScore);

	score = Label::create();
	score->setPosition(Point(labScore->getPositionX() + 80, visibleSize.height - pauseItem->getContentSize().height));
	score->setColor(Color3B::BLACK);
	score->setSystemFontSize(30);
	score->setTag(101);
	this->addChild(score);

	this->scheduleUpdate();

	//������
	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [this](PhysicsContact &contact)
	{
		this->unscheduleUpdate();
		overCallFunc(this);

		return true;
	};
	
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan= [this](Touch* touch, Event* event)
	{
		for (auto gc = gameControllers.begin(); gc != gameControllers.end();gc++)
		{
			if ((*gc)->hitTestPoint(touch->getLocation()))
			{
				(*gc)->onTouch();
				break;
			}
		}
		return false;
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);


	return true;
}

Scene* GameScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//���Կ�
	/*scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);*/

	//�������ٶ�
	scene->getPhysicsWorld()->setGravity(Vec2(0, -2*visibleSize.height));
	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

void GameScene::update(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	counter += 1;
	//log("%d",counter);
	score->setString(StringUtils::format("%d",counter));

	if (counter==500)
	{
		auto gamecontroller2 = GameController::create(this,visibleSize.width*11/16 ,visibleSize.height/48+visibleSize.height/4, 2);
		gameControllers.insert(0,gamecontroller2);
	}

	if (counter ==1000)
	{
		auto gamecontroller3 = GameController::create(this, visibleSize.width * 5 / 16, visibleSize.height / 48 + visibleSize.height / 2, 1);
		gameControllers.insert(0, gamecontroller3);
	}

	if (counter == 1500)
	{
		auto gamecontroller4 = GameController::create(this, visibleSize.width * 11 / 16, visibleSize.height / 48 + visibleSize.height *3/ 4, 2);
		gameControllers.insert(0, gamecontroller4);
	}

	//if (counter == 2000)
	//{
	//	auto gamecontroller5 = GameController::create(this, 100, 375, 1);
	//	gameControllers.insert(0, gamecontroller5);
	//}

	for (auto gc = gameControllers.begin(); gc != gameControllers.end();gc++)
	{
		(*gc)->onUpdate(dt);
	}

}

void GameScene::pauseCallFunc(Ref* pSender)
{
	//����rendertexture�������СΪ���ڴ�С320*480
	Size visibleSize = Director::getInstance()->getVisibleSize();
	RenderTexture* renderTexture = RenderTexture::create(visibleSize.width,visibleSize.height);

	//����GameScene��������ӽڵ���Ϣ������rendertexture�С�
	//�������ƽ�ͼ��
	renderTexture->begin();
	this->getParent()->visit();
	renderTexture->end();

	//����Ϸ������ͣ��ѹ�뵽��ջ�����л�����ͣ����
	Director::sharedDirector()->pushScene(PauseScene::pauseScene(renderTexture));
}

void GameScene::overCallFunc(Ref* pSender)
{
	//����rendertexture�������СΪ���ڴ�С320*480
	Size visibleSize = Director::getInstance()->getVisibleSize();
	RenderTexture* renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
	//RenderTexture* renderTexture = RenderTexture::create(320, 480);

	//����GameScene��������ӽڵ���Ϣ������rendertexture�С�
	//�������ƽ�ͼ��
	renderTexture->begin();
	this->getParent()->visit();
	renderTexture->end();

	//����Ϸ������ͣ��ѹ�뵽��ջ�����л�����ͣ����
	Director::sharedDirector()->pushScene(GameoverScene::overScene(renderTexture));
}