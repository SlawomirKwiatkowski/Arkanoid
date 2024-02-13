#include "Game.h"

//funkcje inicjuj¹ce

void Game::initWindow()
{
	this->window = new RenderWindow(sf::VideoMode(800, 600), "SFML works!");
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initStates()
{
    this->states.push(new CMainMenuState(this->window, &this->states));
}

Game::Game()
{
    this->initWindow();
    this->initStates();
}

Game::~Game()
{
    cout << "destruktor gry";
	this->window->close();
    delete this->window;
    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}


void Game::endAplication()
{
    cout << "koniec ";
}

void Game::updateDt()//aktualizuje czas trwania klatki
{
    this->dt = this->dtClock.restart().asSeconds();
    cout << this->dt << " ";
}

//funkcje
void Game::updateSFMLEvents()//sprawdza wejœcia
{
    while (this->window->pollEvent(this->event))
    {
        if (event.type == Event::Closed)
            this->window->close();
    }
}

void Game::update()//wywoluje aktualizaje
{
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);
        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else//jeœli gra siê skoñczy³¹
    {
        this->endAplication();
        this->window->close();
    }
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    
    }

}

void Game::render()
{
    this->window->clear();

    if (!this->states.empty())
        this->states.top()->render(this->window);
    this->window->display();
}
