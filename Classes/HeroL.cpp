#include "HeroL.h"

bool HeroL::init()
{
	Sprite::init();

	return true;
}



void HeroL::runL()
{

	//加载图片到缓冲池
	SpriteFrameCache* frameCacheL = SpriteFrameCache::getInstance();
	frameCacheL->addSpriteFramesWithFile("opHero.plist", "opHero.png");

	SpriteFrame* frameL = nullptr;
	Vector<SpriteFrame*> frameVecL;

	//用一个列表保存所有spriteframe对象
	for (int i = 1; i <= 5; i++)
	{
		//从缓冲池获取spriteframe对象
		frameL = frameCacheL->getSpriteFrameByName(StringUtils::format("opHero%d.png", i));
		frameVecL.pushBack(frameL);
	}

	//利用列表创建动画对象
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

	//设置主角大小
	Size size = runHeroL->getContentSize();
	runHeroL->setPosition(size / 2);
	this->setPhysicsBody(PhysicsBody::createBox(size));
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	//主角不改变角度
	this->getPhysicsBody()->setRotationEnable(false);
	this->setContentSize(size);

	//设置碰撞
	this->getPhysicsBody()->setContactTestBitmask(1);
}
