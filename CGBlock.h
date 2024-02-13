#pragma once
#include "CGEntity.h"
/// \brief Graficzna reprezentacja bloczkow
class CGBlock :
	public CGEntity
{
private:

	RectangleShape shape;
	bool destroy{false};
public:
	CGBlock(CEntity* obj);
	virtual ~CGBlock();
	void render(RenderTarget& target);
	void updatePos();
	bool isDestroyed();
	void changeColor();
};

