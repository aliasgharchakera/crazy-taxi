#include "CrazyTaxi.hpp"
#include<iostream>

void CrazyTaxi::drawObjects(){
    s1.draw();
    t1.draw();
    for (auto& v: vehicles)
        v->draw();
    for (auto& l: lights)
        l->draw();
    for (auto& t: trees)
        t->draw();
    for (auto& o: obstacles)
        o->draw();
}


CrazyTaxi::CrazyTaxi(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){
    SDL_Rect mov = {500, 500, 40, 60};
    // Taxi* t1 = new Taxi(gRenderer, assets, mov);
    // taxis.push_back(t1);
}

void CrazyTaxi::rightArrow(){
    t1.rightArrow();
}

void CrazyTaxi::leftArrow(){
    t1.leftArrow();
}

void CrazyTaxi::createObject(int x, int y){
    // let's make a rectangel on x, y of the size 30, 10
    // SDL_Rect mov = {x, y, 90, 30};
    // Solar* s1 = new Solar(gRenderer, assets, mov);
    // Taxi* t1 = new Taxi(gRenderer, assets, mov);
    // solars.push_back(s1);
    // taxis.push_back(t1);
    //delete t1;
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
}

void CrazyTaxi::createTraffic(){
    int x, y;
    x = rand () % 5; y = rand () % 5;
    SDL_Rect mov = {200, 300, 30, 30};
    Traffic* v1 = new Traffic(gRenderer, assets, mov);
    vehicles.push_back(v1);
}

void CrazyTaxi::createLights(){
    int x, y;
    x = rand () % 5; y = rand () % 5;
    SDL_Rect mov = {200, 300, 30, 30};
    StreetLight* l1 = new StreetLight(gRenderer, assets, mov);
    lights.push_back(l1);
}

void CrazyTaxi::createObstacles(){
    int x, y;
    x = rand () % 5; y = rand () % 5;
    SDL_Rect mov = {200, 300, 30, 30};
    Obstacle* o1 = new Obstacle(gRenderer, assets, mov);
    obstacles.push_back(o1);
}

void CrazyTaxi::createTrees(){
    int x, y;
    x = rand () % 5; y = rand () % 5;
    SDL_Rect mov = {200, 300, 30, 30};
    Tree* t1 = new Tree(gRenderer, assets, mov);
    trees.push_back(t1);
}

void CrazyTaxi::probObjects(){
    int x; x = rand () % 5;
    if (x%2 == 0)
        createTraffic();
    else
        createObstacles();
}

void CrazyTaxi::deleteObj(){
    for (auto& v: vehicles)
        delete v;
    vehicles.clear();
    for (auto& l: lights)
        delete l;
    lights.clear();
    for (auto& t: trees)
        delete t;
    trees.clear();
    for (auto& o: obstacles)
        delete o;
    obstacles.clear();
    cout << "delete called" << endl;
}