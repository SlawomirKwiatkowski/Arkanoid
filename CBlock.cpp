#include "CBlock.h"

CBlock::CBlock(float x, float y,float width=80.0f, float height=20.0f)
	:CNonMovable(x,y)
{
	this->width = width;
	this->height = height;


}

CBlock::~CBlock()
{
}

bool CBlock::isDestroyed()
{
	return this->destroyed;
}

void CBlock::destroy()
{
	this->destroyed = true;
}

bool CBlock::isKlicked()
{
	return this->klicked;
}

void CBlock::updatePosi(float x, float y)
{
	this->x = x;
	this->y = y;
}

float CBlock::left()
{
	return this->x - width / 2;
}

float CBlock::right()
{
	return this->x + width / 2;
}

float CBlock::top()
{
	return this->y - height/2;
}

float CBlock::bottom()
{
	return this->y + height / 2;
}

void CBlock::update(const float& dt)
{
}



void CBlock::klick()
{
	if (this->klicked == false)
	{
		this->klicked = true;
	}
}

void CBlock::unklick()
{
	this->klicked = false;
}