#include "Unit.hpp"
#pragma once

class Solar: public Unit{
    SDL_Rect src, mover;
    // to keep track of the current animation
    int p = 0;
    public:
    int n = 0;
    Solar(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);

    void draw();
    // declaring a function to add animations when the bullet hits the right edge
    void animation(int);
    // SDL_Rect position();
};