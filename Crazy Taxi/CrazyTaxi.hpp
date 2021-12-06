// including all the libraries and classes
#include<SDL.h>
#include "Solar.hpp"
#include "Taxi.hpp"
#include "Traffic.hpp"
#include "Obstacle.hpp"
#include "Tree.hpp"
#include "StreetLight.hpp"
#include "Lives.hpp"
#include "start_game.hpp"
#include "rules.hpp"
#include "rules_button.hpp"
#include "logo.hpp"
#include "back_button.hpp"
#include "restart_button.hpp"
#include "end_game.hpp"
#include<list>
using namespace std;
class CrazyTaxi{
    Start_Game p1;
    rules_button p2;
    logo l1;
    rules r;
    back_button b;
    restart_button b2;
    End_Game e1;
    // list<Taxi*> taxis;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    list<Traffic*> vehicles;
    list<Obstacle*> obstacles;
    list<Tree*> trees;
    list<StreetLight*> lights;
    list<Lives*> lives;
    // intializing the taxi at the bottom center of the screen
    Taxi t1{gRenderer, assets, {465, 500, 75, 90}};
    int time = 30; int lives_2 = 5;


    public:
    int points = 0; 
    bool gameOver = false;
    bool crashed = false;
    Solar s1{gRenderer, assets, {1000, 50, 50, 50}};
    CrazyTaxi(SDL_Renderer *, SDL_Texture *);
    // ~CrazyTaxi();
    void drawStart();
    void drawBack();
    void drawRestart();
    void drawRules();
    void drawInstructions();
    void drawLogo();
    void drawEnd();
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
    // void deleteLight(StreetLight&);
    // void deleteObstacle(Obstacle&);
    // void deleteTraffic(Traffic&);
    // void deleteTree(Tree&);
    bool stats();
    void endGame();
    void livesLeft();
    // string getPoints();
};