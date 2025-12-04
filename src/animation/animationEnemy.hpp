#pragma once
#include "raylib.h"
#include <string>
#include <vector>
#include "animation.hpp"
using namespace std;

class AnimationEnemy : public Animation
{
public:
    AnimationEnemy();
    virtual ~AnimationEnemy();
    virtual Texture2D DrawRockAnimation(bool reset=false) const override;
    virtual Texture2D DrawPaperAnimation(bool reset=false) const override;
    virtual Texture2D DrawScissorsAnimation(bool reset=false) const override;
    virtual void ResetAnimationFrames(int &EnemyMove) const override;  
};
