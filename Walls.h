#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
class Walls
{
public:
	Walls(int x, int y, uint32_t* sprite_tracker, int width, int height);
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	uint32_t* getSprite();
	void setX(int x);
	void setY(int y);
	void setSprite(uint32_t* sprite_tracker);
	void setWidth(int width);
	void setHeight(int height);

private:
	int x, y, width, height;
	uint32_t* sprite_tracker;

};


