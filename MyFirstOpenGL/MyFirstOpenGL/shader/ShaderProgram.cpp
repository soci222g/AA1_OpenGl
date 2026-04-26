#include "ShaderProgram.h"

void ShaderProgram::loadProgram()
{
	//creamos programa

	GLuint program = glCreateProgram();

	//verifiquem si hi ha un vertex shader o no
	if (_vertexShader.GetShader() != 0) {
		glAttachShader(program, _vertexShader.GetShader());
	}
	if (_geometryShader.GetShader() != 0) {
		glAttachShader(program, _geometryShader.GetShader());
	}
	if (_fragmentShader.GetShader() != 0) {
		glAttachShader(program, _fragmentShader.GetShader());
	}

	//Linkear el programa
	glLinkProgram(program);

	//comprobem estat del programa

	GLint succes;
	glGetProgramiv(program, GL_LINK_STATUS, &succes);

	if (succes) {
		//llibarem recursos
		if (_vertexShader.GetShader() != 0) {
			glDetachShader(program, _vertexShader.GetShader());

		}
		if (_vertexShader.GetShader() != 0) {
			glDetachShader(program, _vertexShader.GetShader());

		}
		if (_vertexShader.GetShader() != 0) {
			glDetachShader(program, _vertexShader.GetShader());

		}

		Program = program;
	}
	else {
		std::cout << " error del programa!!" << std::endl;
		//pillem el lenght del log
		GLint logLenght;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLenght);

		//guardem el log
		std::vector<GLchar> errorlog(logLenght);
		glGetProgramInfoLog(program, logLenght, nullptr, errorlog.data());

		if (errorlog.size() > 0)
		//el printagem i surtim del programa
		std::cout << errorlog.data() << std::endl;
		std::exit(EXIT_FAILURE);
	}


}
