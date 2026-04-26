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

	void handleKeyInput(int key);
	bool isPressed(int key) const { return keyStates[key]; }
	bool isPaused() const { return paused; }
};