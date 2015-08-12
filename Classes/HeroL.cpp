#include "HeroL.h"

bool HeroL::init()
{
	Sprite::init();

	return true;
}



void HeroL::runL()
{

	//����ͼƬ�������
	SpriteFrameCache* frameCacheL = SpriteFrameCache::getInstance();
	frameCacheL->addSpriteFramesWithFile("opHero.plist", "opHero.png");

	SpriteFrame* frameL = nullptr;
	Vector<SpriteFrame*> frameVecL;

	//��һ���б�������spriteframe����
	for (int i = 1; i <= 5; i++)
	{
		//�ӻ���ػ�ȡspriteframe����
		frameL = frameCacheL->getSpriteFrameByName(StringUtils::format("opHero%d.png", i));
		frameVecL.pushBack(frameL);
	}

	//�����б�����������
	Animation* animationL = Animation::createWithSpriteFrames(frameVecL);
	animationL->setLoops(-1);
	animationL->setDelayPerUnit(0.04f);

	Animate* animateL = Animate::create(animationL);
	runHeroL->runAction(animateL);
}

void HeroL::bindHeroL(Sprite* sprite)
{
	runHeroL = sprite;
	this->addChild(runHeroL);

	//�������Ǵ�С
	Size size = runHeroL->getContentSize();
	runHeroL->setPosition(size / 2);
	this->setPhysicsBody(PhysicsBody::createBox(size));
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	//���ǲ��ı�Ƕ�
	this->getPhysicsBody()->setRotationEnable(false);
	this->setContentSize(size);

	//������ײ
	this->getPhysicsBody()->setContactTestBitmask(1);
}
