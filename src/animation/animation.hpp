#pragma once
#include "raylib.h"
#include <string>

class Animation {
private:
    Texture2D RockTexture;
    Texture2D PaperTexture;
    Texture2D ScissorsTexture;

public:
    Animation();
    ~Animation();
    Texture2D getTexture() const { return RockTexture, PaperTexture, ScissorsTexture; }
    
};
