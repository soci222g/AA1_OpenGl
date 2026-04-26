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

	ShaderMatriux();    


    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexCount);
    glBindVertexArray(0);






}

void GameObject::ShaderMatriux()
{
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    glm::mat4 translationMatrix = GenerateTranslationMatrix(position);
    glm::mat4 rotationMatrix = GenerateRotationMatrix(glm::vec3(0.f, 1.f, 0.f), rotation.y);
    glm::mat4 scaleMatrix = GenerateScaleMatrix(scale);



    modelMatrix = translationMatrix * rotationMatrix * scaleMatrix * modelMatrix;

    glUniformMatrix4fv(glGetUniformLocation(shaderProgram->GetProgram(), "transform"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
}


