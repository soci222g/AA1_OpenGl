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

	unsigned int lastFrameTime = 0;

public:
	GameManager() = default;
	~GameManager() = default;

	void Initialize();
	void LoadGame();
	void Update(float dt);
	void Render();
	void Cleanup();
	bool IsRunning() const { return !glfwWindowShouldClose(window); }
	void CreateWindow(int width, int height, const char* title);
	GLFWwindow* GetWindow() const { return window; }
	void ResizeWindow(GLFWwindow* window, int iNewFrameBufferWidth, int iNewFrameBufferHeight);

	unsigned int GetLastFrameTime() const { return lastFrameTime; }
	void SetLastFrameTime(unsigned int time) { lastFrameTime = time; }
};