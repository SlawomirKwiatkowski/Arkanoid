#pragma once
#include "CMovable.h"

/**
*\mainpage
*\par Gra arkanoid
*\author Slawomir Kwiatkowski
*\date 15.07.2020
*/

///\brief Klasa reprezentujaca pileczke ktora sie odbija
class CBall :
	public CMovable
{
private:
	///stala promien kulki
	const float ballRadious{ 10.0f };
	///stala predkosci kulki
	float ballVelocity;
	///wektor 2 zmiennych float,okreslajacy jak porusza siê kulka, startuje w do³ i lewo
	Vector2f velocity;


public:
	/**
	 * @brief konstruktor tworzacy pilke w okreslonym miejcu
	 * @param x wspolrzedna x srodka pilki
	 * @param y wspolrzedna y srodka pilki
	 */
	CBall(float x, float y, float ballVellocity);
	virtual ~CBall();

	//funkcje
	/**
	 * @brief Przy kazdym wywolaniu  sprawdza
	 * odbicie od scian
	 *@param dt czas trwania klatki
	 */
	void update(const float& dt);

	/**
	 * @brief Porusza pilka w gore przy odbiciu
	 */
	void moveUp(); //metody do obs³ugi odbiæ pi³ki
		/**
	 * @brief Porusza pilka w dol przy odbiciu
	 */
	void moveDown();
	/**
	* @brief Porusza pilka w prawo przy odbiciu
	*/
	void moveRight();
	/**
 * @brief Porusza pilka w dol przy odbiciu
 */
	void moveLeft();

	/**
	* @brief Porusza pilka
	*/
	void move(const float& dt, const float dir_x, const float dir_y);
	/**
	* @brief Zwraca pozycje pilki
	*/
	Vector2f getPosition();
	/**
	* @brief Zmienia zmienna destroy
	*/
	void destroy();
	/**
	* @brief Zwraca czy obiekt zniszczony
	*/
	bool isDestroyed();

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

	//void render(RenderTarget& target);//renderuje elementy na okno
};

