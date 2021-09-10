#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Tiles.h"
class Character
{
public:
	Character(uint32_t* sprite_tracker, int width, int height, int Xdir, int Ydir, int x, int y, int health, int x_speed, int y_speed);
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	int getHealth();
	int getXdir();
	int getYdir();
	uint32_t* getSprite();
	int getInvul();
	int getXSpeed();
	int getYSpeed();
	void setInvul(int invul);
	void setX(int x);
	void setY(int y);
	void setSprite(uint32_t* sprite_tracker);
	void setWidth(int width);
	void setHeight(int height);
	void setHealth(int health);
	void setXdir(int Xdir);
	void setYdir(int Ydir);
	void changeXPos();
	void changeYPos();
	void setXspeed(int x_speed);
	void setYspeed(int y_speed);
	int CheckTileCollision(Tiles *tile);
	void ChangeCharacter(Tiles* tile);
	void changeYSpeed(int y_speed);
	void changeXSpeed(int x_speed);
private:
	int x, y, width, height, health, Xdir, Ydir, x_speed, y_speed, invul=0;
	uint32_t* sprite_tracker;
};

