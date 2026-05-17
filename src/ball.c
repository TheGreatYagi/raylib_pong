#include "ball.h"
#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const Color ballColor = {250, 245, 36,255}; //golden
const int MAX_RIGHT = 1280; // 
const int MAX_LEFT = 0; // 
const int MAX_UP = 0;
const int MAX_DOWN = 800;

void updateBall(Ball* ball, Player* player, Player* comm) {
	// 0,0 is upper left
	// x: 1 is right, 0 is left
	// y: 1 is down, 0 is up

	// handle left/right
	//printf("UPDATEBALL[-] stats vx:%d vy:%d x:%d y:%d\n", ball->vel_x, ball->vel_y, ball->pos_x, ball->pos_y);
	if ((ball->vel_x == 1) && (ball->pos_x < MAX_RIGHT)) { //move to the right
		ball->pos_x = ball->pos_x + 1;
		//printf("ball should move right, pos_x is now: %d\n", ball->pos_x);
	} else if ((ball->vel_x ==1) && (ball->pos_x == MAX_RIGHT)) { 
		//handle update player score
		//for now change directions
		ball->vel_x = 0;
		ball->pos_x = ball->pos_x+1;
		//printf("ball will now move left\n"); 
	} else if ((ball->vel_x == 0) && (ball->pos_x > MAX_LEFT)) {// move to left 
		ball->pos_x = ball->pos_x - 1;
		//printf("ball should move left, pos_x is now: %d\n", ball->pos_x);
	} else if ((ball->vel_x == 0) && (ball->pos_x == MAX_LEFT)) {
		// handle update comm score
		// for now change directions
		ball->vel_x = 1;
		//printf("ball will now move right\n"); 
		ball->pos_x = ball->pos_x+1;
	}

	// handle up/down

	if ((ball->vel_y == 1) && (ball->pos_y < MAX_DOWN)) { //move down
		ball->pos_y += 1;
		//printf("ball should move down, pos_y is now: %d\n", ball->pos_y);
	} else if ((ball->vel_y == 1) && (ball->pos_y == MAX_DOWN)) {
		//printf("ball will now move up\n"); 
		ball->vel_y = 0; //swap direction
	} else if ((ball->vel_y == 0) && (ball->pos_y > MAX_UP)) {// move up
		ball->pos_y -= 1;
		//printf("ball should move up, pos_y is now: %d\n", ball->pos_y);
	} else if ((ball->vel_y == 0) && (ball->pos_y == MAX_UP)) {
		ball->vel_y = 1;
		//printf("ball will now move down\n"); 
	}
	//printf("\n\n");

	//handle player collision
	//player h:104, w:18
	//shapes always start in upper left corner
	//0,0 is top left
	// lower y is higher in frame
	//printf("player->x is %d, ball->pos_x is %d\n", player->x, ball->pos_x);
	if (ball->pos_x == player->x + player->width) { //check if we are at player border
		//printf("player->y is %d, ball->pos_y is %d\n", player->y, ball->pos_y);
		// y:123, pos_y: 283
		if ( ( player->y <= ball->pos_y ) && ((player->y + player->height) >= ball->pos_y)) { //check if player height is where ball should be
			ball->vel_x = 1;
		}
		//ball->vel_x = !ball->vel_x;
	}

	// printf("comm->x is %d, ball->pos_x is %d\n", comm->x, ball->pos_x);
	if (ball->pos_x == comm->x - comm->width/4) {
		// printf("comm->y is %d, ball->pos_y is %d\n", comm->y, ball->pos_y);
		if ( ( comm->y <= ball->pos_y ) && ((comm->y + comm->height) >= ball->pos_y)) { //check if player height is where ball should be
			ball->vel_x = 0;
		}
		//ball->vel_x = !ball->vel_x;

	}
	
}



void drawBall(struct Ball* ball) {
	DrawCircle(ball->pos_x, ball->pos_y, ball->radius, ball->color);
}


struct Ball buildBall(float radius, int x, int y, Color color) {
	srand(time(NULL));
	Ball tmp = {radius, x, y, rand() % 2, rand() % 2, color};
	// test left down
	//Ball tmp = {radius, x, y, 0, 1, color};
	return tmp;
}

