#define _CRTDBG_MAP_ALLOC

#include<iostream>

#include <crtdbg.h>

#ifdef _DEBUG

#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)

#define new DEBUG_NEW

#endif
#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>


#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"


using namespace std;
using namespace sf;

/// \brief Klasa reprezentujaca wszystkie obiekty na mapie
class CEntity
{
protected:
	/// wspolrzedna x
	float x;
	/// wspolrzedna y
	float y;
public:
	/**
 * @brief konstruktor tworzacy obiekt w okreslonym miejcu
 * @param x wspolrzedna x srodka obiektu
 * @param y wspolrzedna y srodka obiektu
 */
	CEntity(float x, float y);
	virtual ~CEntity();

	//funkcje
	/**
* @brief Zwraca pozycje lewej strony obiektu
*/
	virtual float left()=0; 
	/**
* @brief Zwraca pozycje prawej strony obiektu
*/
	virtual float right()=0;
	/**
* @brief Zwraca pozycje gory obiektu
*/
	virtual float top()=0;
	/**
* @brief Zwraca pozycje dolu obiektu
*/
	virtual float bottom()=0;

	
	/**
* @brief Funkcja do aktualizacji
*/
	virtual void update(const float& dt)=0;
	//virtual void render(RenderTarget& target)=0;
	/**
* @brief Funkcja do niszczenia obiektu
*/
	virtual void destroy() = 0;
	/**
* @brief Zwraca czy obiekt jest zniszczony
*/
	virtual bool isDestroyed()=0;
};

