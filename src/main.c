#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

// custom includes
#include "player.h"
#include "ball.h"
#include "comm.h"
#include "score.h"


const int w = 1280;
const int h = 800;

// set colors
// https://rgbcolorpicker.com/
const Color bgColor = {77, 92, 140, 127}; //steel blue


int main() {
	//printf("successfully imported raylib");
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(w,h,"pong");
	SetTargetFPS(120);
	
	Player player = buildPlayer(104, 18, GetScreenWidth()/8-120, GetScreenHeight()/2, playerColor);
	Player comm = buildPlayer(104, 18,w - 50, GetScreenHeight()/2, playerColor);
	Ball ball = buildBall(8.5, GetScreenWidth()/2, GetScreenHeight()/2, ballColor);
	Score score = {0,0};
	//printf("Ball directions, x: %d, y:%d\n",ball.vel_x, ball.vel_y);
	bool gameStart = 0;
	while (!WindowShouldClose()) { 
		//setup game
		while(!gameStart) { //title screen
			BeginDrawing();
			ClearBackground(bgColor);
			DrawText(TextFormat("Press Space to start!\nFirst to 5 wins!"), GetScreenWidth()/2, GetScreenHeight()/2, 35, RAYWHITE);
			if (GetKeyPressed() == KEY_SPACE) {
				gameStart =1;
			}
			EndDrawing();
		}
		//Start level
		BeginDrawing();
		ClearBackground(bgColor);

		//Update player movement
		if (IsKeyDown(KEY_UP)) {
			updatePlayer(&player, 0);
			//updatePlayer(&comm, 0);
		}
		if (IsKeyDown(KEY_DOWN)) {
			updatePlayer(&player, 1);
			//updatePlayer(&comm, 1);
		} 

		// Update comm movement to track ball
		updateComm(&comm, &ball);
		
		//update ball
		updateBall(&ball, &player, &comm, &score);

		//Draw everything
		drawScore(&score);
		drawPlayer(&player);
		drawPlayer(&comm);
		drawBall(&ball);



		//loop
		EndDrawing();
	}

	return 0;
}
