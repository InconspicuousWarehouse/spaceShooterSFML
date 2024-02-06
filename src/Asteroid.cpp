#include "../headers/Asteroid.h"
#include <iostream>

Asteroid::Asteroid() : movementSpeed(0.0f) {}

Asteroid::~Asteroid() {}

void Asteroid::initializeAstShape()
{
    if (!texture.loadFromFile("C:\\Users\\SUPERKOMP\\CLionProjects\\Space\\Textures\\Asteroid2.png"))
    {
        std::cout << "ERROR, Asteroid, initializeAstShape: Couldn't load texture file." << "\n";
    }
    sprite.setTexture(texture);
}
void Asteroid::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}

const sf::FloatRect Asteroid::getBounds() const
{
    return sprite.getGlobalBounds();
}
float Asteroid::initializeSpeed()
{
    movementSpeed = 2.f;
    return movementSpeed;
}
void Asteroid::setAsteroidPosition(float pos_x, float pos_y)
{
    sprite.setPosition(pos_x, pos_y);
}
void Asteroid::update()
{
    sprite.move(0.f, movementSpeed);
    sf::Vector2f position = sprite.getPosition();
    float screenHeight = static_cast<float>(800);
    if (position.y > screenHeight)
    {
        delete this;
    }
}

