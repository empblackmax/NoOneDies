#include "BlockR.h"

bool BlockR::init()
{
	Sprite::init();

	//生成障碍物
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Size size = Size((rand() % 20) + 5, (rand() % 25) + 10);
	this->setPhysicsBody(PhysicsBody::createBox(size));
	this->setTextureRect(Rect(0, 0, size.width, size.height));
	this->setColor(Color3B::BLACK);
	this->setContentSize(size);
	this->setPositionX(-10);

	//不受重力影响
	this->getPhysicsBody()->setDynamic(false);

	//设置碰撞
	this->getPhysicsBody()->setContactTestBitmask(1);

	this->schedule(schedule_selector(BlockR::Rmove), 0.01);
	

	return true;
}

void BlockR::Rmove(float dt)
{
	//移动障碍物
	this->setPositionX(getPositionX() + 4);
	if (getPositionX() >330)
	{
		this->unschedule(schedule_selector(BlockR::Rmove));
		this->removeFromParent();


	}
}

