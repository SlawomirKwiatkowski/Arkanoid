#include "CGBlock.h"

CGBlock::CGBlock(CEntity* obj)
	:CGEntity(obj)
{
	shape.setPosition(obj->left(),obj->right());
	shape.setSize(Vector2f(obj->right()-obj->left(),obj->bottom()-obj->top()));
	
}

CGBlock::~CGBlock()
{
}

void CGBlock::render(RenderTarget& target)
{

	target.draw(this->shape);
	this->destroy = object->isDestroyed();
}

void CGBlock::updatePos()
{
	shape.setPosition(object->left(), object->top());
	this->destroy = object->isDestroyed();
}

bool CGBlock::isDestroyed()
{
	return this->destroy;
}

void CGBlock::changeColor()
{
	shape.setFillColor(Color::Red);
}
