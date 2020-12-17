#include "CState.h"

CState::CState(RenderWindow* window, stack<CState*>* states)
{
	this->window = window;
	this->quit = false;
	this->states = states;
}

CState::~CState()
{
}
const bool& CState::getQuit() const
{
	if(this->quit)cout << "wyjdz" << endl;
	return this->quit;
}

void CState::checkForQuit()
{
	cout << this->quit << endl;
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		
		this->quit = true;
		cout << "dzia³am" <<" "<< this->quit<< endl;
	}
}

void CState::updateMousePosition()
{
	this->mousePosScreen = Mouse::getPosition();
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));
}


