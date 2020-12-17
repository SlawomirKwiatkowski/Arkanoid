#pragma once
#include "CGEntity.h"

/// \brief Graficzna reprezentacja pilki
class CGBall :
	public CGEntity
{
private:
	/// ksztalt przycisku w tym wypadku prostokat
	CircleShape shape;
public:
	
	CGBall(CEntity* obj);
	virtual ~CGBall();
	void render(RenderTarget& target);
	void updatePos();
	bool isDestroyed();
};

