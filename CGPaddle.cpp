#include "CGPaddle.h"

CGPaddle::CGPaddle(CEntity* obj)
	:CGEntity(obj)
{
	shape.setPosition(obj->left(),obj->right());
	shape.setSize(Vector2f(obj->right() - obj->left(),obj->bottom()-obj->top()));
}

CGPaddle::~CGPaddle()
{
}

void CGPaddle::render(RenderTarget& target)
{
	target.draw(this->shape);
}

void CGPaddle::updatePos()
{
	shape.setPosition(object->left(), object->top());
}

bool CGPaddle::isDestroyed()
{
	return false;
}
