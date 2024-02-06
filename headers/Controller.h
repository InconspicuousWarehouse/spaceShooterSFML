#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "View.h"
#include "Ship.h"
#include "GameLogic.h"

class Controller
{
private:
    View* view;
    Ship* ship;
    float dirX;
    float dirY;

public:
    Controller();
    ~Controller();
    void run();
    void pollEvents();
    void update();
    void render();
    void setShip(Ship* shipPtr);
};

#endif // CONTROLLER_H

