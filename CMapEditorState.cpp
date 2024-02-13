#include "CMapEditorState.h"

CMapEditorState::CMapEditorState(RenderWindow* window, stack<CState*>* states)
	:CState(window,states)
{
	background.setSize(Vector2f(window->getSize().x, window->getSize().y));
	background.setFillColor(Color::Black);

	initBlock();
}

CMapEditorState::~CMapEditorState()
{
	saveToFile();
	auto it = this->blocks.begin();
	for (it = this->blocks.begin();it != this->blocks.end();++it)
	{
		delete* it;
	}
	auto it2 = this->gobjects.begin();
	for (it2 = this->gobjects.begin();it2 != this->gobjects.end();++it2)
	{
		delete* it2;
	}
	delete this->blockToClick;
	cout << "koniec editorstate";
	Sleep(500);
}

void CMapEditorState::endState()
{
}

void CMapEditorState::update(const float& dt)
{
	this->updateInput(dt);
	updateMousePosition();
	mouseKlickMapCreator();
	for (auto& object : this->gobjects) {

		object->updatePos();
	}
}

void CMapEditorState::render(RenderTarget* target)
{
	for (auto& object : this->gobjects)
		if (object->isDestroyed() == false) {
			object->render(*target);
		}
}

void CMapEditorState::renderButtons(RenderTarget* target)
{
}

void CMapEditorState::initBlock()
{
	fstream plik;
	plik.open("mapa.txt", ios::in);
	if (plik.good() == false)
	{
		exit;
	};
	int n;
	plik >> n;
	for (int i = 0;i < n;i++)
	{
		float x;
		plik >> x;
		float y;
		plik >> y;
		blocks.emplace_back(new CBlock(x, y, 60, 20));
		gobjects.push_back(new CGBlock(blocks.back()));
	};
	plik.close();
	this->blockToClick = new CBlock(400, 550, 80,30);
	gobjects.push_back(new CGBlock(blockToClick));

}

void CMapEditorState::saveToFile()
{
	{
		fstream plik;
		plik.open("mapa.txt", ios::out);
		if (plik.good() == true)
		{
			std::cout << "Uzyskano dostep do pliku!" << std::endl;
			
			plik << size(this->blocks) << endl;

			for (auto& block : this->blocks)
			{

				plik << (block->left() + block->right()) / 2 << endl;
				plik << (block->top() + block->bottom()) / 2 << endl;
			}
		}
		else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;

		plik.close();
	}

}

void CMapEditorState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void CMapEditorState::mouseKlickMapCreator()
{

	{
		cout << mousePosView.x << " " << mousePosView.y << " ";
		cout << "1 ";
		if (this->blockToClick->isKlicked() == true) //sprawdza czy bloczek jest klikniêty
		{
			this->blockToClick->updatePosi(mousePosView.x, mousePosView.y);//jeœli tak to pod¹¿a za kursorem
			cout << "2 ";
			addBlock(); //sprawdza czy kliknales eby dodac
			if (Mouse::isButtonPressed(Mouse::Right)) //sprawdza czy odklikn¹³eœ
			{
				this->blockToClick->unklick();
				this->blockToClick->updatePosi(400, 550);
			}
		}
		else { //jeœli bloczek dodaj¹cy nie jest klikniêty to sprawdza inne i czy klikn¹³eœ na dodaj¹cy
			editBlock();
			cout << "lolo ";
			if (Mouse::isButtonPressed(Mouse::Left) && this->blockToClick->isKlicked() == false// sprawdza czy klikn¹³eœ w dodanie
				&& mousePosView.x < this->blockToClick->right() && mousePosView.x > this->blockToClick->left()
				&& mousePosView.y < this->blockToClick->bottom() && mousePosView.y > this->blockToClick->top())
			{
				this->blockToClick->klick();
				cout << "elo elooll ";
			}

		}
	}
}

void CMapEditorState::addBlock()
{
	
	bool kol = false;
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		for (auto& block : blocks)
		{
			if (block->right() >= this->blockToClick->left() && block->left() <= this->blockToClick->right()
				&& block->bottom() >= this->blockToClick->top() && block->top() <= this->blockToClick->bottom())
			{
				kol = true;
			}
		}
		if (kol == false && mousePosView.y<350)
		{
			blocks.emplace_back(new CBlock(mousePosView.x, mousePosView.y, 60, 20));
			gobjects.push_back(new CGBlock(blocks.back()));
		}
	};
}

void CMapEditorState::editBlock()
{
	int i = -1;
	for (auto& block : this->blocks)
	{
		if (block->isKlicked() == true)
		{
			block->updatePosi(mousePosView.x, mousePosView.y);
			cout << "to jest: " << i << " ";
			if (Mouse::isButtonPressed(Mouse::Right)) {
				block->unklick();
				cout << "wololo";
			}
		}

		i++;
		if (block->isKlicked() == true && Keyboard::isKeyPressed(Keyboard::Delete))
		{
			

			block->destroy();
			for (auto& object : this->gobjects) {

				object->updatePos();
			}
			auto it = blocks.begin() + i;
			this->blocks.erase(it);

		}

		if ((Mouse::isButtonPressed(Mouse::Left) && block->isKlicked() == false// sprawdza czy klikn¹³eœ w dodanie
			&& mousePosView.x <  block->right() && mousePosView.x >  block->left()
			&& mousePosView.y <  block->bottom() && mousePosView.y >  block->top()))
		{
			block->klick();
		}

	}
}
