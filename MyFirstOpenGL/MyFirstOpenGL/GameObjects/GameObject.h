#pragma once
#include <glm.hpp>
#include <GL/glew.h>
#include <ext/matrix_transform.hpp>


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

	GLuint vertexArrayObject = 0;
	GLuint vertexBufferObject = 0;
	GLuint colorBufferObject = 0;
	int vertexCount = 0;


public:

	GameObject() : position(glm::vec3(0.f)), rotation(glm::vec3(0.f)), scale(glm::vec3(1.f)) {}
	GameObject(glm::vec3 pos, glm::vec3 rot, glm::vec3 sca) : position(pos), rotation(rot), scale(sca) {}
	virtual ~GameObject() = default;

	glm::mat4 GenerateTranslationMatrix(glm::vec3 translation);
	glm::mat4 GenerateRotationMatrix(glm::vec3 axi, float fdegrees);
	glm::mat4 GenerateScaleMatrix(glm::vec3 scale);

	virtual void SetupGeometry() = 0;
	virtual void Render();
	virtual void Update(float dt) = 0;

	// getters
	glm::vec3 GetPosition() const { return position; }
	glm::vec3 GetRotation() const { return rotation; }
	glm::vec3 GetScale() const { return scale; }
	GLuint GetVAO() const { return vertexArrayObject; }
	int GetVertexCount() const { return vertexCount; }
};