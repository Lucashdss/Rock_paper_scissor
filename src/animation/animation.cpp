#include "raylib.h"
#include "animation.hpp"
#include <iostream>
#include <vector>

Animation::Animation(){
    RockTexture = LoadTexture("assets/rock.png");
    PaperTexture = LoadTexture("assets/paper.png");
    ScissorsTexture = LoadTexture("assets/scissors.png");
    fadeIn = true;
}

Animation::~Animation() {
    UnloadTexture(RockTexture);
    UnloadTexture(PaperTexture);
    UnloadTexture(ScissorsTexture);
}

std::vector<Texture2D>Animation::getTextures() const{
    std::vector<Texture2D> textures{RockTexture, PaperTexture, ScissorsTexture};
    return textures;
}

void Animation::DrawRockAnimation() const{
    DrawTexture(RockTexture, 0, 0, WHITE);
}