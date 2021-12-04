#include "restart_button.hpp"


void restart_button::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    
    if (come_back){
        moverRect.x-=10;
        come_back=false; 
    
    }
    
}

void restart_button::animate(){
    come_back=true;
    moverRect.x+=10;
}

restart_button::restart_button(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {243,802,300,93};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {660, 375, 270, 95};
}