#pragma once
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "CEntity.h"
/// \brief Klasa reprezentujaca wszystkie graficzne obiekty
class CGEntity
{
protected:
	/// Obiekt logiczny ktorego reprezentacja jest dany obiekt graficzny
	CEntity* object;
public:
	/**
	 * @brief Obiekt graficzny zawsze inicjalizowany jest
	 * wskaznikiem na obiekt logiczny, który reprezentuje;
	 * @param obj Obiekt logiczny, któoy ma byæ reprezentowany
	 */
	CGEntity(CEntity *obj);
	virtual ~CGEntity();
	/**
 * @brief Funkcja aktualzujaca pozycje obiektu graficznego
 * na podstawie pozycji obiektu logicznego
 */
	virtual void updatePos()=0;
	/**
 * @brief Funkcja rysuj¹ca obiekt w oknie 
 * @param target Miejsce rysowania
 */
	virtual void render(RenderTarget& target) = 0;
	/**
* @brief Funkcja zwraca czy obiekt jest zniszczony
* jesli tak to nie jest on rysowany
*/
	virtual bool isDestroyed()=0;
};

