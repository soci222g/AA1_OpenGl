#pragma once
#include <GLFW/glfw3.h>


class InputManager
{
private:
	bool keyStates[GLFW_KEY_LAST] = {};
	bool paused = false;

public:
	InputManager() = default;
	~InputManager() = default;

	void handleKeyInput(int key, GLFWwindow* window);
	bool isPressed(int key, GLFWwindow* window) const { return glfwGetKey(window, key) == GLFW_PRESS; }
	bool isPaused() const { return paused; }
};