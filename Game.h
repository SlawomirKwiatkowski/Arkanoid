#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "CGameState.h"
#include "CMainMenuState.h"
#include "CMapEditorState.h"

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"


using namespace std;
using namespace sf;

/// Klasa zarzadzajaca dzialaniem programu
class Game
{
private:
	/// Okno do wyswietlania obiektow w 2d
	RenderWindow *window; 
	///Zmienna zawierajaca event czyli dane wejsciowe z
	Event event; 
	/// Obiekt klasy Clock 
	Clock dtClock;
	/// Zmienna przechowujaca czas trwania jednego cyklu programu
	float dt;
	/// Stos przechowujacy wskazniki do stanow gry
	stack <CState*> states;

	//funkcje inicjuj¹ce

	/**
 * @brief Funkcja inicjalizujaca okno gry
 * ustawia jego parametry
 */
	void initWindow();//odpala okno do gry
	/**
 * @brief Funkcja inicjalizujaca stany gry
 */
	void initStates();

public:

	/**
* @brief Konstruktor programu odpowiada za wywolanie
* funkcji inicjalizujacych gre
*/
	Game();
	virtual ~Game();


	/**
 * @brief odpowiada za zakonczenie programu
 */
	void endAplication();
	/**
* @brief Funkcja aktualzujaca czas trwania jednego cyklu
*/
	void updateDt();//do aktualizacji czsu trwania klatki
	/**
 * @brief Odpowiada za obsluge zdarzen SFML
 * jak np klikniecie zamkniecia okna
 */
	void updateSFMLEvents();

	/**
* @brief Funkcja aktualzujaca stan gry dla stanu
* bedacego na gorze stosu
*/
	void update();//aktualizujê sytuacje ze stanu gry bêd¹ce najwy¿ej na stosie
	/**
 * @brief Glowna petla gry
 */
	void run();//g³owna pêtla gry
	/**
 * @brief Wywoluje rysowanie dla stanow gry
 * na na oknie 
 */
	void render();//prosi o rysowanie w oknie stanu gry
};

