#include "CPaddle.h"

CPaddle::CPaddle(float x = 200.f, float y = 300.f)
	:CMovable(x, y)
{
	this->y = y;
	this->x = x;
	/*
	this->shape.setPosition(Vector2f(x, y));
	shape.setSize(Vector2f(this->paddleWidht, this->paddleHeight)); //mo¿na te¿ shape.setSize({})
	shape.setFillColor(Color::Green);
	*/
}

void CPaddle::move(const float& dt, const float x, const float y)
{
	this->velocity.x = x * dt * this->paddleVelocity;
	this->velocity.y = y * dt * this->paddleVelocity;
}

void CPaddle::update(const float& dt)
{
	{
		cout << this->x << " ";
		this->x = this->x + velocity.x;
		this->y = this->y + velocity.y;
		//this->shape.setPosition(x - paddleWidht / 2, y);

		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
		{
			this->velocity.x = -this->paddleVelocity;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 800)
		{
			this->velocity.x = paddleVelocity;
		}
		else
		{
			this->velocity.x = 0;
		}
	}

}


void CPaddle::destroy()
{
}

bool CPaddle::isDestroyed()
{
	return false;
}



/*
void Paddle::draw(RenderTarget& target, RenderStates state) const // const oznacza ¿e ta metoda niebedzie zmieniaæ ¿adnych pól naszej klasy
{
	target.draw(this->shape, state);
}
*/





float CPaddle::left()
{
	return this->x - paddleWidht / 2; //zwracamy pozycje krawedzi kulki
}

float CPaddle::right()
{
	return this->x + paddleWidht / 2; //zwracamy pozycje krawedzi kulki
}

float CPaddle::top()
{
	return this->y - paddleHeight / 2; //zwracamy pozycje krawedzi kulki
}

float CPaddle::bottom()
{
	return this->y + paddleHeight / 2; //zwracamy pozycje krawedzi kulki
}

Vector2f CPaddle::getPosition()
{
	return Vector2f(this->x, this->y);
}