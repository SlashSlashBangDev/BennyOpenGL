#include <iostream>
#include "Display.h"
#include "Mesh.h"
#include "Shader.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include "stb_image.h"

int main(int argc, char** argv) {

	Display display(640, 480, "Benny's  tutorial");
	display.MakeCurrent();
	glewInit();
	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5 , -0.5, 0.0)),
		Vertex(glm::vec3(0.0 , 0.5, 0.0)),
		Vertex(glm::vec3(0.5 , -0.5, 0.0)),
	};

	Shader shader("./res/basicShader");

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	int x, y, n;
	unsigned char * imageData = stbi_load("brick.jpg", &x, &y, &n, 4);

	if (imageData == NULL) {
		std::cerr << stbi_failure_reason() << std::endl;
	}
		


	while (!display.ShouldClose()) {
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		shader.Bind();
		mesh.Draw();
		display.Update();
	}

	return 0;
}