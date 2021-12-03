#include "Unit.hpp"
#pragma once

class Taxi: public Unit{
    SDL_Rect src, mover;
    // to keep track of the current animation
    int n = 0;
    public:
    Taxi(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);
    void draw();
    SDL_Rect* getMover();
    // declaring a function to add animations when the bullet hits the right edge
    void animation(int);
    void rightArrow();
    void leftArrow();
    // SDL_Rect position();
};