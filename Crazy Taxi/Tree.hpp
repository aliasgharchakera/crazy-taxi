#include "Unit.hpp"
#pragma once

class Tree: public Unit{
    SDL_Rect src, mover;
    // to keep track of the current animation
    int n = 0, p = 0;
    public:
    Tree(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);

    void draw();
    // declaring a function to add animations when the bullet hits the right edge
    void animation(int);
    bool OutofFrame();
    // SDL_Rect position();
};