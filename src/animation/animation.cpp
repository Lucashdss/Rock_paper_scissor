#include "raylib.h"
#include "animation.hpp"
#include <iostream>
#include <vector>

Animation::Animation(){
    int AnimationFrame = 0;
    RockGifImage = LoadImageAnim("assets/rock.gif", &AnimationFrame);
    PaperGifImage = LoadImageAnim("assets/paper.gif", &AnimationFrame);
    ScissorsGifImage = LoadImageAnim("assets/scissors.gif", &AnimationFrame);
    sourceRec = { 0.0f, 0.0f, (float)RockGifImage.width*(-1), (float)RockGifImage.height};
    destRec = { 0.0f, 100.0f, (float)RockGifImage.width, (float)RockGifImage.height};
}

Animation::~Animation() {
    UnloadImage(RockGifImage);
    UnloadImage(PaperGifImage);
    UnloadImage(ScissorsGifImage);
}

std::vector<Image>Animation::getTextures() const{
    std::vector<Image> textures{
        RockGifImage,
        PaperGifImage,
        ScissorsGifImage
    };
    return textures;
}

Texture2D Animation::DrawRockAnimation() const {
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
            CurrentFrame = 20;
        }

        NextFrameDataOffset = RockGifImage.width * RockGifImage.height * 4 * CurrentFrame;

        UpdateTexture(RockTexture, ((unsigned char*)RockGifImage.data) + NextFrameDataOffset);

        FrameCounter = 0;
    }

    return RockTexture;
}

Texture2D Animation::DrawPaperAnimation() const {
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
            CurrentFrame = 20;
        }

        NextFrameDataOffset = PaperGifImage.width * PaperGifImage.height * 4 * CurrentFrame;

        UpdateTexture(PaperTexture, ((unsigned char*)PaperGifImage.data) + NextFrameDataOffset);

        FrameCounter = 0;
    }

    return PaperTexture;
}

Texture2D Animation::DrawScissorsAnimation() const {
    static Texture2D ScissorsTexture = LoadTextureFromImage(ScissorsGifImage);

    const int AnimationFrame = 99;
    static int CurrentFrame = 20;
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
            CurrentFrame = 20;
        }

        NextFrameDataOffset = ScissorsGifImage.width * ScissorsGifImage.height * 4 * CurrentFrame;

        UpdateTexture(ScissorsTexture, ((unsigned char*)ScissorsGifImage.data) + NextFrameDataOffset);

        FrameCounter = 0;
    }

    return ScissorsTexture;
}