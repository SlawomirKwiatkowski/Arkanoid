#include "CMainMenuState.h"

CMainMenuState::CMainMenuState(RenderWindow* window, stack<CState*>* states)
	:CState(window, states)//wywoluje konstruktor
{
	this->initFonts();
	this->initButtons();


	this->background.setSize(Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(Color::Blue);

}

CMainMenuState::~CMainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin();it != this->buttons.end();++it)
	{
		delete it->second;
	}
} 



void CMainMenuState::endState()
{
	cout << "ending setingssteate" << endl;
}


void CMainMenuState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);



	//system("cls");
	//cout << this->mousePosWindow.x << "  " << this->mousePosWindow.y << endl;
	this->updateButtons();


}

void CMainMenuState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//nowa gra
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new CSetingsState(this->window, this->states,&this->font));
	}

	
	if (this->buttons["MAP_STATE"]->isPressed())
	{
		this->states->push(new CMapEditorState(this->window, this->states));
	}


	//wyjœcie
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->quit = true;
	}

}


void CMainMenuState::render(RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	target->draw(this->background);

	this->renderButtons(target);



}

void CMainMenuState::renderButtons(RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}

}


void CMainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();

	//update player input

}

void CMainMenuState::initButtons()
{
	{

		this->buttons["GAME_STATE"] = new CButton(100, 100, 150, 50, &this->font, "New game",
			Color(70, 70, 70, 200), Color(150, 150, 150, 200), Color(20, 20, 20, 200));

		this->buttons["MAP_STATE"] = new CButton(100, 200, 150, 50, &this->font, "Map editor",
			Color(70, 70, 70, 200), Color(150, 150, 150, 200), Color(20, 20, 20, 200));

		this->buttons["EXIT_STATE"] = new CButton(100, 300, 150, 50, &this->font, "quit",
			Color(70, 70, 70, 200), Color(150, 150, 150, 200), Color(20, 20, 20, 200));
	}


}


void CMainMenuState::initFonts()
{
	if (!this->font.loadFromFile("ariblk.ttf"))
	{
		cout << "nie mozna wczytaæ czcionki" << endl;
	}
}