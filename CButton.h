#pragma once
#include "CNonMovable.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


#include <iostream>
#include <fstream>
#include <sstream>
#include <stack> //do pusha
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>

/// \brief Mozliwy stany przycisku
enum button_states
{
	BTN_IDLE = 0,
	BTN_HOVER,
	BTN_ACTIVE

};

/// \brief Klasa reprezentujaca przyciski
class CButton
{
private:
	/// Stan przycisku
	short unsigned buttonState;
	/// Ksztalt przycisku
	RectangleShape shape;
	/// Trzcionka w jakiej wykonywany jest napis
	Font* font;
	/// text na przycisku
	Text text;

	/// Kolor bezczynnego przycisku
	Color idleColor;
	/// Kolor przycisku
	Color hoverColor;
	/// kolor aktywnego przycisku
	Color activeColor;


public:
	/**
 * @brief Konstruktor tworzacy przycisk
 * @param x wspó³rzêdna x przycisku
 * @param y wspó³rzêdna y przycisku
 * @param width szerokosc przycisku
 * @param height wysokosc przycisku
 * @param font trcionka
 * @param text napis
 */
	CButton(float x, float y, float width, float height, Font* font, string text,
		Color idleColor, Color hoverColor, Color activeColor);
	~CButton();

	/**
* @brief Zwraca pozycje lewej strony pilki
*/
	float left();
	/**
* @brief Zwraca pozycje prawej strony pilki
*/
	float right();
	/**
* @brief Zwraca pozycje gornej strony pilki
*/
	float top();
	/**
* @brief Zwraca pozycje dolnej strony pilki
*/
	float bottom();


	/**
* @brief Sprawdza czy przycisk jest wcisniety
*/
	const bool isPressed() const;



	/**
	 * @brief Przy ka¿dym wywo³aniu  sprawdza czy najechales na
	 * przycisk myszka jesli tak to zmienia aktywnosc
	 *@param mousePos pozycja myszki na ekranie
	 */
	void update(Vector2f mousePos);
	/**
 * @brief Sluzy do wyswietlania przyciskow na ekranie
 *@param target ekran do wyswietlania
 */
	void render(RenderTarget* target);
};

