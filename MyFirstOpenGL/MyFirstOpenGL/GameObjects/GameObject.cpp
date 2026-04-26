#include "GameObject.h"


glm::mat4 GameObject::GenerateTranslationMatrix(glm::vec3 translation)
{
    return glm::translate(glm::mat4(1.0f), translation);
}

glm::mat4 GameObject::GenerateRotationMatrix(glm::vec3 axi, float fdegrees)
{
    return glm::rotate(glm::mat4(1.0f), glm::radians(fdegrees), glm::normalize(axi));
}

glm::mat4 GameObject::GenerateScaleMatrix(glm::vec3 scale)
{
	return glm::scale(glm::mat4(1.0f), scale);
}

void GameObject::Render(GLuint VAO)
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexCount);
    glBindVertexArray(0);
}


