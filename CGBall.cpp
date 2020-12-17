#include "CGBall.h"

CGBall::CGBall(CEntity* obj)
	:CGEntity(obj)
{
	shape.setPosition(obj->left(), obj->top());
	shape.setRadius((obj->right() - obj->left())/2);
	shape.setFillColor(Color::Red);
}

CGBall::~CGBall()
{
}

void CGBall::render(RenderTarget& target)
{
	target.draw(this->shape);
}

void CGBall::updatePos()
{
	shape.setPosition(object->left(), object->top());
}

bool CGBall::isDestroyed()
{
	return false;
}
