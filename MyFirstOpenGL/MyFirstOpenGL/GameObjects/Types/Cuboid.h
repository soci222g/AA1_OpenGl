#pragma once
#include "../GameObject.h"

class Cuboid : public GameObject
{
private:
	float width = 0.5f;
	float height = 0.3f;
	float depth = 0.2f;

	float minScale = 0.3f;
	float maxScale = 1.0f;
	bool scalingDown = true;
	float scaleSpeed = 0.5f;

		ShaderProgram* shaderProgram;


public:
	Cuboid() = default;
	Cuboid(glm::vec3 pos, glm::vec3 rot, glm::vec3 sca, float w, float h, float d) : GameObject(pos, rot, sca), width(w), height(h), depth(d) {}

	void SetupGeometry(GLuint VAO) override;
	void Update(float dt) override;
private:
	void UpdateScale(float dt);
};
