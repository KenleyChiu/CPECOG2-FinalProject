#include "View.h"

uint32_t  View::bg_arr[];
uint32_t  View::frame[];
uint32_t  View::sprite_mem[];
uint32_t* View::sprite_mem_tracker;
const size_t View::sprite_mem_size;

View::View(uint8_t* bg_mem)
{
	bgbuffer = bg_arr;
	framebuffer = frame;
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			uint8_t r = bg_mem[WIDTH * y + x];
			uint8_t g = bg_mem[WIDTH * y + x + WIDTH * HEIGHT];
			uint8_t b = bg_mem[WIDTH * y + x + 2 * WIDTH * HEIGHT];


			bgbuffer[WIDTH * (y)+(x)] = (r << 16) + (g << 8) + b;
			framebuffer[WIDTH * (y)+(x)] = bgbuffer[WIDTH * (y)+(x)];
		}
	}
	sprite_mem_tracker = sprite_mem;
}

uint32_t* View::getFrameBuffer()
{
	return framebuffer;
}
