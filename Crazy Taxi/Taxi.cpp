#include "Taxi.hpp"    

    Taxi::Taxi(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        src = {531, 1, 102, 85};
    }
// drawing animations when the bullet hits the right edge
    void Taxi::draw(){
        // if (mover.x == 0 + mover.w){
        //         // animation(n);
        //         n++;
        // }
        // else{
        //     // mover.x-=10;
        //     if (mover.x < 500)
        //         // mover.y -= 5;
        //     else
        //         // mover.y += 5;
        // }
        Unit::draw(src, mover);
    }

    SDL_Rect* Taxi::getMover(){
        return &mover;
    }

    void Taxi::rightArrow(){
        if (mover.x < 725)
            mover.x += 20;
    }

    void Taxi::leftArrow(){
        if (mover.x > 200)
            mover.x -= 20;
    }
// defining the animation function
    void Taxi::animation(int n){
        switch (n){
        case 0: src = {39, 394, 92, 95};
        mover.w = 30; mover.h = 32; mover.y -= 25;
        break;
        case 1: src = {189, 373, 133, 141};
        mover.w = 44; mover.h = 47;
        break;
        case 2: src = {339, 362, 162, 165};
        mover.w = 54; mover.h = 55;
        break;
        case 3: src = {506, 362, 162, 165};
        mover.w = 54; mover.h = 55;
        break;
        case 4: src = {681, 362, 154, 165};
        mover.w = 51; mover.h = 55;
        break;
        case 5: src = {847, 362, 154, 165};
        mover.w = 51; mover.h = 55;
        break;
        case 6: src = {1010, 362, 158, 165};
        mover.w = 53; mover.h = 55;
        break;
        case 8: src = {0, 0, 0, 0};
        mover.w = 0; mover.h = 0;
        break;
        }
    }