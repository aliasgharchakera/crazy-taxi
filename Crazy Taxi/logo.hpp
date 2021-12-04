#include<SDL.h>
#include <string>
#include <vector>
#include <fstream>
#pragma once

class logo{
SDL_Rect srcRect, moverRect;
bool come_back=false;
public:
    void draw(SDL_Renderer*, SDL_Texture* assets);
    void animate();
    logo(); 
};