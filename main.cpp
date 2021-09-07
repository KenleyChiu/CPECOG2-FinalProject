#include <stdio.h>
#include <stdlib.h>

#include "CImg.h"
#include "MiniFB.h"
#include <iostream>
#include "View.h"
#include "Character.h"


#define WIDTH  1280
#define HEIGHT 720
#define CHAR_COUNT 4

using namespace cimg_library;

int main()
{
	CImg<unsigned char> bg("assets/background.bmp");
	uint8_t* bg_mem = bg.data();
	// Instantiate View Object
	View* graphics = new View(bg_mem);
	char file[4][100] = { "assets/player_sprite_back-left-up.bmp", "assets/player_sprite_back-right-up.bmp","assets/player_sprite_front-left-down.bmp","assets/player_sprite_front-right-down.bmp" };
	int block_info[CHAR_COUNT][] = { {1060,300,0},{100,250,1},{800,200,1},{500,350,2},{1100,550,2},{850,600,3},{400,150,3},{200,500,3} };
	float factor[4] = { 0,2,0.5,1 };
	Character *sprite_arr[CHAR_COUNT];
	for (int i = 0; i < CHAR_COUNT; i++)
	{

	}
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