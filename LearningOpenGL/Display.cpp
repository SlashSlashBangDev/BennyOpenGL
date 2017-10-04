#include "Display.h"



Display::Display(int width, int height, const std::string& title)
{
	glfwInit();

	m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	
}

void Display::MakeCurrent() {
	glfwMakeContextCurrent(m_window);
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Display::Update()
{
	glfwSwapBuffers(m_window);

	/* Poll for and process events */
	glfwPollEvents();
}

bool Display::ShouldClose() {
	return glfwWindowShouldClose(m_window);
}

void Display::SetShouldClose()
{
	glfwSetWindowShouldClose(m_window, 1);
}


Display::~Display()
{

	glfwDestroyWindow(m_window);
	glfwTerminate();
}
