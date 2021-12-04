#include "logo.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void logo::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
   
}
void logo::animate(){
    //come_back=true;
    //moverRect.x+=10;
}

logo::logo(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {13,39,488,205};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {300, 80, 400, 200};
}