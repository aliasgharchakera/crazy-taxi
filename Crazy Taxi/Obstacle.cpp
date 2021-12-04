#include "Obstacle.hpp"    

    Obstacle::Obstacle(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), mover(mov){
        int p = rand () % 2 + 1;
        switch(p){
            case 1: src = {28, 1339, 151, 177};
            break;
            case 2: src = {1017, 110, 200, 200};
            break;
        }
    }
// drawing animations when the bullet hits the right edge
    void Obstacle::draw(){
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
                mover.x += 8;
        }
        else{
            int x = rand () % 4 + 1;
            if (x == 1)
                mover.x -= 2;
            else if (x == 2)
                mover.x -= 4;
            else if (x == 3)
                mover.x -= 8;
        }
        mover.y += 1;
        Unit::draw(src, mover);
    }

    SDL_Rect* Obstacle::getMover(){
        return &mover;
    }

    bool Obstacle::OutofFrame(){
        if (mover.y > 600)
            return true;
        return false;
    }
// defining the animation function
    void Obstacle::animation(int n){
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