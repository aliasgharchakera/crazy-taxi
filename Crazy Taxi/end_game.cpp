#include "end_game.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


void End_Game::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

End_Game::End_Game(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {267,619,243,91};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {300, 80, 400, 200};
}