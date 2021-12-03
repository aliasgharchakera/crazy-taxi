#include "Lives.hpp"    

    Lives::Lives(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        src = {1, 509, 100, 101};
    }
// drawing animations when the bullet hits the right edge
    void Lives::draw(){
        Unit::draw(src, mover);
    }
