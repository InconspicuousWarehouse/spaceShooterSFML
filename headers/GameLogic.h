#ifndef SPACE_SHOOTERV3_GAMELOGIC_H
#define SPACE_SHOOTERV3_GAMELOGIC_H
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Asteroid.h"
#include "View.h"

class GameLogic
{
private:
    int counter;
public:
    GameLogic();
    ~GameLogic();
    View* view;
    GameLogic(View* viewPtr) : view(viewPtr) {}
    void checkCollisions();
};
#endif //SPACE_SHOOTERV3_GAMELOGIC_H
