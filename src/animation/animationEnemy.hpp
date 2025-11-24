#pragma once
#include "raylib.h"
#include <string>
#include <vector>
#include "animation.hpp"
using namespace std;

class AnimationEnemy : public Animation
{
private:
    int AnimationFrame;
    Image RockGifImage;
    Image PaperGifImage;
    Image ScissorsGifImage;
public:
    AnimationEnemy();
    virtual ~AnimationEnemy();
    virtual Texture2D DrawRockAnimation() const override;
    virtual Texture2D DrawPaperAnimation() const override;
    virtual Texture2D DrawScissorsAnimation() const override;  
};
