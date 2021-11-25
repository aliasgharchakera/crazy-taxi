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
    Solar s1{gRenderer, assets, {1000, 50, 50, 50}};
    Taxi t1{gRenderer, assets, {500, 500, 50, 75}};
    int time; int points;

    public:
    CrazyTaxi(SDL_Renderer *, SDL_Texture *);
    void drawObjects();
    void createObject(int x, int y);
    void createTraffic();
    void createLights();
    void createObstacles();
    void createTrees();
    void probObjects();
    void rightArrow();
    void leftArrow();
    void deleteObj();
};