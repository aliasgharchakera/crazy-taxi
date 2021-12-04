#include<SDL.h>
#include <string>
#include <vector>
#include <fstream>
#pragma once

class rules{
SDL_Rect srcRect, moverRect;
bool come_back=false;
public:
    
    void draw(SDL_Renderer*, SDL_Texture* assets);
    
    rules(); 
};