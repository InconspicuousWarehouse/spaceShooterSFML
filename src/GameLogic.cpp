#include "../headers/GameLogic.h"

GameLogic::GameLogic() : view(nullptr), counter(0) {}
GameLogic::~GameLogic() {}

void GameLogic::checkCollisions()
{
    std::vector<int> asteroidsToRemove;
    std::vector<int> bulletsToRemove;

    // Check collisions in between Asteroids and Bullets
    for (int i = 0; i < view->getAsteroids().size(); ++i)
    {
        for (int j = 0; j < view->getBullets().size(); ++j)
        {
            if (view->getAsteroids()[i]->getBounds().intersects(view->getBullets()[j]->getBounds()))
            {
                // Check if Asteroid hasn't been removed already
                if (std::find(asteroidsToRemove.begin(), asteroidsToRemove.end(), i) == asteroidsToRemove.end())
                {
                    asteroidsToRemove.push_back(i);
                }
                bulletsToRemove.push_back(j);
            }
        }
    }
    view->removeBullets(bulletsToRemove);
    // Check collisions in between Asteroids and Ship
    for (int i = 0; i < view->getAsteroids().size(); ++i)
    {
        if (view->getAsteroids()[i]->getBounds().intersects(view->getShip().getBounds())) {
            // Dodaj indeks asteroidy do wektora asteroidsToRemove
            asteroidsToRemove.push_back(i);
            counter +=  1;
            if (counter >= 3)
            {
                view->endGame();
            }
            view->HPstatus();
        }
    }
    view->removeAsteroids(asteroidsToRemove);
}

