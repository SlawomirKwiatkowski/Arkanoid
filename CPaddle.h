#pragma once
#include "CMovable.h"

/// \brief Klasa reprezentujaca poruszajaca paletke
class CPaddle :
	public CMovable
{

private:
	//void draw(RenderTarget& target, RenderStates state) const override; //nadpisujemy metode virtualn¹ z interfejsu który dziedziczymy, zaznaczamy ¿e ta funkcja jest sta³a
	/// szerokosc paletki
	const float paddleWidht{ 100.0f };
	/// wysokosc paletki
	const float paddleHeight{ 20.0f };
	/// predkosc poruszania sie paletki
	float paddleVelocity{ 4.0f };
	///wektor 2 zmiennych float,okreslajacy jak porusza się paleta, moze tylko w lewo i prawo
	Vector2f velocity{ paddleVelocity, 0 };

public:
	/**
 * @brief konstruktor tworzacy paletke w okreslonym miejcu
 * @param x wspolrzedna x srodka paletki
 * @param y wspolrzedna y srodka paletki
 */
	CPaddle(float x ,float y);
	~CPaddle() = default;
	/**
	* @brief Porusza pilka
	*/
	void move(const float& dt, const float x, const float y);//przemieszczanie

	/**
	* @brief Przy kazdym wywolaniu  sprawdza
	* odbicie od scian
	*@param dt czas trwania klatki
	*/
	void update(const float& dt); //do aktualizacja elementów skladowych
	/**
	* @brief Zmienia zmienna destroy
	*/
	void destroy();
	/**
	* @brief Zwraca czy obiekt zniszczony
	*/
	bool isDestroyed();

	/**
	* @brief Zwraca pozycje lewej strony paletki
	*/
	float left();
	/**
	* @brief Zwraca pozycje prawej strony paletki
	*/
	float right();
	/**
	* @brief Zwraca pozycje gornej strony paletki
	*/
	float top();
	/**
	* @brief Zwraca pozycje dolnej strony paletki
	*/
	float bottom();


	/**
	* @brief Zwraca pozycje paletki
	*/
	Vector2f getPosition();
};

