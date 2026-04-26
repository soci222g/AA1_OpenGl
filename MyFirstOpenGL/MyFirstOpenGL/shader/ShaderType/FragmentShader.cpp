#include "FragmentShader.h"

void FragmentShader::loadFragmentShader(const std::string& path)
{

	GLuint FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	std::string sShaderCode = LoadPath(path);
	const char* cShaderSource = sShaderCode.c_str();


	//vinculem a la targeta grafica  (el 1 es el numero de archius que composan el shaders)
	glShaderSource(FragmentShader, 1, &cShaderSource, nullptr);


	//compilem el shader
	glCompileShader(FragmentShader);

	//verifiquem la compilacio del shader
	GLint succes;
	glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &succes);


	if (succes) {
		SetShader(&FragmentShader);
	}
	else {
		std::cout << " error de carga!!" << std::endl;
		//primer he,m de saver la longitut del error
		GLint logLenght;
		glGetShaderiv(FragmentShader, GL_INFO_LOG_LENGTH, &logLenght);


		//get the log
		std::vector<GLchar> errorlog(logLenght);
		glGetShaderInfoLog(FragmentShader, logLenght, nullptr, errorlog.data());

		//mostrem el log

		std::cout << errorlog.data() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}
