#pragma once
#include "CState.h"
#include "CBlock.h"
#include "CGBlock.h"
#include <windows.h>

/// \brief Klasa obslugujaca edycje mapy
class CMapEditorState :
	public CState
{
public:
	CMapEditorState(RenderWindow* window, stack<CState*>* states);
	virtual ~CMapEditorState();

	//funkcje inicjuj¹ce



	//funkcje

	void endState();

	void update(const float& dt);


	void render(RenderTarget* target = NULL);
	void renderButtons(RenderTarget* target = NULL);

	void updateInput(const float& dt);
	/**
* @brief Sprawdza czy bloczek jest klikniety,
* jesli tak to porusza nim za kursorem,
* umozliwia jego dodanie jesli nie koliduje z innymi,
* pozwala tez edytowac bloczki kture znajduja sie na mapie
*/
	void mouseKlickMapCreator();//do sprawdzeniea czy klikn¹³eœ na dodawanie bloczka
		/**
* @brief Sprawdza czy bloczek ktory chcemy
*dodac nie koliduje z innymi i czy znajduje sie
* w odpowiednim obszarze
*/
	void addBlock(); //do dodania bloku
			/**
* @brief Umozliwia usuniecie istniejacego juz bloczka
*/
	void editBlock(); //do edyttowania bloków na mapie

private:
	RectangleShape background;
	vector <CBlock*> blocks; //do wype³nienia z pliku lub auto
	vector <CGBlock*> gobjects;

	unsigned blocsWidth{ 60 }, blocksHeight{ 20 };
	/// blok ktory sluzy do dodawania innych blokow na mapie
	CBlock* blockToClick;


	/**
* @brief Wczytuje mape z pliku,w ktorym znajduja
* sie wspolrzedne bloczkow
*/
	void initBlock();//wczytuje z pliku
		/**
* @brief Zapisuje mape do pliku, tj. przepisuje
* liczbe bloczkow na mapie oraz ich wspolrzedne
*/
	void saveToFile();//do zapisu do pliku 
};

