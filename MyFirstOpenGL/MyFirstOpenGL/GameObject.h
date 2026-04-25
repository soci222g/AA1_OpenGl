#pragma once
#include <glm.hpp>

class GameObject
{
protected:
	glm::vec3 position = glm::vec3(0.f);
	glm::vec3 rotation = glm::vec3(0.f);
	glm::vec3 scale = glm::vec3(0.f);


	glm::vec3 forward = glm::vec3(1.f, 0.f, 0.f);
	glm::vec3 Up = glm::vec3(0.f, 1.f, 0.f);

	float velocity = 0.01f;
	float angularVelocity = 1;

public:
	GameObject() = default;
	GameObject() : position(glm::vec3(0.f)), rotation(glm::vec3(0.f)), scale(glm::vec3(1.f));
	GameObject(glm::vec3 pos, glm::vec3 rot, glm::vec3 sca) : position(pos), rotation(rot), scale(sca) {}
};