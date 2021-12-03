#include "Unit.hpp"
#pragma once

class Obstacle: public Unit{
    SDL_Rect src, mover;
    // to keep track of the current animation
    int n = 0, p = 0;
    public:
    Obstacle(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    SDL_Rect* getMover();
    void draw();
    // declaring a function to add animations when the bullet hits the right edge
    void animation(int);
    // SDL_Rect position();
};