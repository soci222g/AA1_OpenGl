#pragma once
#include <GLFW/glfw3.h>
//#include <GL/glew.h>
//#include <gtc/type_ptr.hpp>


//#define IM InputManager::GetInstance()
//
//class InputManager
//{
//public:
//	static InputManager* GetInstance()
//	{
//		static InputManager instance;
//		return &instance;
//	}
//
//
//
//	bool IsKeyPressed(int key) const
//	{
//		//la window te que vani del game manager, es te que guarda en alguna variable
//		GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "WINDOW1", NULL, NULL);
//		return glfwGetKey(window, key) == GLFW_PRESS;
//	}
//
//	bool IsKeyReleased(int Key) const {
//
//		GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "WINDOW1", NULL, NULL);
//
//		return glfwGetKey(window, Key) == GLFW_REPEAT;
//	}
//};

class InputManager
{
private:
	bool keyStates[GLFW_KEY_LAST] = {};
	bool paused = false;
	float speedMultiplier = 1.0f;

public:
	InputManager() = default;
	~InputManager() = default;

	void handleKeyInput(int key);
	bool isPressed(int key) const { return keyStates[key]; }
	bool isPaused() const { return paused; }
	float getSpeedMultiplier() const { return speedMultiplier; }
};