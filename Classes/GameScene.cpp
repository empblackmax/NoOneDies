#include "GameScene.h"



bool GameScene::init()
{
	if (!LayerColor::initWithColor(Color4B(255,255,255,255)))
	{
		return false;
	}
	counter = 0;//初始化计数器

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//gameControllers.pushBack(GameController::create(this, 100, 0, 1));
	//gameControllers.pushBack(GameController::create(this, 220, 150, 2));
	auto gamecontroller1= GameController::create(this, 100, 10, 1);
	gameControllers.insert(0,gamecontroller1);

	//暂停
	auto pauseItem = MenuItemFont::create("Pause", CC_CALLBACK_1(GameScene::pauseCallFunc, this));
	pauseItem->setPosition(Point(280, 465));
	pauseItem->setColor(Color3B::BLACK);

	auto menu = Menu::create(pauseItem, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 7);

	//分数
	auto labScore = Label::create("Score:", "Arial", 30);
	labScore->setPosition(Point(47, 464));
	labScore->setColor(Color3B::BLACK);
	this->addChild(labScore);

	score = Label::create();
	score->setPosition(Point(135, 464));
	score->setColor(Color3B::BLACK);
	score->setSystemFontSize(30);
	score->setTag(101);
	this->addChild(score);

	this->scheduleUpdate();

	//监听器
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

	//调试框
	/*scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);*/

	//重力加速度
	scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));
	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

void GameScene::update(float dt)
{
	counter += 1;
	//log("%d",counter);
	score->setString(StringUtils::format("%d",counter));

	if (counter==500)
	{
		auto gamecontroller2 = GameController::create(this, 220,130, 2);
		gameControllers.insert(0,gamecontroller2);
	}

	if (counter ==1000)
	{
		auto gamecontroller3 = GameController::create(this, 100, 250, 1);
		gameControllers.insert(0, gamecontroller3);
	}

	if (counter == 1500)
	{
		auto gamecontroller4 = GameController::create(this, 220, 370, 2);
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
	//创建rendertexture，纹理大小为窗口大小320*480
	RenderTexture* renderTexture = RenderTexture::create(320, 480);

	//遍历GameScene类的所有子节点信息，画入rendertexture中。
	//这里类似截图。
	renderTexture->begin();
	this->getParent()->visit();
	renderTexture->end();

	//将游戏界面暂停，压入到堆栈，并切换到暂停界面
	Director::sharedDirector()->pushScene(PauseScene::pauseScene(renderTexture));
}

void GameScene::overCallFunc(Ref* pSender)
{
	//创建rendertexture，纹理大小为窗口大小320*480
	RenderTexture* renderTexture = RenderTexture::create(320, 480);

	//遍历GameScene类的所有子节点信息，画入rendertexture中。
	//这里类似截图。
	renderTexture->begin();
	this->getParent()->visit();
	renderTexture->end();

	//将游戏界面暂停，压入到堆栈，并切换到暂停界面
	Director::sharedDirector()->pushScene(GameoverScene::overScene(renderTexture));
}