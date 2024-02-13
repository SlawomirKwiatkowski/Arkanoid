#pragma once
#include "CEntity.h"

/// \brief Klasa reprezentujaca nieruchome obiekty
class CNonMovable :
	public CEntity
{
private:

public:
	/**
* @brief konstruktor tworzacy poruszajace sie obiekty w okreslonym miejcu
* @param x wspolrzedna x srodka obiektu
* @param y wspolrzedna y srodka obiektu
*/
	CNonMovable(float x, float y);
	virtual ~CNonMovable();

	//funkcje
	/**
* @brief Zwraca pozycje lewej strony obiektu
*/
	virtual float left() = 0;
	/**
* @brief Zwraca pozycje prawej strony obiektu
*/
	virtual float right() = 0;
	/**
* @brief Zwraca pozycje gory obiektu
*/
	virtual float top() = 0;
	/**
* @brief Zwraca pozycje dolu obiektu
*/
	virtual float bottom() = 0;



	/**
* @brief Funkcja do aktualizacji
*/
	virtual void update(const float& dt) = 0;
	//virtual void render(RenderTarget& target)=0;
	/**
* @brief Funkcja do niszczenia obiektu
*/
	virtual void destroy() = 0;
	/**
* @brief Zwraca czy obiekt jest zniszczony
*/
	virtual bool isDestroyed() = 0;
};

