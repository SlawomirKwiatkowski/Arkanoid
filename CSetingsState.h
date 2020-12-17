#pragma once
#include "CState.h"
#include "CButton.h"
#include "CGameState.h"
#include <windows.h>
#include "CMapChoosingState.h"
class CSetingsState :
	public CState
{
public:
	/**
* @brief Konstruktor dla stanow gry
* @param window Wskaznik na okno na ktorym sa rysowane rzeczy
* @param states Wskaznik na stos na ktorym znajduja sie stany gry
* @param font Wskaźnik do trzcionki
*/
	CSetingsState(RenderWindow* window, stack<CState*>* states,Font *font);
	~CSetingsState();
	/**
* @brief Funkcja do aktualizacji
*/
	void update(const float& dt);
	/**
* @brief Sprawdza czy nie kliknales w przycisk,
* jesli tak to wykonuje odpowiednie operacje, jak
* przejscie do innego stanu lub wyjscie z gry
*/
	void updateButtons(); 
	/**
* @brief Sluzy do wyswietlania obiektow
*/
	void render(RenderTarget* target = NULL);
	/**
 * @brief do usuwania rzeczy, na razie nie uzywane
 */
	void endState();
	/**
* @brief Do rysowania obiektow
 * @param target Miejsce rysowania
*/
	void renderButtons(RenderTarget* target = NULL);

	void updateInput(const float& dt);

private:
	/// Trzcionka
	Font *font;

	/// Lista przyciskow w tym stanie 
	map<string, CButton*> buttons;
	/**
* @brief Tworzy przyciski
*/
	void initButtons();
};

