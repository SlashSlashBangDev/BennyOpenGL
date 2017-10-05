#include <iostream>
#include "Display.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include "stb_image.h"

int main(int argc, char** argv) {

	Display display(640, 480, "Benny's  tutorial");
	display.MakeCurrent();
	glewInit();
	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5, -0.5,  0.0), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3( 0.0 ,  0.5, 0.0), glm::vec2(0.5, 1.0)),
		Vertex(glm::vec3( 0.5 , -0.5, 0.0), glm::vec2(1.0, 0.0)),
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./res/basicShader");
	Texture texture("brick.jpg");
	


	while (!display.ShouldClose()) {
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		shader.Bind();
		texture.Bind(0);
		mesh.Draw();
		
		
		display.Update();
	}

	return 0;
}