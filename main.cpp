#include <stdio.h>
#include <stdlib.h>

#include "CImg.h"
#include "MiniFB.h"
#include <iostream>
#include "View.h"
#include "Char_sprite.h"
#include "Character.h"
#include "Tiles.h"


#define WIDTH  1280
#define HEIGHT 720
#define CHAR_COUNT 4
#define TILE_COUNT 5

int speed = 10;
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
			x_move= -speed;
			y_move = 0;
			xdir = 0;
			type = 1;
		}
		else if (key == KB_KEY_RIGHT)
		{
			x_move = speed;
			y_move = 0;
			xdir = 1;
			type = 2;
		}
		else if (key == KB_KEY_UP)
		{
			x_move = 0;
			y_move = -speed;
			ydir = 1;
			type = 3;
		}
		else if (key == KB_KEY_DOWN)
		{
			x_move = 0;
			y_move = speed;
			ydir = 0;
			type = 4;
		}
	}
}

void drawWall(Character* character, int xpos, int ypos, int width, int height) {

	
	if ((character->getX() + x_move < xpos + width && character->getX() + 40 + x_move > xpos && character->getY() < ypos + height +10 && character->getY() + 40 > ypos)) {
		character->setXspeed(0);
		character->setYspeed(0);
	}
	
	else if ((character->getY() + y_move < ypos + height + 10 && character->getY() + 40 + y_move > ypos && character->getX() < xpos + width && character->getX() + 40 > xpos)) {
		character->setXspeed(0);
		character->setYspeed(0);
	}

	if (character->getX() + x_move < 10) {
		character->setXspeed(0);
	}
	else if (character->getX() + x_move > WIDTH - 45) {
		character->setXspeed(0);
	}
	else if (character->getY() + y_move < 30) {
		character->setYspeed(0);
	}
	else if (character->getY() + y_move > HEIGHT - 85) {
		character->setYspeed(0);
	}

}

int main()
{
	int prev_count =0;
	//CImg<unsigned char> bg("assets/background.bmp");
	CImg<unsigned char> bg("assets/dungeon_level_1.bmp");
	printf("%d,%d\n",bg.width(),bg.height());
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

	int wallPosX[21] = { 400,   400,   680,   790,   790,   950,   910,   910,   1080,   1080,   1080,   1070,   1070,   1200,   400,   230,   160,   10,   10,   690,   760};
	int wallPosY[21] = { 0,     510,   150,   150,   510,   510,   0,     390,   390,    390,    640,    0,      110,    110,    640,   150,   350,   360,  150,  150,   150};
	int wallWidth[21] = { 10,  280, 10 ,  10, 130,  10,  10,   80,    10,   200,    10,   10 ,  50 ,   50,    10,  10,   70,   70,  200,    20,  20 };
	int wallHeight[21] = { 530, 10, 370, 370,  10, 120, 410,   10,   180,    20,    10,   120,   10,   10,    50, 220,   20,   10,   10,    10,  10 };

	Tiles* tile[TILE_COUNT];
	char tile_file[4][100] = { "assets/pitfall.bmp", "assets/slow.bmp","assets/spikes.bmp","assets/potion.bmp" };
	int tile_info[TILE_COUNT][5] = {{320,320,3,10,1},{320,240,0,5,2},{100,200,1,10,3},{300,520,0,10,4},{240,100,0,5,2}};
	for (int i = 0; i < TILE_COUNT; i++)
	{
		CImg<unsigned char> tile_sprite(tile_file[(tile_info[i][4])-1]);
		uint8_t* tile_data = tile_sprite.data();
		uint32_t* tile_pointer = graphics->loadSprite(tile_data, tile_sprite.width(), tile_sprite.height());
		tile[i] = new Tiles(tile_pointer, tile_sprite.width(), tile_sprite.height(), tile_info[i][0], tile_info[i][1], tile_info[i][2], tile_info[i][3], tile_info[i][4], i+1);
		graphics->displaySprite(tile[i]->getSprite(), tile[i]->getWidth(), tile[i]->getHeight(), tile[i]->getX(), tile[i]->getY());
	}
	

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

		// Wall Algorithm
		/*for (int i = 0; i < 21; i++) {
			drawWall(character, wallPosX[i], wallPosY[i], wallWidth[i], wallHeight[i]);
		}*/

		// Tile Algorithm
		/*int count, check =0;
		for (count =0; count< 5; count++)
		{
			check = character->CheckTileCollision(tile[count]);
			if (check >= 1)
			{
				break;
			}
		}
		

		if (check == 1)
		{
			if (tile[count]->getType() == 2) speed = tile[count]->getChangeSpeed();
			else speed = tile[count]->getChangeSpeed();
			character->ChangeCharacter(tile[count]);
			prev_count = count;
		}
		else
		{
			character->setInvul(0);
			speed = 10;
			count = prev_count;
			
		}*/
		
		//graphics->moveCharacter(character,tile[count],check);
		graphics->moveCharacter(character);
		if (type != 0)
		{
			printf("%d,%d\n", character->getXSpeed(), character->getYSpeed());
			printf("%d,%d\n", character->getX(), character->getY());
		}
		

	}while (mfb_wait_sync(window));
}