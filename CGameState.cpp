#include "CGameState.h"

CGameState::CGameState(RenderWindow* window, stack<CState*>* states, float ballVellocity)
	:CState(window, states)
{
	initBall(ballVellocity);
	initPaddle();
	initBlock();
	
	/*
	objects.push_back(new CPaddle(400.f, 550.f));
	objects.push_back(new CBall(400.f, 300.f));
	*/
}


CGameState::CGameState(RenderWindow* window, stack<CState*>* states, float ballVellocity, string source)
	:CState(window, states)
{
	initBall(ballVellocity);
	initPaddle();
	initBlock(source);
}


CGameState::~CGameState()
{
	//objects.clear();
	auto it = this->objects.begin();
	for (it = this->objects.begin();it != this->objects.end();++it)
	{
		delete* it;
	}
	auto it2 = this->gobjects.begin();
	for (it2 = this->gobjects.begin();it2 != this->gobjects.end();++it2)
	{
		delete* it2;
	}
	//gobjects.clear();
	delete this->ball;
	delete this->paddle;
}

void CGameState::initPaddle()
{
	this->paddle = new CPaddle(400.f, 550.f);
	//objects.push_back(this->paddle);
	gobjects.push_back(new CGPaddle(this->paddle));

}

void CGameState::initBall(float ballVellocity)
{
	this->ball = new CBall(400.f, 300.f, ballVellocity);
	//objects.push_back(this->ball);
	gobjects.push_back(new CGBall(this->ball));
}
 
void CGameState::initBlock()
{
	for (int i = 0;i < blocksY;i++)
	{
		for (int j = 0;j < blocksX; j++)
		{
			objects.push_back(new CBlock((j + 1) * (60 + 10), (i + 2) * (20 + 5), 60, 20));
			gobjects.push_back(new CGBlock(objects.back()));//metoda ta oczekuje parametrów konstruktora bloczka
		}
	}


	/*
	objects.push_back(new CBlock(100.0f, 200.0f, 80, 30));
	this->firstBlock = objects.back();
	gobjects.push_back(new CGBlock(objects.back()));
	*/
}

void CGameState::initBlock(string source)
{
	fstream plik;
	plik.open(source, ios::in);
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
		objects.emplace_back(new CBlock(x, y, 60, 20));
		gobjects.push_back(new CGBlock(objects.back()));
	};
	plik.close();
}



void CGameState::endState()
{
	cout << "endgamestate ";
}

void CGameState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void CGameState::update(const float& dt)
{

	this->collisionTest(paddle, ball);
	/*
	int i = 0;
	CPaddle* ob;
	
	for (auto& object : this->objects) {
		object->update(dt);
		i++;
		if (i == 1)
			ob = object;
		if (i == 2) {
			collisionTest(ob, object);
		}
		ob = object;
	}
	*/
	/*
	this->paddle->update(dt);
	this->ball->update(dt);
	*/
	
	paddle->update(dt);
	ball->update(dt);
	this->quit = true;
	for (auto& object : this->objects) {


		if(object->isDestroyed() == false){
			this->quit = false;
			if(collisionTest1(ball,object)) break;//sprawdza czy bloczki nie zderzyly sie z pilka
		}
	}

	for (auto& object : this->gobjects) {
		
		object->updatePos();
	}
	if (this->end) cout << "koniec gry";

	if(Keyboard::isKeyPressed(Keyboard::A))
		cout<<"A"<<endl;
	this->updateInput(dt);
}

void CGameState::render(RenderTarget* target)
{

/*
	this->paddle->render(*target);
	this->ball->render(*target);
	*/
	
	for (auto& object : this->gobjects)// do rysowania obiektów graficznych 
		if (object->isDestroyed() == false) {
			object->render(*target);
		}
}

bool CGameState::collisionTest(CPaddle* paddle, CBall* ball)//zderzenie pileczki z paletka
{
	if (!(isIntersecting(paddle, ball))) return false; //jesli nie doszlo do kolizji

	ball->moveUp();

	if (ball->getPosition().x < paddle->getPosition().x)
	{
		ball->moveLeft();
	}
	else if (ball->getPosition().x > paddle->getPosition().x)
	{
		ball->moveRight();
	}
}

bool CGameState::collisionTest1(CBall* ball, CBlock* block)//kolizja pillki z bloczkiem
{
	if (!(isIntersecting(block, ball))) return false;

	block->destroy();

	float overlapLeft{ ball->right() - block->left() };
	float overlapRight{ block->right() - ball->left() };

	float overlapTop{ ball->bottom() - block->top() };
	float overlapBottom{ block->bottom() - ball->top() };

	bool ballFromLeft{ abs(overlapLeft) < abs(overlapRight) };
	bool ballFromTop{ abs(overlapTop) < abs(overlapBottom) };

	float minOverlapX(ballFromLeft ? overlapLeft : overlapRight);
	float minOverlapY(ballFromTop ? overlapTop : overlapBottom);

	if (abs(minOverlapX) < abs(minOverlapY))
	{
		ballFromLeft ? ball->moveLeft() : ball->moveRight();
	}
	else
	{
		ballFromTop ? ball->moveUp() : ball->moveDown();
	}
}
