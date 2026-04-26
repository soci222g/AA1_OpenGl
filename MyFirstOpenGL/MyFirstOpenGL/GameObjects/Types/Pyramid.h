#pragma once
#include "../GameObject.h"

class Pyramid : public GameObject
{
private:
	float colorTimer = 0.f;


	ShaderProgram* shaderProgram;

	bool movingUp = true;
	const float maxHeight = 0.5f;
	const float minHeight = -0.5f;
public:
	Pyramid() = default;
	Pyramid(glm::vec3 pos, glm::vec3 rot, glm::vec3 sca) : GameObject(pos, rot, sca) {}

	void SetupGeometry(GLuint VAO) override;
	void Update(float dt) override;
	void ShaderMatriux() override;


};