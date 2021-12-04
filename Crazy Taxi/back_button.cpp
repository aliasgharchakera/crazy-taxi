#include "back_button.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
// pigeon implementation will go here.

void back_button::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    if (come_back){
        moverRect.x-=10;
        come_back=false; 
    }
}
void back_button::animate(){
    come_back=true;
    moverRect.x+=10;
}

back_button::back_button(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {1017,1,150,107};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {50, 100, 150, 100};
}