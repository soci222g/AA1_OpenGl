#pragma once
#include "../GameManager.h"



class  Aplication
{
public:
	void run();
	void processInput();
	void update(float dt);	


private:
	GameManager _gameManager;
};

