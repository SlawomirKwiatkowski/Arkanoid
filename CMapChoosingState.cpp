#include "CMapChoosingState.h"


CMapChoosingState::CMapChoosingState(RenderWindow* window, stack<CState*>* states, Font* font, float ballVellocity)
	:CState(window, states)
{
	this->ballVellocity = ballVellocity;
	this->font = font;
	this->initButtons();
	Sleep(500);
}

CMapChoosingState::~CMapChoosingState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin();it != this->buttons.end();++it)
	{
		delete it->second;
	}
}

void CMapChoosingState::initButtons()
{
	{

		this->buttons["DEFAULT_STATE"] = new CButton(100, 100, 150, 50, this->font, "domyslna",
			Color(70, 70, 70, 200), Color(150, 150, 150, 200), Color(20, 20, 20, 200));


		this->buttons["OWN_STATE"] = new CButton(100, 200, 150, 50, this->font, "wlasna",
			Color(70, 70, 70, 200), Color(150, 150, 150, 200), Color(20, 20, 20, 200));


	}
}


void CMapChoosingState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);



	//system("cls");
	cout << this->mousePosWindow.x << "  " << this->mousePosWindow.y << endl;
	this->updateButtons();
}

void CMapChoosingState::updateButtons()
{
	{
		for (auto& it : this->buttons)
		{
			it.second->update(this->mousePosView);
		}

		//nowa gra
		if (this->buttons["DEFAULT_STATE"]->isPressed())
		{
			this->states->push(new CGameState(this->window, this->states, this->ballVellocity));
		}

		if (this->buttons["OWN_STATE"]->isPressed())
		{
			this->states->push(new CGameState(this->window, this->states, this->ballVellocity,"mapa.txt"));
		}

	}
}

void CMapChoosingState::render(RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	this->renderButtons(target);
}

void CMapChoosingState::endState()
{
}

void CMapChoosingState::renderButtons(RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void CMapChoosingState::updateInput(const float& dt)
{
	this->checkForQuit();
}
