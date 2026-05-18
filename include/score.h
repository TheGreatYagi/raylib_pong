#ifndef SCORE_H
#define SCORE_H
#pragma once

#include "raylib.h"

extern const Color scoreColor;

typedef struct Score {
    int player;
    int comm;
} Score;


void drawScore(Score* score);
void updateScore(Score* score, bool player);


 

#endif