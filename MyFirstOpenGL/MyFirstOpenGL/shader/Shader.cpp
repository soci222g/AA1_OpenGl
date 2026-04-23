#include "Shader.h"

std::string Shader::LoadPath(const std::string& filePath)
{
	std::ifstream file(filePath);
	std::string fileContet;
	std::string line;


	if (!file.is_open()) {
		std::cout << "error de llegir el archiu puto " << filePath << std::endl;
		std::exit(EXIT_FAILURE);
	}

	while (std::getline(file, line))
	{
		fileContet += line + "\n";
	}
	file.close();

	return fileContet;
}
