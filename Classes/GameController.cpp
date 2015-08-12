#include "GameController.h"


GameController* GameController::create(Layer* layer, float positionX, float positionY, int flag)
{
	auto gamecontroller = new GameController;
	gamecontroller->init( layer, positionX, positionY, flag);
	gamecontroller->autorelease();
	return gamecontroller;
}


bool GameController::init(Layer* layer, float positionX, float positionY, int flag)
{
	
	
	gc_layer = layer;
	gc_positionX = positionX;
	gc_positionY = positionY;
	gc_flag = flag;

	visibleSize = Director::getInstance()->getVisibleSize();

	//添加边框
	edge = Edge::create();
	edge->setPosition(visibleSize.width/2,visibleSize.height/2+positionY);
	edge->setContentSize(visibleSize);
	edge->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	layer->addChild(edge);

	//添加地板
	auto ground = Sprite::create();
	ground->setColor(Color3B::BLACK);
	ground->setPosition(visibleSize.width / 2, positionY+2);
	ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
	
	layer->addChild(ground);

	//添加主角
	
	if (flag==1)
	{
		//log("1");
	
		Sprite* sprite = Sprite::create("Hero1.png");

		runHeroR = HeroR::create();
		runHeroR->bindHeroR(sprite);
		runHeroR->runR();
		runHeroR->setPosition(100,runHeroR->getContentSize().width/2+ positionY);
		layer->addChild(runHeroR);
	

		//添加障碍物
		auto blockL = BlockL::create();
		blockL->setPositionY(blockL->getContentSize().height/2+positionY);
		layer->addChild(blockL);

	}

	if (flag==2)
	{
		//log("2");

		Sprite* sprite = Sprite::create("opHero1.png");

		runHeroL = HeroL::create();
		runHeroL->bindHeroL(sprite);
		runHeroL->runL();
		runHeroL->setPosition(220, runHeroL->getContentSize().height / 2 + positionY);
		layer->addChild(runHeroL);



		//添加障碍物
		auto blockR = BlockR::create();
		blockR->setPositionY(blockR->getContentSize().height/2+positionY);
		layer->addChild(blockR);
	}

	resetFrame();
	return true;
}

void GameController::resetFrame()
{
	currentFrameIndex = 0;
	nextFrameCount = (rand() % 120) + 120;
}

void GameController::addBlock()
{
	if (gc_flag==1)
	{
		auto blockl = BlockL::create();
		gc_layer->addChild(blockl);
		blockl->setPositionY(blockl->getContentSize().height / 2 + gc_positionY );
	}

	if (gc_flag == 2)
	{
		auto blockr = BlockR::create();
		gc_layer->addChild(blockr);
		blockr->setPositionY(blockr->getContentSize().height / 2 + gc_positionY);
	}
}

void GameController::onUpdate(float dt)
{
	currentFrameIndex++;
	if (currentFrameIndex>=nextFrameCount)
	{
		resetFrame();
		addBlock();
	}
}

bool GameController::hitTestPoint(Vec2 point)
{
	return edge->getBoundingBox().containsPoint(point);
}

void GameController::onTouch()
{
	
	
		if (gc_flag == 1)
		{
			
			runHeroR->getPhysicsBody()->setVelocity(Vec2(0, visibleSize.height * 11 / 16));
			
		}

		if (gc_flag == 2)
		{

			runHeroL->getPhysicsBody()->setVelocity(Vec2(0, visibleSize.height * 11 / 16));
		}

}

