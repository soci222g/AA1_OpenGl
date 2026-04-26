#pragma once
#include "../GameObject.h"


class Cube : public GameObject
{
private:
	bool movingUp = true;
	const float maxHeight = 0.5f;
	const float minHeight = -0.5f;
	


	GLint offsetpositionReference = 0;

public:
	Cube() = default;
	Cube(glm::vec3 pos, glm::vec3 rot, glm::vec3 sca) : GameObject(pos, rot, sca) {}

	void SetupGeometry(GLuint VAO) override;
	void Update(float dt) override;
	void ShaderMatriux() override;	
};