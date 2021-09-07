#include <stdio.h>
#include <stdlib.h>

#include "CImg.h"
#include "MiniFB.h"
#include <iostream>
#include "View.h"


#define WIDTH  1280
#define HEIGHT 720

using namespace cimg_library;

int main()
{
	CImg<unsigned char> bg("assets/background.bmp");
	uint8_t* bg_mem = bg.data();
	// Instantiate View Object
	View* graphics = new View(bg_mem);

	struct mfb_window* window;
	window = mfb_open("Dungeon Crawler", WIDTH, HEIGHT);
	if (!window)
		return -1;
	while (1)
	{

		mfb_update(window, graphics->getFrameBuffer());
		mfb_wait_sync(window);
	}
}