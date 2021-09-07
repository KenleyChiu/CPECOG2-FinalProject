#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Char_sprite
{
public:
	Char_sprite(uint32_t* sprite_tracker, int width, int height, int Xdir, int Ydir);
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	int getHealth();
	int getXdir();
	int getYdir();
	uint32_t* getSprite();
	void setX(int x);
	void setY(int y);
	void setSprite(uint32_t* sprite_tracker);
	void setWidth(int width);
	void setHeight(int height);
	void setHealth(int health);
	void setXdir(int Xdir);
	void setYdir(int Ydir);

private:
	int x, y, width, height, health, Xdir, Ydir;
	uint32_t* sprite_tracker;

};

