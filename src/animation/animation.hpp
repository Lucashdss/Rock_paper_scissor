#pragma once
#include "raylib.h"
#include <string>
#include <vector>
using namespace std;

class Animation
{
protected:
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
    virtual Texture2D DrawRockAnimation(bool reset=false) const;
    virtual Texture2D DrawPaperAnimation(bool reset=false) const;
    virtual Texture2D DrawScissorsAnimation(bool reset=false) const;
    void DrawWinner(int winner) const;
    void DrawTrophy() const;
    virtual void ResetAnimationFrames(int &PlayerMove) const;

};
