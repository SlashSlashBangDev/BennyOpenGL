#pragma once

#include <string>
#include "GL/glew.h"
#include "GLFW\glfw3.h"

class Display
{
public:
	Display( int width, int height, const std::string& title);
	void MakeCurrent();
	void Clear(float r, float g, float b, float a);
	void Update();
	bool ShouldClose();
	void SetShouldClose();
	virtual ~Display();
private:

	GLFWwindow * m_window;
};

