#include "Tree.hpp"    

    Tree::Tree(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        src = {1559, 2, 632, 640};
    }
// drawing animations when the bullet hits the right edge
    void Tree::draw(){
        if (p%10 == 0){
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
    void Tree::animation(int n){
        switch (n){
        case 0: src = {1559, 1, 632, 640};
        mover.w = 50; mover.h = 50;
        mover.x = 1000;
        mover.y = 50;
        break;
        case 1: src = {475, 2, 1081, 1170};
        mover.w = 45; mover.h = 45;
        mover.x = 1000;
        mover.y = 50;
        cout << "moon time" << endl;
        break;
        }
    }