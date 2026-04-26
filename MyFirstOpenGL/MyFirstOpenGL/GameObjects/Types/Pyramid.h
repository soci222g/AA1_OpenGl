#pragma once
#include "../GameObject.h"

class Pyramid : public GameObject
{
private:
	int colorIndex = 0;  // 0 = Red, 1 = Green, 2 = Blue
	float colorTimer = 0.f;
	const float colorInterval = 2.f;  // 2 segons per cada canvi de color


	ShaderProgram* shaderProgram;


	glm::vec3 colors[3] = {
		glm::vec3(1.f, 0.f, 0.f),  // Red
		glm::vec3(0.f, 1.f, 0.f),  // Green
		glm::vec3(0.f, 0.f, 1.f)   // Blue
	};

	bool movingUp = true;
	const float maxHeight = 0.5f;
	const float minHeight = -0.5f;
public:
	Pyramid() = default;
	Pyramid(glm::vec3 pos, glm::vec3 rot, glm::vec3 sca) : GameObject(pos, rot, sca) {}

	void SetupGeometry(GLuint VAO) override;
	void Update(float dt) override;
	void UpdateColor(float dt);

	glm::vec3 GetColor() const { return colors[colorIndex]; }
};