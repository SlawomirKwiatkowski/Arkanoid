#pragma once
#include "CGEntity.h"
/// \brief Graficzna reprezentacja paletki
class CGPaddle :
	public CGEntity
{
private:

	RectangleShape shape;
	
public:
	CGPaddle(CEntity* obj);
	virtual ~CGPaddle();
	void render(RenderTarget& target);
	void updatePos();
	bool isDestroyed();

};


