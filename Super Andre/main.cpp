#include "DarkGDK.h"
#include "CONSTANTS.h"
#include "Functions.h"





void displayTiles(int map[][TILE_COLS], int rows);
void displayObstacles(int map[][TILE_COLS], int rows);
void detectCollision();
void memoryLeak();
void andreText();
void playMusic();
void loadGSM();
void move();




void DarkGDK()
{

	dbSetImageColorKey(0,255,0);
	loadGSM();
	playMusic();


	int heroX = dbSpriteX(HERO);
	int heroY = dbSpriteY(HERO);

	//Bottom Layer
	int tileMap[TILE_ROWS][TILE_COLS] =
	{	{TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP,  },
		{TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, },
		{GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, },
		{GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, },
	};

	

	//Sprite
	int obstacleMap[TILE_ROWS][TILE_COLS] =
	{	{TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP,  },
		{TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP, TOP,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, BRICK2, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, BRICK, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{PIPE, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, PIPE2, SKY, SKY, SKY, SKY,  },
		{SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, ENEMY, SKY, SKY, SKY, SKY, SKY, SKY, SKY, SKY,  },
		{GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, },
		{GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, },
		{GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, GROUND, },
	};




	
	

	while(LoopGDK() )
	{

		displayTiles(tileMap, TILE_ROWS);

		displayObstacles(obstacleMap, TILE_ROWS);

		dbSprite(BOARDER, 0, 0, BOARDER);
		dbSprite(BOARDER2, 630, 0, BOARDER2);
		dbSprite(INV, 0, 408, INV);

		move();

		detectCollision();


		dbSync();
	}
	
	dbSyncOff();
	memoryLeak();

	return;
}