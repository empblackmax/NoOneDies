#include "MainScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B::WHITE) )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

   

	//²Ëµ¥ÌõÄ¿
	auto gameItem = MenuItemFont::create("StartGame", CC_CALLBACK_1(MainScene::menuSelCallFunc, this));
	auto exitItem = MenuItemFont::create("Exit", CC_CALLBACK_1(MainScene::menuSelCallFunc, this));
	gameItem->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
	exitItem->setPosition(Point(visibleSize.width / 2, visibleSize.height / 3));
	gameItem->setColor(Color3B::BLACK);
	exitItem->setColor(Color3B::BLACK);
	gameItem->setTag(11);
	exitItem->setTag(12);

    // create menu, it's an autorelease object
    auto menu = Menu::create(gameItem,exitItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("RunningMen", "Arial", 24);
	label->setColor(Color3B::BLACK);
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

  
    
    return true;
}


void MainScene::menuSelCallFunc(Ref* pSender)
{
	MenuItem* selItem = (MenuItem*)pSender;
	switch (selItem->getTag())
	{
	case 10:
		#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
			MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
			return;
		#endif

		Director::getInstance()->end();

		#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
			exit(0);
		#endif
			break;
		case 11://game
			Director::getInstance()->replaceScene(TransitionMoveInR::create(0.5f,GameScene::createScene()));
			break;
		case 12:
			Director::getInstance()->end();
		default:
		break;
	}
}
