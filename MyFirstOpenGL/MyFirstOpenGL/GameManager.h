#pragma once
#include "GameObject.h"
#include "ShaderProgram.h"

#include <vector>

class GameManager
{
private:
	std::vector<GameObject*> gameObjects;
	ShaderProgram* shaderProgram;

public:
	void LoadGame();
	void Update(float dt);
	void Render();
};