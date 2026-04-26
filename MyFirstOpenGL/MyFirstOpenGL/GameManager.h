#pragma once
#include "GameObjects/GameObject.h"
#include "shader/ShaderProgram.h"
#include "InputManager/InputManager.h"

#include <vector>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class GameManager
{
private:
	GLFWwindow* window = nullptr;
	std::vector<GameObject*> gameObjects;
	ShaderProgram* shaderProgram;
	InputManager inputManager;

	void CreateWindow(int width, int height, const char* title);

public:
	GameManager() = default;
	~GameManager() = default;

	void Initialize();
	void LoadGame();
	void Update(float dt);
	void Render();
	void Cleanup();
	bool IsRunning() const { return !glfwWindowShouldClose(window); }
	GLFWwindow* GetWindow() const { return window; }


};