#include "score.h"
#include "raylib.h"

const Color scoreColor = {199, 163, 105, 255}; //grey orange

//0,0 is top left

void drawScore(Score* score) {
    DrawText(TextFormat("%d",score->player),80,20,40,scoreColor);
    DrawText(TextFormat("%d",score->comm),1180,20,40,scoreColor);
}

void updateScore(Score* score, bool player) {
    if(player) {
        score->player += 1;
    } else {
        score->comm +=1;
    }
}