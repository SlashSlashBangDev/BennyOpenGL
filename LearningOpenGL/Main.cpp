#include <iostream>
#include "Display.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include "stb_image.h"

int main(int argc, char** argv) {

	Display display(640, 480, "Benny's shit tutorial");
	display.MakeCurrent();
	int x, y, n;
	unsigned char * imageData = stbi_load("brick.jpg", &x, &y, &n, 4);

	if (imageData == NULL) {
		std::cerr << stbi_failure_reason() << std::endl;
	}
		


	while (!display.ShouldClose()) {
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
		// go here -> https://www.youtube.com/watch?v=0jML5fMBDGg
		display.Update();
	}

	return 0;
}