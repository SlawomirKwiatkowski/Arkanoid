#include "CSetingsState.h"

CSetingsState::CSetingsState(RenderWindow* window, stack<CState*>* states,Font *font)
	: CState(window,states)
{
	this->font = font;
	this->initButtons();
	this->quit = false;
	Sleep(500);

}

CSetingsState::~CSetingsState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin();it != this->buttons.end();++it)
	{
		delete it->second;
	}
	Sleep(500);
}

void CSetingsState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);



	//system("cls");
	cout << this->mousePosWindow.x << "  " << this->mousePosWindow.y << endl;
	this->updateButtons();

}

void CSetingsState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//nowa gra
	if (this->buttons["EASY_STATE"]->isPressed())
	{
		this->states->push(new CMapChoosingState(this->window, this->states,this->font,2.f));
	}

	if (this->buttons["MEDIUM_STATE"]->isPressed())
	{
		this->states->push(new CMapChoosingState(this->window, this->states, this->font,4.f));
	}

	if (this->buttons["HARD_STATE"]->isPressed())
	{
		this->states->push(new CMapChoosingState(this->window, this->states, this->font,6.f));
	}

}

void CSetingsState::render(RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	this->renderButtons(target);
}

void CSetingsState::endState()
{
	cout << "ending menusteate" << endl;
}

void CSetingsState::renderButtons(RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void CSetingsState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void CSetingsState::initButtons()
{
	{

		this->buttons["EASY_STATE"] = new CButton(100, 100, 150, 50, this->font, "Easy",
			Color(70, 70, 70, 200), Color(150, 150, 150, 200), Color(20, 20, 20, 200));


		this->buttons["MEDIUM_STATE"] = new CButton(100, 200, 150, 50, this->font, "Medium",
			Color(70, 70, 70, 200), Color(150, 150, 150, 200), Color(20, 20, 20, 200));

		this->buttons["HARD_STATE"] = new CButton(100, 300, 150, 50, this->font, "Hard",
			Color(70, 70, 70, 200), Color(150, 150, 150, 200), Color(20, 20, 20, 200));
	}
}

