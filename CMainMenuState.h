#pragma once
#include "CState.h"
#include "CGameState.h"
#include "CButton.h"
#include "CMapEditorState.h"
#include "CSetingsState.h"

/// \brief Klasa obslugujaca menu glowne
class CMainMenuState :
	public CState
{
public:
	/**
* @brief Konstruktor dla stanow gry
* @param window Wskaznik na okno na ktorym sa rysowane rzeczy
* @param states Wskaznik na stos na ktorym znajduja sie stany gry
*/
	CMainMenuState(RenderWindow* window, stack<CState*>* states);
	virtual ~CMainMenuState();

	//funkcje

	/**
 * @brief Do usuwania rzeczy
 */
	void endState();
	/**
* @brief Funkcja do aktualizacji
*/
	void update(const float& dt);
	/**
* @brief Funkcja do aktualizacji przycisków i obsłucgi ich funkcjonalnosci
*/
	void updateButtons();
	/**
 * @brief Sluzy do wyswietlania obiektow
 */
	void render(RenderTarget* target = NULL);
	/**
* @brief Sprawdza czy nie kliknales w przycisk,
* jesli tak to wykonuje odpowiednie operacje, jak
* przejscie do innego stanu lub wyjscie z gry
 * @param target Miejsce rysowania 
*/
	/**
* @brief Sprawdza czy nie kliknales w przycisk,
* jesli tak to wykonuje odpowiednie operacje, jak
* przejscie do innego stanu lub wyjscie z gry
 * @param target Miejsce rysowania
*/
	void renderButtons(RenderTarget* target = NULL);

	void updateInput(const float& dt);

private:
	//parametry
	/// Kolor tla w tym stanie gry
	RectangleShape background;
	/// Trzcionka
	Font font;

	/// Lista przyciskow w tym stanie 
	map<string, CButton*> buttons;
	/**
* @brief Tworzy przyciski
*/
	void initButtons();
	/**
* @brief Wczytuje czcionke z pliku
*/
	void initFonts();

};