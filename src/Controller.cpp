#include "../headers/Controller.h"

Controller::Controller() : view(new View()), dirX(0.0f), dirY(0.0f)
{
    setShip(new Ship());
}
Controller::~Controller()
{
    delete view;
    delete ship;
}
void Controller::run()
{
    while (view->isOpen())
    {
        update();
        render();

    }
}
void Controller::pollEvents()
{
    view->pollEvents();
    float speed = view->getShipSpeed();
    dirX = 0.0f;
    dirY = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        dirX -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        dirX += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        dirY -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        dirY += speed;

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Left)) && ship->canAttack())
    {
        view->spawnBullet();
    }
}
void Controller::update()
{
    pollEvents();
    ship->attack();
    view->spawnAsteroid(0.4f);
    // Update game logic to check collisions
    GameLogic gameLogic(view);
    gameLogic.checkCollisions();
    // Update bullets position
    for (auto& bullet : view->getBullets())
    {
        bullet->update();
    }
    // Update asteroids position
    unsigned counter = 0;
    for (auto& asteroid : view->getAsteroids())
    {
        asteroid->update();
        if (asteroid->getBounds().top >= view->getWindowSize().y)
        {
            view->removeAsteroid(counter);
            --counter;
        }
        ++counter;
    }
}
void Controller::render()
{
    view->render(dirX, dirY);
}
void Controller::setShip(Ship* shipPtr)
{
    ship = shipPtr;
}
