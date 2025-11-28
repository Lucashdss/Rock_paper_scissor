#include "raylib.h"
#include "animationEnemy.hpp"
#include <iostream>
#include <vector>

AnimationEnemy::AnimationEnemy(): Animation(){
    int AnimationFrame = 0;
    RockGifImage = LoadImageAnim("assets/rock.gif", &AnimationFrame);
    PaperGifImage = LoadImageAnim("assets/paper.gif", &AnimationFrame);
    ScissorsGifImage = LoadImageAnim("assets/scissors.gif", &AnimationFrame);
}

AnimationEnemy::~AnimationEnemy() {
    UnloadImage(RockGifImage);
    UnloadImage(PaperGifImage);
    UnloadImage(ScissorsGifImage);
}

Texture2D AnimationEnemy::DrawRockAnimation() const {
    static Texture2D RockTexture = LoadTextureFromImage(RockGifImage);

    const int AnimationFrame = 99;
    static int CurrentFrame = 20;
    const int FrameDelay = 2;
    static int FrameCounter = 0;
    static unsigned int NextFrameDataOffset = 0;
    static bool firstUpdate = true;
    
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

Texture2D AnimationEnemy::DrawPaperAnimation() const {
    static Texture2D PaperTexture = LoadTextureFromImage(PaperGifImage);

    const int AnimationFrame = 99;
    static int CurrentFrame = 20;
    const int FrameDelay = 2;
    static int FrameCounter = 0;
    static unsigned int NextFrameDataOffset = 0;
    static bool firstUpdate = true;
    
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

Texture2D AnimationEnemy::DrawScissorsAnimation() const {
    static Texture2D ScissorsTexture = LoadTextureFromImage(ScissorsGifImage);

    const int AnimationFrame = 78;
    static int CurrentFrame = 0;
    const int FrameDelay = 2;
    static int FrameCounter = 0;
    static unsigned int NextFrameDataOffset = 0;
    static bool firstUpdate = true;
    
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