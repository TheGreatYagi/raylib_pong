#include "comm.h"

/*
    This file handles CPU logic. Changes here affect game difficulty.
*/

void updateComm(Player* comm, Ball* ball) {
    // Update comm movement to track ball
    // y: 1 is down, 0 is up
    // printf("comm y is: %d, ball.pos_y is: %d, ball.vel_y is: %d\n", comm.y, ball.pos_y, ball.vel_y);
    if (ball->vel_y == 0) {
    	if (ball->pos_y <= comm->y + 104/2) {
    		//printf("moving comm up\n");
    		updatePlayer(comm, 0);
    	}
    }
    if (ball->vel_y == 1) {
    	if (ball->pos_y > comm->y + 104/2) {
    		//printf("moving comm down\n");
    		updatePlayer(comm, 1);
    	}
    }

}