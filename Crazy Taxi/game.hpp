#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;
    int day = 0;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    //global reference to png image sheets
    SDL_Texture* assets=NULL;
    SDL_Surface *screen = NULL;

    std::string cur_string = " ";

    int cur_time=0,start_time=time(0);
    

public:
    void blit();
    bool init();
    bool loadMedia();
    void close();
    
    bool rules_called;
    bool maingame_called;
    bool restartgame_called;
    void rules();
    void maingame();

    SDL_Texture* loadTexture( std::string path );
    SDL_Texture* get_gTexture();

    void run();
    void write(std::string s);
};

