#pragma once
#include "raylib.h"
#include <string>
#include <vector>
using namespace std;

class Animation
{
private:
    Texture2D RockTexture;
    Texture2D PaperTexture;
    Texture2D ScissorsTexture;

public:
    Animation();
    ~Animation();
    std::vector<Texture2D> getTextures() const;
};
