#include "player.h"
#include <stdio.h>

const Color playerColor = {17, 207, 93, 255}; //light green
const Color comColor = {232, 2, 2, 255}; //dark red

//player size h:104, w:17

void updatePlayer(Player* player, int direction) {

	// y: 1 is down, 0 is up
	//printf("moving player from %d, dir is %d\n", player->y, direction);
	if ((direction == 0) && (player->y > 0)) {

		player->y = player->y - 3;
		if (player->y < 0) player->y = 0;
	} 
	if ((direction == 1) && (player->y <= 800-105+3)) {
		player->y = player->y + 3;
	}
	//printf("\n\n");
}

void drawPlayer(struct Player* player) {
	DrawRectangle(player->x, player->y, player->width, player->height, player->color);
}

struct Player buildPlayer(int height, int width, int x, int y, Color color) {
	Player tmp = {height, width, x, y, color};
	return tmp;
}