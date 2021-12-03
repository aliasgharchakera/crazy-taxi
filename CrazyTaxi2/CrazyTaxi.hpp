#include<SDL.h>
#include "Solar.hpp"
#include "Taxi.hpp"
#include "Traffic.hpp"
#include "Obstacle.hpp"
#include "Tree.hpp"
#include "StreetLight.hpp"
#include<list>
using namespace std;
class CrazyTaxi{
    // list<Taxi*> taxis;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    list<Traffic*> vehicles;
    list<Obstacle*> obstacles;
    list<Tree*> trees;
    list<StreetLight*> lights;
    Taxi t1{gRenderer, assets, {500, 500, 50, 75}};
    int time = 30; int points = 0;
    bool gameOver = false; bool day = false;

    public:
    Solar s1{gRenderer, assets, {1000, 50, 50, 50}};
    CrazyTaxi(SDL_Renderer *, SDL_Texture *);
    // ~CrazyTaxi();
    void drawObjects();
    void createObject(int x, int y);
    void createObstacles();
    void createTraffic();
    void createLights();
    void createTrees();
    void probObjects();
    void rightArrow();
    void leftArrow();
    void deleteObj();
    bool stats();
    void endGame();
};