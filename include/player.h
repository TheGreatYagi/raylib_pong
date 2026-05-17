#ifndef PLAYER_H
#define PLAYER_H


#include <raylib.h>

extern const Color playerColor;
extern const Color comPlayer;


typedef struct Player {
	int height;
	int width;
	int x;
	int y;
	Color color;
}Player;

void updatePlayer(struct Player* player, int direction) ;
void drawPlayer(struct Player* player);
struct Player buildPlayer(int height, int width, int x, int y, Color color);


#endif