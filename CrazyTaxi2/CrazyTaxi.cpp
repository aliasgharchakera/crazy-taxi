#include "CrazyTaxi.hpp"
#include<iostream>

void CrazyTaxi::drawObjects(){
    s1.draw();
    t1.draw();
    for (auto& v: vehicles){
        v->draw();
        if (v.)
        }
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
    int x = rand () % 3 + 1;
    SDL_Rect mov;
    if (x == 3)
        mov = {200, 300, 30, 30};
    else if (x == 2)
        mov = {200, 300, 30, 30};
    else 
        mov = {200, 300, 30, 30};
    Traffic* v1 = new Traffic(gRenderer, assets, mov);
    vehicles.push_back(v1);
}

void CrazyTaxi::createLights(){
    int x = rand () % 2 + 1;
    SDL_Rect mov;
    if (x == 2)
        mov = {200, 300, 30, 30};
    else
        mov = {200, 300, 30, 30};
    StreetLight* l1 = new StreetLight(gRenderer, assets, mov);
    lights.push_back(l1);
}

void CrazyTaxi::createObstacles(){
    int x = rand () % 3 + 1;
    SDL_Rect mov;
    if (x == 3)
        mov = {200, 300, 30, 30};
    else if (x == 2)
        mov = {200, 300, 30, 30};
    else 
        mov = {200, 300, 30, 30};
    Obstacle* o1 = new Obstacle(gRenderer, assets, mov);
    obstacles.push_back(o1);
}

void CrazyTaxi::createTrees(){
    int x = rand () % 2 + 1;
    SDL_Rect mov;
    if (x == 2)
        mov = {200, 300, 30, 30};
    else
        mov = {200, 300, 30, 30};
    Tree* t1 = new Tree(gRenderer, assets, mov);
    trees.push_back(t1);
}

void CrazyTaxi::probObjects(){
    int x = rand () % 2 + 1;
    if (x == 2)
        createTraffic();
    else
        createObstacles();
}

bool CrazyTaxi::stats(){
    points++; time--;
    cout << "time left: " << time << endl;
    if (time == 0){
        gameOver = true;
    }
    return gameOver;
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