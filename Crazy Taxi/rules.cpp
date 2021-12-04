#include "rules.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void rules::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

rules::rules(){
    srcRect = {303,1065,564,463};
    moverRect = {290, 80, 400, 400};
}