#include "loadRAW.h"

void loadRAW(std::string filename, int width, int height)
{
	char* imageData;
	int size;
	std::ifstream file(filename.c_str(), std::ios::in | std::ios::binary);
	if (!file)
	{
		std::cout << "*** Error opening image file: " << filename.c_str() << std::endl;
		exit(1);
	}

	size = width * height * 3;  //Total number of bytes to be read
	imageData = new char[size];
	file.read(imageData, size);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
	delete imageData;
}