#ifndef BALL_H
#define BALL_H
#pragma once

#include <raylib.h>
#include "player.h"
#include "score.h"

extern const Color ballColor;
extern const int MAX_RIGHT;
extern const int MAX_LEFT;
extern const int MAX_UP;
extern const int MAX_DOWN;

typedef struct Ball {
	float radius;
	int pos_x;
	int pos_y;
	int vel_x;
	int vel_y;
	Color color;
	int delta;
}Ball; 


void drawBall(Ball* ball);
struct Ball buildBall(float radius, int x, int y, Color color);
void updateBall(Ball* ball, Player* player, Player* comm, Score* score);



#endif