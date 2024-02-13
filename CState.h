#pragma once


#include "CEntity.h"




using namespace std;
using namespace sf;

/// \brief Klasa reprezentujaca wszystkie stany gry
class CState
{
private:
protected:
	/// Wskaznik na stos na ktorym znajduja sie stany gry
	stack <CState*>* states; //wskaŸnik na stos na którym znajduj¹ siê ekrany

	/// Wskaznik na okno w ktorym rysowane sa stany gry 
	RenderWindow* window; // wskaŸnik na ekran 
	/// Okresla czy nalezy wyjsc z okna
	bool quit; // okreœla czy naale¿y wyjœæ z okna

	/// Przechowuje pozycje myszy na ekranie
	Vector2i mousePosScreen; //do œledzenie myszy na eekranie
	/// Przechowuje pozycje myszy w oknie
	Vector2i mousePosWindow; //do œledzenia pozycji myszy w ekranie gry
	/// Przechowuje pozycje myszy w widoku
	Vector2f mousePosView;//do œledzenia myszy prz przesuwaj¹cym siê ekranie
public:
	/**
 * @brief Konstruktor dla stanow gry
 * @param window Wskaznik na okno na ktorym sa rysowane rzeczy
  * @param states Wskaznik na stos na ktorym znajduja sie stany gry
 */
	CState(RenderWindow* window, stack<CState*>* states);
	virtual ~CState();

	/**
 * @brief Zwraca czy wyjsc
 */
	const bool& getQuit() const; //zwraca czy wyjœæ

		/**
	 * @brief Sprawdza czy wcisniety escape
	 */
	virtual void checkForQuit();//sprawdza czy wciœniêty escape
		/**
	 * @brief do usuwania rzeczy, na razie nie uzywane
	 */
	virtual void endState() = 0; //do usówania rzeczy po zakoñczeniu narazie nie u¿ywane
		/**
	 * @brief Aktualizuje pozycje myszki
	 */
	virtual void updateMousePosition(); //aktualizuje pozycje myszki

		/**
	 * @brief Sprawdza dane wejsciowe
	 */
	virtual void updateInput(const float& dt) = 0; //wirtualna do sprawdzania danych wejœciowych
		/**
	 * @brief Funkcja do aktualizacji
	 */
	virtual void update(const float& dt) = 0; //wirtualna do aktualizacji danych
		/**
	 * @brief Sluzy do wyswietlania obiektow
	 */
	virtual void render(RenderTarget* target = nullptr) = 0;//wirtualna jeœli nic nie ma renderuje okno


};

