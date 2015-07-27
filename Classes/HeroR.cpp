#include "HeroR.h"

bool HeroR::init()
{
	Sprite::init();

	return true;
}

void HeroR::runR()
{
	
	//����ͼƬ�������
	SpriteFrameCache* frameCacheR = SpriteFrameCache::getInstance();
	frameCacheR->addSpriteFramesWithFile("Hero.plist", "Hero.png");

	SpriteFrame* frameR = nullptr;
	Vector<SpriteFrame*> frameVecR;

	//��һ���б�������spriteframe����
	for (int i = 1; i <= 5;i++)
	{
		//�ӻ���ػ�ȡspriteframe����
		frameR = frameCacheR->getSpriteFrameByName(StringUtils::format("Hero%d.png", i));
		frameVecR.pushBack(frameR);
	}

	//�����б�����������
	Animation* animationR = Animation::createWithSpriteFrames(frameVecR);
	animationR->setLoops(-1);
	animationR->setDelayPerUnit(0.03f);

	Animate* animateR = Animate::create(animationR);
	runHeroR->runAction(animateR);
}



void HeroR::bindHeroR(Sprite* sprite)
{
	runHeroR = sprite;
	this->addChild(runHeroR);


	//�������Ǵ�С
	Size size = runHeroR->getContentSize();
	runHeroR->setPosition(size / 2);
	this->setPhysicsBody(PhysicsBody::createBox(size));
	
	//���ǲ��ı�Ƕ�
	this->getPhysicsBody()->setRotationEnable(false);
	this->setContentSize(size);

	//������ײ
	this->getPhysicsBody()->setContactTestBitmask(1);
}
