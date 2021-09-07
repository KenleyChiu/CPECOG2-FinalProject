#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
class Tiles
{
public: 
	Tiles(int x, int y, uint32_t* sprite_tracker, int width, int height, int damage, float change_speed);
	int getWidth();
	int getHeight();
	int getX();
	int getY(); 
	int getDamage();
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
	float change_speed; 

};

