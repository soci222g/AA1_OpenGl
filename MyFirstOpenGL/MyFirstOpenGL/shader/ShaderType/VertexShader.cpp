#include "VertexShader.h"

void VertexShader::loadVertexShader(const std::string& path)
{

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	//load in memeori the shader

	std::string sShaderCode = LoadPath(path);
	const char* cShaderSource = sShaderCode.c_str();

	//vinculem a la targeta grafica  (el 1 es el numero de archius que composan el shaders)
	glShaderSource(vertexShader, 1, &cShaderSource, nullptr);


	//compilem el shader
	glCompileShader(vertexShader);


	
	//verifiquem la compilacio del shader
	GLint succes;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &succes);




	if (succes) {
		SetShader(vertexShader);
	}
	else {
		std::cout << " error de carga!!" << std::endl;
		//primer he,m de saver la longitut del error
		GLint logLenght;
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &logLenght);


		//get the log
		std::vector<GLchar> errorlog(logLenght);
		glGetShaderInfoLog(vertexShader, logLenght, nullptr, errorlog.data());

		//mostrem el log

		std::cout << errorlog.data() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}
