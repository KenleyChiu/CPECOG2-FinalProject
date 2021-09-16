#include "Stage.h"



Stage::Stage()
{

}

void Stage::setStage(int stage)
{
	switch (stage)
	{
	case 1: setDungeon1();
		break;
	case 2: setDungeon2();
		break;
	case 3: setDungeon3();
		break;
	case 4: setDungeon4();
		break;
	default:
		break;
	}
}
void Stage::setDungeon2()
{
	int tile_info[COUNT][7] = {
		//Instant death (27)
		{320,80,3,10,1,40,80}
		,{360,160,3,10,1,40,80}
		,{240,160,3,10,1,40,80}
		,{280,240,3,10,1,40,80}
		,{320,320,3,10,1,40,80}
		,{280,400,3,10,1,40,80}
		,{160,240,3,10,1,40,80}
		,{80,440,3,10,1,40,80}
		,{80,560,3,10,1,40,80}
		,{200,480,3,10,1,40,80}
		,{240,560,3,10,1,40,80}
		,{360,440,3,10,1,40,80}
		,{320,520,3,10,1,40,80}
		,{840,600,3,10,1,40,80}
		,{560,40,3,10,1,40,80}
		,{520,160,3,10,1,40,80}
		,{640,200,3,10,1,40,80}
		,{440,360,3,10,1,40,80}
		,{560,360,3,10,1,40,80}
		,{1200,600,3,10,1,40,80}
		,{1120,480,3,10,1,40,80}
		,{960,280,3,10,1,40,80}
		,{1160,280,3,10,1,40,80}
		,{1040,200,3,10,1,40,80}
		,{1040,200,3,10,1,40,80}
		,{1200,160,3,10,1,40,80}
		,{960,120,3,10,1,40,80}
		//Instant damage (19)
		,{480,560,1,10,3,40,80}
		,{600,600,1,10,3,40,80}
		,{760,560,1,10,3,40,80}
		,{480,40,1,10,3,40,80}
		,{560,80,1,10,3,40,80}
		,{440,120,1,10,3,40,80}
		,{440,200,1,10,3,40,80}
		,{560,200,1,10,3,40,80}
		,{600,280,1,10,3,40,80}
		,{480,280,1,10,3,40,80}
		,{520,320,1,10,3,40,80}
		,{440,400,1,10,3,40,80}
		,{520,440,1,10,3,40,80}
		,{1200,480,1,10,3,40,80}
		,{1120,560,1,10,3,40,80}
		,{1080,240,1,10,3,40,80}
		,{1200,280,1,10,3,40,80}
		,{1160,200,1,10,3,40,80}
		,{1000,320,1,10,3,40,80}
		
		//Access to next Level (1)
		,{440,440,0,10,6,40,80}
		//next Level (1)
		,{1200,40,0,10,8,40,360}
	};
	int wall_XPos[COUNT] = { 400,   400,   680,   790,   790,   950,   910,   910,   1080,   1080,   1080,   1070,   1070,   1200,   400,   230,   160,   10,   10,   690,   760 };
	int wall_YPos[COUNT] = { 0,     510,   150,   150,   510,   510,   0,     390,   390,    390,    640,    0,      110,    110,    640,   150,   350,   360,  150,  150,   150 };
	int wall_Width[COUNT]= { 10,  280, 10 ,  10, 130,  10,  10,   80,    10,   200,    10,   10 ,  50 ,   50,    10,  10,   70,   70,  200,    20,  20 };
	int wall_Height[COUNT] = { 530, 10, 370, 370,  10, 120, 410,   10,   180,    20,    10,   120,   10,   10,    50, 220,   20,   10,   10,    10,  10 };
	wallCount = 21;
	tileCount = 48;
	setPositionTile(tile_info, tileCount);
	setPositionWallX(wall_XPos, wallCount);
	setPositionWallY(wall_YPos, wallCount);
	setPositionWallWidth(wall_Width, wallCount);
	setPositionWallHeight(wall_Height, wallCount);
}

