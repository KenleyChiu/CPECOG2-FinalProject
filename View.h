#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include "CImg.h"


#define WIDTH	1280
#define HEIGHT	720

class View
{
public:
	View(uint8_t* bg_mem);
	uint32_t* getFrameBuffer();
	uint32_t* loadSprite(uint8_t* sprite_data, int width, int height);


private:
	static uint32_t bg_arr[WIDTH * HEIGHT];
	static uint32_t frame[WIDTH * HEIGHT];
	static const size_t sprite_mem_size = 1000000;
	static uint32_t sprite_mem[sprite_mem_size];
	static uint32_t* sprite_mem_tracker;
	uint32_t* bgbuffer;
	uint32_t* framebuffer;
};

};
