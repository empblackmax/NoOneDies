#include "HeroR.h"

bool HeroR::init()
{
	Sprite::init();

	return true;
}

void HeroR::runR()
{
	
	//加载图片到缓冲池
	SpriteFrameCache* frameCacheR = SpriteFrameCache::getInstance();
	frameCacheR->addSpriteFramesWithFile("Hero.plist", "Hero.png");

	SpriteFrame* frameR = nullptr;
	Vector<SpriteFrame*> frameVecR;

	//用一个列表保存所有spriteframe对象
	for (int i = 1; i <= 5;i++)
	{
		//从缓冲池获取spriteframe对象
		frameR = frameCacheR->getSpriteFrameByName(StringUtils::format("Hero%d.png", i));
		frameVecR.pushBack(frameR);
	}

	//利用列表创建动画对象
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


	//设置主角大小
	Size size = runHeroR->getContentSize();
	runHeroR->setPosition(size / 2);
	this->setPhysicsBody(PhysicsBody::createBox(size));
	
	//主角不改变角度
	this->getPhysicsBody()->setRotationEnable(false);
	this->setContentSize(size);

	//设置碰撞
	this->getPhysicsBody()->setContactTestBitmask(1);
}
