#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
class Tiles
{
public: 
	Tiles(uint32_t* sprite_tracker, int width, int height, int x, int y, int damage, int change_speed, int type, int new_x, int new_y, int key);
	int getWidth();
	int getHeight();
	int getX();
	int getY(); 
	int getDamage();
	int getType();
	int getKey();
	int getChangeSpeed();
	int getNewX();
	int getNewY();
	uint32_t* getSprite();
	void setX(int x);
	void setY(int y);
	void setSprite(uint32_t* sprite_tracker);
	void setWidth(int width);
	void setHeight(int height);
	void setDamage(int damage);
	void setChangeSpeed(int change_speed);
	void setType(int type);


private: 
	int x, y, width, height, damage, new_x, new_y;
	uint32_t* sprite_tracker;
	int change_speed;
	int key, type;

};

