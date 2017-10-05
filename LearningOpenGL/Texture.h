#pragma once

#include "GL/glew.h"
#include "stb_image.h"
#include <string>
#include <cassert>
#include <iostream>




class Texture
{
public:
	Texture(const std::string& fileName);
	void Bind(unsigned int unit);
	~Texture();
private:
	GLuint m_texture;


};

