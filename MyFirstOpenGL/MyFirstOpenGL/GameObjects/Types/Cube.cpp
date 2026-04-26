#include "Cube.h"




void Cube::SetupGeometry(GLuint VAO)
{


	// VBOs
	glGenBuffers(1, &vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

	GLfloat vertices[] = {
				-0.3f,0.3f,-0.3f,
				0.3f,0.3f, -0.3f,
				-0.3f,-0.3f, -0.3f,
				0.3f,-0.3f,-0.3f,
				0.3f,-0.3f,0.3f,
				0.3f,0.3f, -0.3f,
				0.3f,0.3f,0.3f,
				-0.3f,0.3f,-0.3f,
				-0.3f,0.3f,0.3f,
				-0.3f,-0.3f, -0.3f,
				-0.3f,-0.3f, 0.3f,
				0.3f,-0.3f,0.3f,
				-0.3f,0.3f,0.3f,
				0.3f,0.3f,0.3f
	};

	vertexCount = 15;

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);





	//shaders
	shaderProgram = new ShaderProgram();
	shaderProgram->GetVertexShader()->loadVertexShader("MyFistVertexShader.glsl");
	shaderProgram->GetGeometryShader()->loadGeometryShader("MyFirstGeometryShader.glsl");
	shaderProgram->GetFragmentShader()->loadFragmentShader("MyFirstFragmentShader.glsl");
	shaderProgram->loadProgram();

	shaderProgram->UseProgram();
	glUniform2f(glGetUniformLocation(shaderProgram->GetProgram(), "WindowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
	shaderProgram->UnuseProgram();


}

void Cube::Update(float dt)
{
	shaderProgram->UseProgram();

	if (movingUp) {
		position = position + Up * velocity ;

		if (position.y >= maxHeight) {
			movingUp = false;
		}
	}
	else {
		position = position - Up * velocity;
		if (position.y <= minHeight) {
			movingUp = true;
		}
	}


	rotation = rotation + Up * angularVelocity;

	// rotar sobre l'eix y
	

	shaderProgram->UnuseProgram();
}

void Cube::ShaderMatriux()
{
	glm::mat4 modelMatrix = glm::mat4(1.0f);
	glm::mat4 translationMatrix = GenerateTranslationMatrix(position);
	glm::mat4 rotationMatrix = GenerateRotationMatrix(glm::vec3(0.f, 1.f, 0.f), rotation.y);
	glm::mat4 scaleMatrix = GenerateScaleMatrix(scale);



	modelMatrix = translationMatrix * rotationMatrix * scaleMatrix * modelMatrix;

	glUniformMatrix4fv(glGetUniformLocation(shaderProgram->GetProgram(), "transform"), 1, GL_FALSE, glm::value_ptr(modelMatrix));


}
