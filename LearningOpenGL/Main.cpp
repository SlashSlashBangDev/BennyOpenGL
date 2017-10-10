 #include <iostream>
#include "Display.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"
#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include "stb_image.h"

#define WIDTH 800
#define HEIGHT 800

int main(int argc, char** argv) {

	Display display(800, 800, "Benny's  tutorial");
	display.MakeCurrent();
	glewInit();
	Vertex vertices[] = {
		Vertex(glm::vec3(-0.5, -0.5,  0.0), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3( 0.0 ,  0.5, 0.0), glm::vec2(0.5, 1.0)),
		Vertex(glm::vec3( 0.5 , -0.5, 0.0), glm::vec2(1.0, 0.0)),
	};

	unsigned int indices[] = { 0, 1, 2 };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices )/sizeof(indices[0]));
	Mesh monkeyMesh("./res/monkey3.obj");
	Shader shader("./res/basicShader");
	Texture texture("brick.jpg");
	Camera camera(glm::vec3(0, 0, -4), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);
	Transform transform;

	glEnable(GL_DEPTH_TEST);

	float counter = 0.0f;
	float sinCounter;
	float cosCounter;
	while (!display.ShouldClose()) {
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		sinCounter = sinf(counter);
		cosCounter = cosf(counter);

		transform.GetPosition().x = sinCounter;
		transform.GetPosition().z = cosCounter;
		transform.GetRotation().x = counter;
		transform.GetRotation().y = counter;
		transform.GetRotation().z = counter;
		//transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));
		shader.Bind();
		texture.Bind(0);
		shader.Update(transform, camera);
		monkeyMesh.Draw();
		
		
		display.Update();

		counter += 0.01f;
	}

	return 0;
}