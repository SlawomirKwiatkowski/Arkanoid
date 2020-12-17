#pragma once
#include "CEntity.h"

/// \brief Klasa reprezentujaca ruchome obiekty
class CMovable :
	public CEntity
{
protected:
	/// wspolrzedna x
	float x = 0;
	/// wspolrzedna y
	float y = 0;
public:
	/**
* @brief konstruktor tworzacy poruszajace sie obiekty w okreslonym miejcu
* @param x wspolrzedna x srodka obiektu
* @param y wspolrzedna y srodka obiektu
*/
	CMovable(float x, float y);
	virtual ~CMovable();

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
* @brief Funkcja do przemieszczania obiektu
*/
	virtual void move(const float& dt,const float dir_x,const float dir_y)=0;
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

