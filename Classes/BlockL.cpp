#include "BlockL.h"

bool BlockL::init()
{
	Sprite::init(); 

	//生成障碍物
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Size size = Size((rand()%20)+5,(rand()%25)+10);
	this->setPhysicsBody(PhysicsBody::createBox(size));
	this->setTextureRect(Rect(0, 0, size.width, size.height));
	this->setColor(Color3B::BLACK);
	this->setContentSize(size);
	this->setPositionX(visibleSize.width);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	//不受重力影响
	this->getPhysicsBody()->setDynamic(false);

	//设置碰撞
	this->getPhysicsBody()->setContactTestBitmask(1);

	this->schedule(schedule_selector(BlockL::Lmove), 0.01);
	//this->schedule(schedule_selector(Block::Rmove), 0.5);

	return true;
}

void BlockL::Lmove(float dt)
{
	//移动障碍物
	this->setPositionX(getPositionX() - 4 );
	if (getPositionX()<0)
	{
		this->unschedule(schedule_selector(BlockL::Lmove));
		this->removeFromParent();
		

	}
}

