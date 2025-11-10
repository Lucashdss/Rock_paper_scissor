#include "raylib.h"
#include "animation.hpp"
#include <iostream>

Animation::Animation(){
    RockTexture = LoadTexture("assets/rock.png");
    PaperTexture = LoadTexture("assets/paper.png");
    ScissorsTexture = LoadTexture("assets/scissors.png");
}

Animation::~Animation() {
    UnloadTexture(RockTexture);
    UnloadTexture(PaperTexture);
    UnloadTexture(ScissorsTexture);
}

