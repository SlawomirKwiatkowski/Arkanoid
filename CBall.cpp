#include "CBall.h"

CBall::CBall(float x = 200.f, float y = 300.f, float ballVellocity = 50.f)
	:CMovable(x, y)
{
	this->ballVelocity = ballVellocity;
	this->y = y;
	this->x = x;
	this->velocity = { ballVellocity ,-ballVellocity };
}
CBall::~CBall()
{
}

void CBall::update(const float& dt)
{
	this->x = this->x + velocity.x;
	this->y = this->y + velocity.y;

	if (this->left() < 0)
	{
		velocity.x = ballVelocity;
	}
	else if (this->right() > 800)
	{
		velocity.x = -ballVelocity;
	}
	else if (this->top() < 0)
	{
		velocity.y = ballVelocity;
	}
	else if (this->bottom() > 600)
	{
		velocity.y = -ballVelocity;
		cout << "Poza  wpwwpw";
	}
}

float CBall::left()
{
	return this->x - this->ballRadious; //zwracamy pozycje krawedzi kulki
}

float CBall::right()
{
	return this->x + this->ballRadious; //zwracamy pozycje krawedzi kulki
}

float CBall::top()
{
	return this->y - this->ballRadious; //zwracamy pozycje krawedzi kulki
}

float CBall::bottom()
{
	return this->y + this->ballRadious; //zwracamy pozycje krawedzi kulki
}

/*void CBall::render(RenderTarget& target)
{
	target.draw(this->shape);
}
*/

void CBall::move(const float& dt, const float dir_x, const float dir_y)
{
	this->velocity.x = dir_x * dt * this->ballVelocity;
	this->velocity.y = dir_y * dt * this->ballVelocity;

}


void CBall::moveDown()
{
	this->velocity.y = ballVelocity;
}

void CBall::moveUp()
{
	this->velocity.y = -ballVelocity;
}

void CBall::moveRight()
{
	this->velocity.x = ballVelocity;
}
void CBall::moveLeft()
{
	this->velocity.x = -ballVelocity;
}

Vector2f CBall::getPosition()
{
	return Vector2f(this->x, this->y);
}

void CBall::destroy()
{
}

bool CBall::isDestroyed()
{
	return false;
}
