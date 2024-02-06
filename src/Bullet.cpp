#include "../headers/Bullet.h"
#include <iostream>
Bullet::Bullet(): movementSpeed(0.0f) {}
Bullet::~Bullet() {}
void Bullet::initializeBulletShape()
{
    if (!texture.loadFromFile("C:\\Users\\SUPERKOMP\\CLionProjects\\Space\\Textures\\Bullet.png"))
    {
        std::cout << "ERROR, Asteroid, initializeAstShape: Couldn't load texture file." << "\n";
    }
    sprite.setTexture(texture);
}
void Bullet::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}
const sf::FloatRect Bullet::getBounds() const
{
    return sprite.getGlobalBounds();
}
float Bullet::initializeSpeed()
{
    movementSpeed = -2.f;
    return movementSpeed;
}
void Bullet::setBulletPosition(float pos_x, float pos_y)
{
    sprite.setPosition(pos_x, pos_y);
}
void Bullet::update()
{
    sprite.move(0.f, movementSpeed);
    sf::Vector2f position = sprite.getPosition();
    float screenHeight = static_cast<float>(800);
    if (position.y > screenHeight)
    {
        delete this;
    }
}
