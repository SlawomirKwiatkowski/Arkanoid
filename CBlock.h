#pragma once
#include "CNonMovable.h"
/// \brief Klasa reprezentujaca bloczki
class CBlock :
	public CNonMovable
{
private:
	///określa czy blok zniszczony
	bool destroyed{ false };
	/// do edycji mapy czy klkniety
	bool klicked{ false };
	///szerokosc bloczka
	float width{ 80.0f }; 
	///wysokosc bloczka
	float height{ 20.0f };

	
public:
	/**
 * @brief konstruktor tworzacy bloczek w okreslonym miejcu
 * @param x wspolrzedna x srodka bloczka
 * @param y wspolrzedna y srodka bloczka
 * @param width szerokosc bloczka
 * @param height wysokosc bloczka
 */
	CBlock(float x, float y, float width,float height);
	virtual ~CBlock();

	/**
* @brief Zwraca czy bloczek jest zniszczony
*/
	bool isDestroyed(); //do sprawdzania czy istnieje
	/**
* @brief Funkcja do niszczenia bloczka
*/
	void destroy(); //do niszczenia bloczku
	/**
* @brief Zwraca czy bloczek jest klikniety
*/
	bool isKlicked();//zwraca czy klikniêty
	/**
* @brief Funkcja do klikniecia w bloczek
*/
	void klick();
	/**
* @brief Funkcja do odklkniecia bloczka
*/
	void unklick();
	/**
* @brief Funkcja do uaktualnienia pozycji
*/
	void updatePosi(float x,float y);

	//funkcje
	/**
* @brief Zwraca pozycje lewej krawedzi
*/
	float left(); //metody zwracaja pozycje krawedzi kulek 
	/**
* @brief Zwraca pozycje prawej krawedzi
*/
	float right();
	/**
* @brief Zwraca pozycje gornej krawedzi
*/
	float top();
	/**
* @brief Zwraca pozycje dolnej krawedzi
*/
	float bottom();
	/**
* @brief Funkcja do aktualizacji
*/
	void update(const float& dt) ;

};


