#include "Solar.hpp"    

    Solar::Solar(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        src = {1219, 613, 100, 101};
    }
// drawing animations when the bullet hits the right edge
    void Solar::draw(){
        if (p%5 == 0){
            if (mover.x == 0){
                    if (n == 1)
                        n = 0;
                    else
                        n++;
                    animation(n);
            }
            else{
                mover.x-=10;
                if (mover.x < 500)
                    mover.y += 1;
                else
                    mover.y -= 1;
            }
        }
        p++;
        Unit::draw(src, mover);
    }
// defining the animation function
    void Solar::animation(int n){
        switch (n){
        case 0: src = {1219, 613, 100, 101};
        mover.w = 50; mover.h = 50;
        mover.x = 1000;
        mover.y = 50;
        break;
        case 1: src = {1321, 613, 100, 101};
        mover.w = 45; mover.h = 45;
        mover.x = 1000;
        mover.y = 50;
        cout << "moon time" << endl;
        break;
        }
    }