#include "Traffic.hpp"

    Traffic::Traffic(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        int p = rand () % 9 + 1;
        switch(p){
            case 1: src = {281, 660, 80, 45}; //green car
            break;
            case 2: src = {363, 660, 80, 45}; //pruple car
            break;
            case 3: src = {383, 707, 80, 45}; //yellow car
            break;
            case 4: src = {1391, 613, 80, 45}; //blue car
            break;
            case 5: src = {1391, 660, 80, 45}; //red car
            break;
            case 6: src = {243, 312, 240, 194}; //lime car
            break;
            case 7: src = {1, 312, 240, 194}; //blue car
            break;
            case 8: src = {281, 524, 200, 116}; //pink car
            break;
            case 9: src = {1017, 312, 240, 194}; //red car2
            break;
        } 
    }

    SDL_Rect* Traffic::getMover(){
        return &mover;
    }
// drawing animations when the bullet hits the right edge
    void Traffic::draw(){
        if (n == 10)
            n = 0;
        else{
            mover.w += 1; mover.h += 1;
            n++;
        }

        if (mover.y > 320)
            if (mover.y > 350)
                mover.y += 2;
            mover.y += 2;
        if (mover.x > 500){
            int x = rand () % 4 + 1;
            if (x == 1)
                mover.x += 2;
            else if (x == 2)
                mover.x += 4;
            else if (x == 3)
                mover.x -= 4;
        }
        else{
            int x = rand () % 4 + 1;
            if (x == 1)
                mover.x -= 2;
            else if (x == 2)
                mover.x -= 4;
            else if (x == 3)
                mover.x += 4;
        }
        mover.y += 1;
        Unit::draw(src, mover);
    }

    bool Traffic::OutofFrame(){
        if (mover.y > 600)
            return true;
        return false;
    }
// defining the animation function
    // void Traffic::animation(int n){
    //     switch (n){
    //     case 0: src = {1559, 1, 632, 640};
    //     mover.w = 50; mover.h = 50;
    //     mover.x = 1000;
    //     mover.y = 50;
    //     break;
    //     case 1: mover.w += 2; mover.h += 2;
    //     break;
    //     }
    // }