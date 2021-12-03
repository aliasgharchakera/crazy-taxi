#include "CrazyTaxi.hpp"
#include<iostream>

void CrazyTaxi::drawObjects(){
    s1.draw();
    t1.draw();
    for (auto& v: vehicles){
        v->draw();
        if (SDL_HasIntersection((v->getMover()), (t1.getMover()))){
            cout << "crashed" << endl;
            lives_2--;
            lives.pop_back();
            crashed = true;
            if (lives_2 > 0){
                deleteObj();
                t1 = {gRenderer, assets, {500, 500, 70, 95}}; 
                crashed = false;
            }
        }
    }
    for (auto& l: lights)
        l->draw();
    for (auto& t: trees)
        t->draw();
    for (auto& l: lives)
        l->draw();
    for (auto& o: obstacles){
        o->draw();
        if (SDL_HasIntersection((o->getMover()), (t1.getMover()))){
            // cout << "crashed" << endl;
            lives_2--;
            crashed = true;
            if (lives_2 > 0){
                deleteObj();
                t1 = {gRenderer, assets, {500, 500, 70, 95}}; 
                crashed = false;
            }
        }
    }
}

CrazyTaxi::CrazyTaxi(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){
    SDL_Rect mov = {5, 50, 30, 30};
    for (int i = 0; i < 5; i++){
        mov.x += 32;
        Lives* l1 = new Lives(gRenderer, assets, mov);
        lives.push_back(l1);
    }
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
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
}

void CrazyTaxi::createTraffic(){
    int x = rand () % 3 + 1;
    SDL_Rect mov;
    if (x == 4)
        mov = {600, 300, 10, 12};
    else if (x == 3)
        mov = {521, 273, 10, 12};
    else if (x == 2)
        mov = {487, 273, 10, 12};
    else 
        mov = {400, 300, 10, 12};
    Traffic* v1 = new Traffic(gRenderer, assets, mov);
    vehicles.push_back(v1);
}

void CrazyTaxi::createLights(){
    int x = rand () % 2 + 1;
    SDL_Rect mov;
    if (x == 2)
        mov = {100, 300, 60, 85};
    else
        mov = {500, 300, 60, 85};
    StreetLight* l1 = new StreetLight(gRenderer, assets, mov);
    lights.push_back(l1);
}

void CrazyTaxi::createObstacles(){
    int x = rand () % 3 + 1;
    SDL_Rect mov;
    if (x == 3)
        mov = {480, 273, 60, 85};
    else if (x == 2)
        mov = {521, 273, 60, 85};
    else 
        mov = {400, 300, 60, 85};
    Obstacle* o1 = new Obstacle(gRenderer, assets, mov);
    obstacles.push_back(o1);
}

void CrazyTaxi::createTrees(){
    int x = rand () % 2 + 1;
    SDL_Rect mov;
    if (x == 2)
        mov = {100, 300, 60, 85};
    else
        mov = {500, 300, 60, 85};
    Tree* t1 = new Tree(gRenderer, assets, mov);
    trees.push_back(t1);
}

void CrazyTaxi::probObjects(){
    int y = rand () % 50 + 1;
    if (y%10 == 0){
        int x = rand () % 2 + 1;
        if (x == 2)
            createTraffic();
        else
            createObstacles();
    }
}

bool CrazyTaxi::stats(){
    points++; //time--;
    // cout << "time left: " << time << endl;
    if (time == 0){
        gameOver = true;
    }
    if (lives_2 < 0)
        gameOver = true;
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