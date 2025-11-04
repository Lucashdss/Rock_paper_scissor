#pragma once
#include "raylib.h"
#include <string>

class Animation {
private:
    Texture2D texture;

public:
    Animation(const std::string& imagePath);
    ~Animation();
    Texture2D getTexture() const { return texture; }
    
};
