#pragma once
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <gtc/type_ptr.hpp>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define IM InputManager::GetInstance()

class InputManager
{
public:
	static InputManager* GetInstance()
	{
		static InputManager instance;
		return &instance;
	}



	bool IsKeyPressed(int key) const
	{
		//la window te que vani del game manager, es te que guarda en alguna variable
		GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "WINDOW1", NULL, NULL);
		return glfwGetKey(window, key) == GLFW_PRESS;
	}
};