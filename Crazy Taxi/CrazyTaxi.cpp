#include "CrazyTaxi.hpp"
#include<iostream>

// drawing all the objects in the game
void CrazyTaxi::drawObjects(){
    s1.draw();
    t1.draw();
    for (auto& v: vehicles){
        // checking if the particular instance has went out of frame so we can delete it
        if (v->OutofFrame()){
            // delete v;
            // points += 5;
        }
        else{
            v->draw();
            // checking if it crashed with the taxi
            if (SDL_HasIntersection((v->getMover()), (t1.getMover()))){
                // cout << "crashed" << endl;
                lives_2--;
                lives.pop_back();
                crashed = true;
                // clearing the screen if lives are left
                if (lives_2 > 0){
                    deleteObj();
                    t1 = {gRenderer, assets, {500, 500, 70, 95}};
                }
                // game over if no lives left
                else
                    gameOver = true;
            }
        }
    }
    // drawing the streetlights
    for (auto& l: lights){
        if (l->OutofFrame())
            delete l;
        else
            l->draw();
    }
    // drawing the trees
    for (auto& t: trees){
        if (t->OutofFrame())
            delete t;
        else
            t->draw();
    }
    // drawing the lives
    for (auto& l: lives){
        l->draw();
    }
    // drawing the obstacles
    for (auto& o: obstacles){
        // checking if the particular instance has went out of frame so we can delete it
        if (o->OutofFrame()){
            // delete o;
            // points += 5;
        }
        else{
            o->draw();
            // checking if the obstacle collided with the taxi
            if (SDL_HasIntersection((o->getMover()), (t1.getMover()))){
                // cout << "crashed" << endl;
                lives_2--;
                lives.pop_back();
                crashed = true;
                // clearing the screen if lives are left
                if (lives_2 > 0){
                    deleteObj();
                    t1 = {gRenderer, assets, {500, 500, 70, 95}};
                }
                // game over no lives are left
                else
                    gameOver = true;
            }
        }
    }
}

CrazyTaxi::CrazyTaxi(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){
    SDL_Rect mov = {5, 100, 30, 30};
    // initializing the game with 5 lives
    for (int i = 0; i < 5; i++){
        mov.x += 32;
        Lives* l1 = new Lives(gRenderer, assets, mov);
        lives.push_back(l1);
    }
    // Taxi* t1 = new Taxi(gRenderer, assets, mov);
    // taxis.push_back(t1);
}
// drawing the back button
void CrazyTaxi::drawBack(){
    b.draw(gRenderer, assets);
}
// drawing the exit button
void CrazyTaxi::drawRestart(){
    b2.draw(gRenderer, assets);
}
// drawing the instructions panel
void CrazyTaxi::drawInstructions(){
    r.draw(gRenderer, assets);
}
// drawing the start game button
void CrazyTaxi::drawStart(){
    p1.draw(gRenderer, assets);
}
// drawing the game over text
void CrazyTaxi::drawEnd(){
    e1.draw(gRenderer, assets);
}
// drawing the rules button
void CrazyTaxi::drawRules(){
    p2.draw(gRenderer, assets);
}
// drawing the crazytaxi logo
void CrazyTaxi::drawLogo(){
    l1.draw(gRenderer, assets);
}
// right arrow key is called
void CrazyTaxi::rightArrow(){
    t1.rightArrow();
}
// left arrow key is called
void CrazyTaxi::leftArrow(){
    t1.leftArrow();
}

void CrazyTaxi::createObject(int x, int y){
    // std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
}
// creating traffic objects at random positions
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
// creating the street lights
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
// creating the obstacles at random positions
void CrazyTaxi::createObstacles(){
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
    Obstacle* o1 = new Obstacle(gRenderer, assets, mov);
    obstacles.push_back(o1);
}
// creating the trees
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
// a probability to decide whether a vehicle or an obstacle will be created
void CrazyTaxi::probObjects(){
    int y = rand () % 50 + 1;
    if (y%15 == 0){
        points += 5;
        int x = rand () % 3 + 1;
        if (x == 2)
            createObstacles();
        else
            createTraffic();
    }
}

// string CrazyTaxi::getPoints(){
//     return to_string(points);
// }

// bool CrazyTaxi::stats(){
//     // points++; //time--;
//     // cout << "time left: " << time << endl;
//     if (time == 0){
//         gameOver = true;
//     }
//     if (lives_2 < 0)
//         gameOver = true;
//     return gameOver;
// }
// a delete function to delete all the dynamically created objects from the memory
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
    // cout << "delete called" << endl;
}