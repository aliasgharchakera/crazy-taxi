#include<SDL.h>
#include <string>
#include <vector>
#include <fstream>
#pragma once

class back_button{
SDL_Rect srcRect, moverRect;
bool come_back=false;
public:
    void draw(SDL_Renderer*, SDL_Texture* assets);
    void animate();
    back_button(); 
};