#include <stdio.h>
#include <stdlib.h>

#include "CImg.h"
#include "MiniFB.h"
#include <iostream>
#include "View.h"
#include "Char_sprite.h"
#include "Character.h"
#include "Tiles.h"
#include "Stage.h"

#define WIDTH  1280
#define HEIGHT 720
#define CHAR_COUNT 4
#define TILE_COUNT 100

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
		
		if (key == KB_KEY_LEFT)
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
		else if (key == KB_KEY_ENTER)
		{
			type = 5;
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



void setUpStage(Stage *stage, View *graphics, Character *character, Tiles *tile[], Char_sprite *char_arr[], int level, int new_x, int new_y)
{
	CImg<unsigned char> bg(stage->getFileBg(level-1));
	printf("%d,%d\n", bg.width(), bg.height());
	uint8_t* bg_mem = bg.data();
	// Instantiate View Object
	graphics = new View(bg_mem);
	stage->setStage(level);
	char file[4][100] = { "assets/player_sprite_back-left-up.bmp", "assets/player_sprite_back-right-up.bmp","assets/player_sprite_front-left-down.bmp","assets/player_sprite_front-right-down.bmp" };
	int character_info[CHAR_COUNT][2] = { {0,1},{1,1},{0,0},{1,0} };
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
	character->setSprite(char_arr[3]->getSprite());
	character->setX(new_x);
	character->setY(new_y);
	graphics->displaySprite(character->getSprite(), character->getWidth(), character->getHeight(), character->getX(), character->getY());
	for (int i = 0; i < stage->getTileCount(); i++)
	{
		CImg<unsigned char> tile_sprite(stage->getFileTile(stage->getTileDetail(i,4) - 1));
		uint8_t* tile_data = tile_sprite.data();
		uint32_t* tile_pointer = graphics->loadSprite(tile_data, tile_sprite.width(), tile_sprite.height());
		tile[i] = new Tiles(tile_pointer, tile_sprite.width(), tile_sprite.height(), stage->getTileDetail(i, 0), stage->getTileDetail(i, 1), stage->getTileDetail(i, 2), stage->getTileDetail(i, 3), stage->getTileDetail(i, 4), stage->getTileDetail(i, 5), stage->getTileDetail(i, 6), i + 1);
		graphics->displaySprite(tile[i]->getSprite(), tile[i]->getWidth(), tile[i]->getHeight(), tile[i]->getX(), tile[i]->getY());
	}
}

int main()
{
	Stage *stage = new Stage();
	int level = 1;
	CImg<unsigned char> instruct(stage->getFilehowtoPlay(level-1));
	uint8_t* instruct_mem = instruct.data();
	View* graphics = new View(instruct_mem);
	struct mfb_window* window;
	window = mfb_open("Dungeon Crawler", WIDTH, HEIGHT);

	if (!window)
		return -1;
	do
	{
		mfb_set_keyboard_callback(window, keypress);
		int state = mfb_update_ex(window, graphics->getFrameBuffer(), WIDTH, HEIGHT);
		if (type == 5)
		{
			level++;
		}
		mfb_wait_sync(window);
	} while (level == 1);


	level = 1;
	CImg<unsigned char> bg(stage->getFileBg(level - 1));
	printf("%d,%d\n", bg.width(), bg.height());
	uint8_t* bg_mem = bg.data();
	graphics = new View(bg_mem);
	stage->setStage(level);
	char file[4][100] = { "assets/player_sprite_back-left-up.bmp", "assets/player_sprite_back-right-up.bmp","assets/player_sprite_front-left-down.bmp","assets/player_sprite_front-right-down.bmp" };
	int character_info[CHAR_COUNT][2] = { {0,1},{1,1},{0,0},{1,0} };
	Char_sprite* char_arr[CHAR_COUNT];
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
	Character *character = new Character(char_arr[3]->getSprite(), char_arr[3]->getWidth(), char_arr[3]->getHeight(), char_arr[3]->getXdir(), char_arr[3]->getYdir(), 40, 360, 3, x_move, y_move);
	graphics->displaySprite(character->getSprite(), character->getWidth(), character->getHeight(), character->getX(), character->getY());
	Tiles* tile[TILE_COUNT];
	for (int i = 0; i < stage->getTileCount(); i++)
	{
		CImg<unsigned char> tile_sprite(stage->getFileTile(stage->getTileDetail(i, 4) - 1));
		uint8_t* tile_data = tile_sprite.data();
		uint32_t* tile_pointer = graphics->loadSprite(tile_data, tile_sprite.width(), tile_sprite.height());
		tile[i] = new Tiles(tile_pointer, tile_sprite.width(), tile_sprite.height(), stage->getTileDetail(i, 0), stage->getTileDetail(i, 1), stage->getTileDetail(i, 2), stage->getTileDetail(i, 3), stage->getTileDetail(i, 4), stage->getTileDetail(i, 5), stage->getTileDetail(i, 6), i + 1);
		graphics->displaySprite(tile[i]->getSprite(), tile[i]->getWidth(), tile[i]->getHeight(), tile[i]->getX(), tile[i]->getY());
	}

	//For switch and stair setup
	CImg<unsigned char> switchSprite(stage->getFileTile(5));
	uint8_t* switch_data = switchSprite.data();
	uint32_t* switch_pointer = graphics->loadSprite(switch_data, switchSprite.width(), switchSprite.height());
	CImg<unsigned char> switchonSprite(stage->getFileTile(6));
	uint8_t* switchon_data = switchonSprite.data();
	uint32_t* switchon_pointer = graphics->loadSprite(switchon_data, switchonSprite.width(), switchonSprite.height());
	CImg<unsigned char> stairSprite(stage->getFileTile(4));
	uint8_t* stair_data = stairSprite.data();
	uint32_t* stair_pointer = graphics->loadSprite(stair_data, stairSprite.width(), stairSprite.height());
	CImg<unsigned char> normalSprite(stage->getFileTile(7));
	uint8_t* normal_data = normalSprite.data();
	uint32_t* normal_pointer = graphics->loadSprite(normal_data, normalSprite.width(), normalSprite.height());


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
		for (int i = 0; i < stage->getWallCount(); i++) {
			drawWall(character, stage->getXWallPos(i), stage->getYWallPos(i), stage->getWallWidth(i), stage->getWallHeight(i));
		}

		// Tile Algorithm
		int count, check =0;
		for (count =0; count< stage->getTileCount(); count++)
		{
			check = character->CheckTileCollision(tile[count]);
			if (check >= 1)
			{
				break;
			}
		}
		int changeOperation = 0;
		// For partial slow and spike and Full others
		if (check == 1)
		{
			if (tile[count]->getType() == 2) speed = tile[count]->getChangeSpeed();
			else speed = tile[count]->getChangeSpeed();
			character->CharacterDamage(tile[count]);
			changeOperation=graphics->moveCharacter(character, tile[count], check);
		}
		//For partial others except slow and spike
		else if(check == 2)
		{
			character->setInvul(0);
			speed = 10;
			changeOperation=graphics->moveCharacter(character, tile[count], check);
		}
		// No traps
		else {
			character->setInvul(0);
			speed = 10;
			graphics->moveCharacter(character);
		}

		if (changeOperation == 1)
		{
			level++;
			setUpStage(stage, graphics, character, tile, char_arr, level, tile[count]->getNewX(), tile[count]->getNewY());
		}
		else if (changeOperation == 2)
		{
			tile[stage->getTileCount() - 2]->setSprite(switch_pointer);
			tile[stage->getTileCount() - 2]->setType(6);
			graphics->changeTile(tile[stage->getTileCount() - 2]);
			tile[stage->getTileCount() - 1]->setSprite(normal_pointer);
			tile[stage->getTileCount() - 1]->setType(8);
			graphics->changeTile(tile[stage->getTileCount() - 1]);
		}
		else if (changeOperation == 3)
		{
			tile[count]->setSprite(switchon_pointer);
			tile[count]->setType(7);
			graphics->changeTile(tile[count]);
			tile[stage->getTileCount() -1]->setSprite(stair_pointer);
			tile[stage->getTileCount() - 1]->setType(5);
			graphics->changeTile(tile[stage->getTileCount() - 1]);
			graphics->displaySprite(character->getSprite(), character->getWidth(), character->getHeight(), character->getX(), character->getY());
		}
		else if (changeOperation == 4)
		{
			mfb_close(window);
			return 0;
		}
		
		if (type != 0)
		{
			printf("%d,%d\n", character->getX(), character->getY());
		}

		
		

	}while (mfb_wait_sync(window));
}