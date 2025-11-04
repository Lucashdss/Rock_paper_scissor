#include "raylib.h"
#include "animation.hpp"
#include <iostream>

Animation::Animation(const std::string& imagePath) {
try
{
    Image image = LoadImage(imagePath.c_str());
    if (image.data == nullptr) {
        throw std::runtime_error("Failed to load image: " + imagePath);
    }
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
}

Animation::~Animation() {
    UnloadTexture(texture);
}

