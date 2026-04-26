#include "GeometryShader.h"

void GeometryShader::loadGeometryShader(const std::string& path)
{
	GLuint GeometryShader = glCreateShader(GL_GEOMETRY_SHADER);

	std::string sShaderCode = LoadPath(path);
	const char* cShaderSource = sShaderCode.c_str();


	//vinculem a la targeta grafica  (el 1 es el numero de archius que composan el shaders)
	glShaderSource(GeometryShader, 1, &cShaderSource, nullptr);


	//compilem el shader
	glCompileShader(GeometryShader);

	//verifiquem la compilacio del shader
	GLint succes;
	glGetShaderiv(GeometryShader, GL_COMPILE_STATUS, &succes);


	if (succes) {
		SetShader(GeometryShader);
	}
	else {
		std::cout << " error de carga!!" << std::endl;
		//primer he,m de saver la longitut del error
		GLint logLenght;
		glGetShaderiv(GeometryShader, GL_INFO_LOG_LENGTH, &logLenght);


		//get the log
		std::vector<GLchar> errorlog(logLenght);
		glGetShaderInfoLog(GeometryShader, logLenght, nullptr, errorlog.data());

		//mostrem el log

		std::cout << errorlog.data() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}
