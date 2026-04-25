#pragma once
#include <GL/glew.h>
#include <gtc/matrix_transform.hpp>
#include <glm.hpp>
#include <string>
#include<fstream>
#include<iostream>
#include <vector>



class GameObject
{
public:
	glm::vec3 position = glm::vec3(0.f);
	glm::vec3 rotation = glm::vec3(0.f);
	glm::vec3 scale = glm::vec3(0.f);


	glm::vec3 forward = glm::vec3(1.f, 0.f, 0.f);
	glm::vec3 Up = glm::vec3(0.f, 1.f, 0.f);

	float velocity = 0.01f;
	float angularVelocity = 1;


	glm::mat4 ObjectModelMatrix;

private:

};