void Stage::setDungeon1()
{
	int tile_info[COUNT][7] = 
	{
		//Instant Damage
		{1040,400,1,10,3,40,360},
		{880,200,1,10,3,40,360},
		{1160,440,1,10,3,40,360},
		{800,480,1,10,3,40,360},

		//Instant Death
		{1040,240,3,10,1,40,360},
		{840,240,3,10,1,40,360},
		{1000,280,3,10,1,40,360},
		{1000,440,3,10,1,40,360},
		{960,480,3,10,1,40,360},

		//Slow
		{1160, 280,0,5,2,40,360},
		{1120,200,0,5,2,40,360},
		{1200,200,0,5,2,40,360},
		{920,280,0,5,2,40,360},
		{800,400,0,5,2,40,360},
		{1080,440,0,5,2,40,360},
		{880,480,0,5,2,40,360},

		
		//Teleport (2)
		{160,80,0,10,4,360,360},
		{320,360,0,10,4,160,120},

		//Access To next Level (1)
		{920,80,0,10,6,40,360},
		//Next Level (1)
		{520,200,0,10,8,40,80}
	};
	int wall_XPos[COUNT] = { 110,    200,  30,  30,   110, 200,    200,  920, 810, 790,  590,   390, 360,  200, 200, 520,  270, 110, 800 };
	int wall_YPos[COUNT] = { 40,     40,  280, 430,   430, 430,    550,  350, 150,  30,  100,   120, 100,  270, 430, 270,  265,  40,  40 };
	int wall_Width[COUNT] = { 10,     10,   70,  70,    10,  10,    960,  320, 345,  10,   10,   180,  10,  250, 360,  50,   10,  60, 470 };
	int wall_Height[COUNT] = { 240,    240,   10,  10,   250,  140,    10,   10,  10,  530, 310,    10,  140,  10,  10,  10,   135, 10,  10 };
	wallCount = 19;
	tileCount = 20;
	setPositionTile(tile_info, tileCount);
	setPositionWallX(wall_XPos, wallCount);
	setPositionWallY(wall_YPos, wallCount);
	setPositionWallWidth(wall_Width, wallCount);
	setPositionWallHeight(wall_Height, wallCount);
}

void Stage::setDungeon3()
{
	int tile_info[COUNT][7] =
	{
		//Instant Death (1)
		{320,320,3,10,1,40,360}
		//Teleport Ladder Path 1 Green (4)
		,{80,120,0,10,4,560,600}
		,{520,600,0,10,4,120,120}
		,{760,560,0,10,4,1000,400}
		,{960,400,0,10,4,800,560} 
		//Teleport Ladder Path 2 Red (6)
		,{200,120,0,10,4,1000,200}
		,{960,200,0,10,4,240,120}
		,{1160,120,0,10,4,960,600}
		,{920,600,0,10,4,1200,120}
		,{1200,560,0,10,4,800,360}
		,{760,360,0,10,4,1160,560}
		//Teleport Ladder Path 3 Blue (4)
		,{320,120,0,10,4,560,200}
		,{520,200,0,10,4,360,120}
		,{760,120,0,10,4,120,600}
		,{80,600,0,10,4,800,120}
		//Access to next Level (1)
		,{280,600,0,10,6,40,360}
		//Next Level (1)
		,{520,400,0,10,8, 600,600}
	};
	int wall_XPos[COUNT] = { 10   , 10    , 280,   880,  430 ,  10 };
	int wall_YPos[COUNT] = { 40   ,  470  ,  275,   20,   20 ,  275 };
	int wall_Width[COUNT] = { 1260,   1260,   970,  10,   10 ,   150 };
	int wall_Height[COUNT] = { 10 ,    10 ,   10 ,  690,   690,   10 };
	wallCount = 6;
	tileCount = 17;
	setPositionTile(tile_info, tileCount);
	setPositionWallX(wall_XPos, wallCount);
	setPositionWallY(wall_YPos, wallCount);
	setPositionWallWidth(wall_Width, wallCount);
	setPositionWallHeight(wall_Height, wallCount);
}

void Stage::setDungeon4()
{
	int tile_info[COUNT][7] = {{500,320,0,10,9,40,360}};
	int wall_XPos[COUNT] = { 200 ,    360 ,  910 };
	int wall_YPos[COUNT] = { 40   ,    60 ,  60 };
	int wall_Width[COUNT] = { 1030 ,   10  ,  10 };
	int wall_Height[COUNT] = { 10   ,  570  , 570 };
	wallCount = 31;
	tileCount = 1;
	setPositionTile(tile_info, tileCount);
	setPositionWallX(wall_XPos, wallCount);
	setPositionWallY(wall_YPos, wallCount);
	setPositionWallWidth(wall_Width, wallCount);
	setPositionWallHeight(wall_Height, wallCount);
}

void Stage::setPositionWallX(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		wallXPos[i] = arr[i];
	}
}

void Stage::setPositionWallY(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		wallYPos[i] = arr[i];
	}
}

void Stage::setPositionWallWidth(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		wallWidth[i] = arr[i];
	}
}

void Stage::setPositionWallHeight(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		wallHeight[i] = arr[i];
	}
}

const char* Stage::getFileBg(int i)
{
	return bgFile[i];
}

const char* Stage::getFileTile(int i)
{
	return tileFile[i];
}

const char* Stage::getFilehowtoPlay(int i)
{
	return howtoPlay[i];
}

int Stage::getTileDetail(int i, int j)
{
	return tileInfo[i][j];
}

int Stage::getXWallPos(int i)
{
	return wallXPos[i];
}

int Stage::getYWallPos(int i)
{
	return wallYPos[i];
}

int Stage::getWallWidth(int i)
{
	return wallWidth[i];
}

int Stage::getWallHeight(int i)
{
	return wallHeight[i];
}

int Stage::getWallCount()
{
	return wallCount;
}

int Stage::getTileCount()
{
	return tileCount;
}

void Stage::setPositionTile(int arr[][7], int count)
{
	for (int i = 0; i < count; i++)
	{
		for(int j = 0; j < 7; j++)
		tileInfo[i][j] = arr[i][j];
	}
}

