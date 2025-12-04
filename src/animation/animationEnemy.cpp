#include "raylib.h"
#include "animationEnemy.hpp"
#include <iostream>
#include <vector>

AnimationEnemy::AnimationEnemy(): Animation(){
}

AnimationEnemy::~AnimationEnemy() {
}

Texture2D AnimationEnemy::DrawRockAnimation(bool reset) const {
    static Texture2D RockTexture = LoadTextureFromImage(RockGifImage);

    const int AnimationFrame = 99;
    static int CurrentFrame = 20;
    const int FrameDelay = 2;
    static int FrameCounter = 0;
    static unsigned int NextFrameDataOffset = 0;
    static bool firstUpdate = true;

    if (reset){
    CurrentFrame = 20;
    FrameCounter = 0;
    NextFrameDataOffset = 0;
    firstUpdate = true;
    }
    
    if (firstUpdate) {
        unsigned int offset = RockGifImage.width * RockGifImage.height * 4 * CurrentFrame;
        UpdateTexture(RockTexture, ((unsigned char*)RockGifImage.data) + offset);
        firstUpdate = false;
    }

    FrameCounter++;

    if (FrameCounter >= FrameDelay) {
        CurrentFrame++;

        if (CurrentFrame >= AnimationFrame) {
            CurrentFrame = AnimationFrame;
        }
        else{
        NextFrameDataOffset = RockGifImage.width * RockGifImage.height * 4 * CurrentFrame;
        UpdateTexture(RockTexture, ((unsigned char*)RockGifImage.data) + NextFrameDataOffset);
        }

        FrameCounter = 0;
    }

    return RockTexture;
}

Texture2D AnimationEnemy::DrawPaperAnimation(bool reset) const {
    static Texture2D PaperTexture = LoadTextureFromImage(PaperGifImage);

    const int AnimationFrame = 99;
    static int CurrentFrame = 20;
    const int FrameDelay = 2;
    static int FrameCounter = 0;
    static unsigned int NextFrameDataOffset = 0;
    static bool firstUpdate = true;

    if (reset){
    CurrentFrame = 20;
    FrameCounter = 0;
    NextFrameDataOffset = 0;
    firstUpdate = true;
    }
    
    if (firstUpdate) {
        unsigned int offset = PaperGifImage.width * PaperGifImage.height * 4 * CurrentFrame;
        UpdateTexture(PaperTexture, ((unsigned char*)PaperGifImage.data) + offset);
        firstUpdate = false;
    }

    FrameCounter++;

    if (FrameCounter >= FrameDelay) {
        CurrentFrame++;

        if (CurrentFrame >= AnimationFrame) {
            CurrentFrame = AnimationFrame;
        }
        else{
        NextFrameDataOffset = PaperGifImage.width * PaperGifImage.height * 4 * CurrentFrame;
        UpdateTexture(PaperTexture, ((unsigned char*)PaperGifImage.data) + NextFrameDataOffset);
        }

        FrameCounter = 0;
    }

    return PaperTexture;
}

Texture2D AnimationEnemy::DrawScissorsAnimation(bool reset) const {
    static Texture2D ScissorsTexture = LoadTextureFromImage(ScissorsGifImage);

    const int AnimationFrame = 78;
    static int CurrentFrame = 0;
    const int FrameDelay = 2;
    static int FrameCounter = 0;
    static unsigned int NextFrameDataOffset = 0;
    static bool firstUpdate = true;

    if (reset){
    CurrentFrame = 20;
    FrameCounter = 0;
    NextFrameDataOffset = 0;
    firstUpdate = true;
    }
    
    if (firstUpdate) {
        unsigned int offset = ScissorsGifImage.width * ScissorsGifImage.height * 4 * CurrentFrame;
        UpdateTexture(ScissorsTexture, ((unsigned char*)ScissorsGifImage.data) + offset);
        firstUpdate = false;
    }

    FrameCounter++;

    if (FrameCounter >= FrameDelay) {
        CurrentFrame++;

        if (CurrentFrame >= AnimationFrame) {
            CurrentFrame = AnimationFrame;
        }
        else{
        NextFrameDataOffset = ScissorsGifImage.width * ScissorsGifImage.height * 4 * CurrentFrame;
        UpdateTexture(ScissorsTexture, ((unsigned char*)ScissorsGifImage.data) + NextFrameDataOffset);
        }

        FrameCounter = 0;
    }

    return ScissorsTexture;
}

void AnimationEnemy::ResetAnimationFrames(int &EnemyMove) const {
    if (EnemyMove == 1){
        DrawRockAnimation(true);
    }
    else if (EnemyMove == 2){
        DrawPaperAnimation(true);
    }
    else if (EnemyMove == 3){
        DrawScissorsAnimation(true);
    }
}