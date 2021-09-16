#pragma once

#define COUNT 100
class Stage
{
public:
	Stage();
	void setStage(int stage);
	void setDungeon1();
	void setDungeon2();
	void setDungeon3();
	void setDungeon4();
	void setPositionTile(int arr[][7], int count);
	void setPositionWallX(int arr[], int count);
	void setPositionWallY(int arr[], int count);
	void setPositionWallWidth(int arr[], int count);
	void setPositionWallHeight(int arr[], int count);
	const char* getFileBg(int i);
	const char* getFileTile(int i);
	const char* getFilehowtoPlay(int i);
	int getTileDetail(int i, int j);
	int getXWallPos(int i);
	int getYWallPos(int i);
	int getWallWidth(int i);
	int getWallHeight(int i);
	int getWallCount();
	int getTileCount();
private:
	char tileFile[10][100]= { "assets/pitfall.bmp", "assets/slow_tile.bmp","assets/spikes.bmp","assets/ladder.bmp","assets/staircase.bmp","assets/switch.bmp", "assets/switch_on.bmp", "assets/staircase_closed.bmp", "assets/chest.bmp"};
	char bgFile[4][100] = {"assets/dungeon_level_1.bmp","assets/dungeon_level_2.bmp","assets/dungeon_level_3.bmp","assets/dungeon_level_4.bmp"};
	char howtoPlay[2][100] = { "assets/how_to_play_1.bmp","assets/how_to_play_2.bmp" };
	int tileCount;
	int wallCount;
	int tileInfo[100][7];
	int wallXPos[100];
	int wallYPos[100];
	int wallWidth[100];
	int wallHeight[100];
	int initialX;
	int initialY;
};

