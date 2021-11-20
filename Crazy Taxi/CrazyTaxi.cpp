#include "CrazyTaxi.hpp"
#include<iostream>

void CrazyTaxi::drawObjects(){
    s1.draw();
    t1.draw();
    for (auto& v: vehicles)
        v->draw();
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

void CrazyTaxi::deleteObj(){
    for (auto& v: vehicles)
        delete v;
    vehicles.clear();
    cout << "delete called" << endl;
}