#include "BlockR.h"

bool BlockR::init()
{
	Sprite::init();

	//�����ϰ���
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Size size = Size((rand() % 20) + 5, (rand() % 25) + 10);
	this->setPhysicsBody(PhysicsBody::createBox(size));
	this->setTextureRect(Rect(0, 0, size.width, size.height));
	this->setColor(Color3B::BLACK);
	this->setContentSize(size);
	this->setPositionX(-10);

	//��������Ӱ��
	this->getPhysicsBody()->setDynamic(false);

	//������ײ
	this->getPhysicsBody()->setContactTestBitmask(1);

	this->schedule(schedule_selector(BlockR::Rmove), 0.01);
	

	return true;
}

void BlockR::Rmove(float dt)
{
	//�ƶ��ϰ���
	this->setPositionX(getPositionX() + 4);
	if (getPositionX() >330)
	{
		this->unschedule(schedule_selector(BlockR::Rmove));
		this->removeFromParent();


	}
}

