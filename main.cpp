#include <stdio.h>
#include <stdlib.h>

#include "CImg.h"
#include "MiniFB.h"
#include <iostream>
#include "View.h"
#include "Char_sprite.h"
#include "Character.h"


#define WIDTH  1280
#define HEIGHT 720
#define CHAR_COUNT 4

int x_move = 0;
int y_move = 0;
int xdir = 0;
int ydir = 0;
int type = 0;

using namespace cimg_library;




void keypress(struct mfb_window* window, mfb_key key, mfb_key_mod mod, bool isPressed)
{
	if (isPressed) {
		if (key == KB_KEY_ESCAPE)
		{
			mfb_close(window);
		}
		else if (key == KB_KEY_LEFT)
		{
			x_move= -40;
			y_move = 0;
			xdir = 0;
			type = 1;

		}
		else if (key == KB_KEY_RIGHT)
		{
			x_move = 40;
			y_move = 0;
			xdir = 1;
			type = 2;
		}
		else if (key == KB_KEY_UP)
		{
			x_move = 0;
			y_move = -40;
			ydir = 1;
			type = 3;
		}
		else if (key == KB_KEY_DOWN)
		{
			x_move = 0;
			y_move = 40;
			ydir = 0;
			type = 4;
		}
	}
}



int main()
{
	x_move = 40;
	CImg<unsigned char> bg("assets/background.bmp");
	uint8_t* bg_mem = bg.data();
	// Instantiate View Object
	View* graphics = new View(bg_mem);
	char file[4][100] = { "assets/player_sprite_back-left-up.bmp", "assets/player_sprite_back-right-up.bmp","assets/player_sprite_front-left-down.bmp","assets/player_sprite_front-right-down.bmp"};
	int character_info[CHAR_COUNT][2] = { {0,1},{1,1},{0,0},{1,0}};
	Char_sprite *char_arr[CHAR_COUNT];
	for (int i = 0; i < CHAR_COUNT; i++)
	{
		CImg<unsigned char> character_sprite(file[i]);
		uint8_t* char_data = character_sprite.data();
		// Load block to sprite memory
		uint32_t* character_pointer = graphics->loadSprite(char_data, character_sprite.width(), character_sprite.height());
		//Instantiate Block Object
		printf("%d,%d\n", character_sprite.width(), character_sprite.height());
		char_arr[i] = new Char_sprite(character_pointer, character_sprite.width(), character_sprite.height(), character_info[i][0], character_info[i][1]);
	}
	Character* character = new Character(char_arr[3]->getSprite(), char_arr[3]->getWidth(), char_arr[3]->getHeight(), char_arr[3]->getXdir(), char_arr[3]->getYdir(),40,40,3, x_move, y_move);
	graphics->displaySprite(character->getSprite(), character->getWidth(), character->getHeight(), character->getX(), character->getY());
	struct mfb_window* window;
	window = mfb_open("Dungeon Crawler", WIDTH, HEIGHT);
	
	if (!window)
		return -1;
	do
	{
		x_move = 0;
		y_move = 0;
		type = 0;
		mfb_set_keyboard_callback(window, keypress);
		int state = mfb_update_ex(window, graphics->getFrameBuffer(), WIDTH, HEIGHT);
		character->setXspeed(x_move);
		character->setYspeed(y_move);
		if (type == 1)
		{
			character->setXdir(xdir);
			if (character->getYdir()) character->setSprite(char_arr[0]->getSprite());
			else character->setSprite(char_arr[2]->getSprite());
			
		}
		else if (type == 2)
		{
			character->setXdir(xdir);
			if (character->getYdir()) character->setSprite(char_arr[1]->getSprite());
			else character->setSprite(char_arr[3]->getSprite());
		}
		else if (type == 3)
		{
			character->setYdir(ydir);
			if (character->getXdir()) character->setSprite(char_arr[1]->getSprite());
			else character->setSprite(char_arr[0]->getSprite());
		}
		else if (type == 4)
		{
			character->setYdir(ydir);
			if (character->getXdir()) character->setSprite(char_arr[3]->getSprite());
			else character->setSprite(char_arr[2]->getSprite());
		}
		graphics->moveCharacter(character);

	}while (mfb_wait_sync(window));
}