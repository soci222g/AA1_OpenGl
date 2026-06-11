#pragma once
#include <GLFW/glfw3.h>

#define IM InputManager::GetInstance()



enum class KeyPressed
{
	NONE, ONE, TWO, THREE, FOUR, M, N, SPACE, ESCAPE

};


class InputManager
{
private:

	bool keyStates[GLFW_KEY_LAST] = {};
	bool paused = false;


	KeyPressed _currentKey = KeyPressed::NONE;

public:



	static InputManager* GetInstance()
	{
		static InputManager instance;
		return &instance;
	}

	static void ListenKeys(GLFWwindow* window, int key, int scancode, int action, int mods);

	void Init(GLFWwindow* window) {
		glfwSetKeyCallback(window, ListenKeys);
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}



	InputManager() = default;
	InputManager(InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;
	~InputManager() = default;

	KeyPressed getCurrentKey() const { return _currentKey; }
	void SetCurrentKey(KeyPressed key) { _currentKey = key; }


	void handleKeyInput(int key, GLFWwindow* window);
	bool isPressed(int key, GLFWwindow* window) const { return glfwGetKey(window, key) == GLFW_PRESS; }
	bool isPaused() const { return paused; }
};