#pragma once
#include "raylib.h"
#include <string>
#include <vector>
using namespace std;

class Animation
{
private:
    int AnimationFrame;
    Image RockGifImage;
    Image PaperGifImage;
    Image ScissorsGifImage;
public:
    Rectangle sourceRec;
    Rectangle destRec;

    Animation();
    virtual ~Animation();
    std::vector<Image>getTextures() const;
    virtual Texture2D DrawRockAnimation() const;
    virtual Texture2D DrawPaperAnimation() const;
    virtual Texture2D DrawScissorsAnimation() const;
    void DrawWinner(int winner) const;
    void DrawTrophy() const;

};
