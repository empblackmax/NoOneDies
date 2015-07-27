#include "Edge.h"

bool Edge::init()
{
	Node::init();

	Size size = Director::getInstance()->getVisibleSize();
	setPhysicsBody(PhysicsBody::createEdgeBox(size));
	

	return true;
}
