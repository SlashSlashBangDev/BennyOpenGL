#include <iostream>
#include "Display.h"

int main(int argc, char** argv) {

	Display display(640, 480, "Benny's shit tutorial");
	display.MakeCurrent();

	while (!display.ShouldClose()) {
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
		// go here -> https://www.youtube.com/watch?v=0jML5fMBDGg
		display.Update();
	}

	return 0;
}