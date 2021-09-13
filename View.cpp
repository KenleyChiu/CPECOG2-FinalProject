#include "View.h"


uint32_t  View::bg_arr[];
uint32_t  View::frame[];
uint32_t  View::sprite_mem[];
uint32_t* View::sprite_mem_tracker;
const size_t View::sprite_mem_size;

View::View()
{
}

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

uint32_t* View::loadSprite(uint8_t* sprite_data, int width, int height)
{
	uint32_t* sprite_tracker = sprite_mem_tracker;

	for (int x = 0; x != width; x++)
	{
		for (int y = 0; y != height; y++)
		{
			uint32_t r = sprite_data[width * y + x];
			uint32_t g = sprite_data[width * y + x + width * height];
			uint32_t b = sprite_data[width * y + x + 2 * width * height];
			uint32_t pixels = (r << 16) + (g << 8) + b;
			sprite_tracker[width * (y)+(x)] = pixels;
		}
	}
	sprite_mem_tracker += (width * height);
	return sprite_tracker;
}

void View::displaySprite(uint32_t* sprite, int width, int height, int current_x, int current_y)
{
	for (int y = 0; y != height; y++)
	{
		for (int x = 0; x != width; x++)
		{
			if (sprite[width * y + x] != 0)
				framebuffer[WIDTH * (current_y + y) + (current_x + x)] = sprite[width * y + x];
		}
	}
}

void View::displayTile(uint32_t* sprite, int width, int height, int current_x, int current_y)
{
	for (int y = 0; y != height; y++)
	{
		for (int x = 0; x != width; x++)
		{
			if (sprite[width * y + x] != 0)
				framebuffer[WIDTH * (current_y + y) + (current_x + x)] = sprite[width * y + x];
		}
	}
}

void View::changeTile(Tiles* tile)
{
	for (int x = 0; x != tile->getWidth(); x++)
	{
		for (int y = 0; y != tile->getHeight(); y++)
		{
			framebuffer[WIDTH * (tile->getY() + y) + (tile->getX() + x)] = bgbuffer[WIDTH * (tile->getY() + y) + (tile->getX() + x)];
		}
	}
	displaySprite(tile->getSprite(), tile->getWidth(), tile->getHeight(), tile->getX(), tile->getY());
}

int View::moveCharacter(Character* character, Tiles *tile,int type)
{

	for (int x = 0; x != character->getWidth(); x++)
	{
		for (int y = 0; y != character->getHeight(); y++)
		{
			framebuffer[WIDTH * (character->getY() + y) + (character->getX() + x)] = bgbuffer[WIDTH * (character->getY() + y) + (character->getX() + x)];
		}
	}

	displaySprite(tile->getSprite(), tile->getWidth(), tile->getHeight(), tile->getX(), tile->getY());

	if (tile->getType() == 5 && type == 1)
	{
		character->setX(tile->getNewX());
		character->setY(tile->getNewY());
		return 1;
	}

	else if (tile->getType() == 4 && type == 1)
	{
		character->setX(tile->getNewX());
		character->setY(tile->getNewY());
	}
	else if (character->getHealth() <= 0)
	{
		character->setX(tile->getNewX());
		character->setY(tile->getNewY());
		character->setHealth(3);
		displaySprite(character->getSprite(), character->getWidth(), character->getHeight(), character->getX(), character->getY());
		return 2;
	}
	else if (tile->getType() == 6 && type == 1)
	{
		character->changeXPos();
		character->changeYPos();
		return 3;
	}
	else
	{
		character->changeXPos();
		character->changeYPos();
	}
	
	displaySprite(character->getSprite(), character->getWidth(), character->getHeight(), character->getX(), character->getY());
	return 0;
}

void View::moveCharacter(Character* character)
{

	for (int x = 0; x != character->getWidth(); x++)
	{
		for (int y = 0; y != character->getHeight(); y++)
		{
			framebuffer[WIDTH * (character->getY() + y) + (character->getX() + x)] = bgbuffer[WIDTH * (character->getY() + y) + (character->getX() + x)];
		}
	}

	character->changeXPos();

	character->changeYPos();

	displaySprite(character->getSprite(), character->getWidth(), character->getHeight(), character->getX(), character->getY());
}