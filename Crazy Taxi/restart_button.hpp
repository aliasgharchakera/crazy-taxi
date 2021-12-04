#include<SDL.h>

class restart_button{
SDL_Rect srcRect, moverRect;
bool come_back = false;

public:
    
    void draw(SDL_Renderer*, SDL_Texture* assets);
    void animate();
    restart_button(); 
};