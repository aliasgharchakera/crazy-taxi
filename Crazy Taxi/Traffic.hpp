#include "Unit.hpp"
#pragma once

class Traffic: public Unit{
    SDL_Rect src, mover;
    // to keep track of the current animation
    int n = 0;
    public:
    Traffic(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    SDL_Rect* getMover();
    void draw();
    // declaring a function to add animations when the bullet hits the right edge
    void animation(int);
    bool OutofFrame();
    // SDL_Rect position();
};