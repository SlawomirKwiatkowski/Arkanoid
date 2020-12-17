#pragma once
#include "CState.h"
#include "CBall.h"
#include "CPaddle.h"
#include "CGBall.h"
#include "CGPaddle.h"
#include "CBlock.h"
#include "CGBlock.h"
#include <windows.h>

/// \brief Klasa obslugujaca rozgrywke
class CGameState :
	public CState
{

private:
	/// Vector zawierajacy wskazniki do logicznej reprezentacji bloczkow
	vector <CBlock*> objects;
	/// Lista wszystkich obiektow graficznych w tym stanie
	vector <CGEntity*> gobjects;
	/// Wskaznik na paletke
	CPaddle* paddle;
	/// Wskaznik na pileczke
	CBall* ball;
	/// Liczba i rozmiar bloczkow w tym stanie gry
	unsigned blocksX{ 8 }, blocksY{ 3 }, blocsWidth{ 60 }, blocksHeight{ 20 };
	///czy koniec gry
		///okreœla czy blok zniszczony
	bool end{ false };

public:
	CGameState(RenderWindow* window, stack<CState*>* states, float ballVellocity);
	CGameState(RenderWindow* window, stack<CState*>* states, float ballVellocity, string source);
	virtual ~CGameState();

	//funkcje inicjujace
		/**
	 * @brief Tworzy paletke
	 */
	void initPaddle();
	/**
	* @brief Tworzy Pilke
	*/
	void initBall(float ballVellocity);
	/**
	* @brief Tworzy bloczki 
	*/
	void initBlock();

	void initBlock(string source);
	/**
	* @brief Do obslugi zakonczenia stanu
	*/
	void endState();


	/**
 * @brief Do obslugi wyjscia z gry
 * @param dt Czas trwania jednego cyklu programu
 */
	void updateInput(const float& dt);
	/**
 * @brief Sprawdza zmiany jakie nastapily w cyklu
 * gry, wywoluje inne metody obslugujace kolizje
 * @param dt Czas trwania jednego cyklu programu
 */
	void update(const float& dt);
	void render(RenderTarget* target = nullptr );

	//mechanika
		/**
 * @brief Obsluguje kolizje paletki i pileczki
 * @param paddle Paletka
 * @param ball pilka
 */
	bool collisionTest(CPaddle* paddle,CBall* ball);
	/**
* @brief Obsluguje kolizje pilki i bloczkow
* w przypadku kolizji niszczy bloczek
* @param paddle Paletka
* @param block Bloczek
*/
	bool collisionTest1(CBall* ball, CBlock* block);

	/**
* @brief Sprawdza czy obiekty sie przecinaja
* @param A Obiekt klasy CEntity
* @param B Obiekt klasy CEntity
*/
	bool isIntersecting(CEntity* A,CEntity* B) //szablon klas do sprawdzenia przeciecia pi³ki i bloczków
	{
		return A->right() >= B->left() && A->left() <= B->right()
			&& A->bottom() >= B->top() && A->top() <= B->bottom();
	};
};

