#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
class Tiles
{
public: 
	Tiles(uint32_t* sprite_tracker, int width, int height, int x, int y, int damage, int change_speed, int type, int key);
	int getWidth();
	int getHeight();
	int getX();
	int getY(); 
	int getDamage();
	int getType();
	int getKey();
	float getChangeSpeed();
	uint32_t* getSprite();
	void setX(int x);
	void setY(int y);
	void setSprite(uint32_t* sprite_tracker);
	void setWidth(int width);
	void setHeight(int height);
	void setDamage(int damage);
	void setChangeSpeed(float change_speed);

private: 
	int x, y, width, height, damage;
	uint32_t* sprite_tracker;
	int change_speed;
	int key, type;

};

