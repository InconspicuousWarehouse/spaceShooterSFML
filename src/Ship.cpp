#include "../headers/Ship.h"
#include <iostream>

Ship::Ship()
{
    initializeVariables();
}
Ship::~Ship() {}
void Ship::initializeShip()
{
    if (!texture.loadFromFile("C:\\Users\\SUPERKOMP\\CLionProjects\\Space\\Textures\\Space_ship2.png"))
    {
        std::cout << "ERROR::Ship::initializeShip:: Couldn't load texture file." << "\n";
    }
}
void Ship::initializeSprite()
{
    sprite.setTexture(texture);
    sprite.scale(1.f, 1.f);
}
void Ship::setShipPosition(float x, float y)
{
    sprite.setPosition(x - sprite.getGlobalBounds().width / 2, y);
}
void Ship::move(float offsetX, float offsetY, const sf::Vector2u& windowSize)
{
    // Move the ship
    sprite.move(offsetX, offsetY);

    // Limit the ship's movement within the screen boundaries
    sf::Vector2f position = sprite.getPosition();
    if (position.x < 0)
        position.x = 0;
    else if (position.x > windowSize.x - sprite.getGlobalBounds().width)
        position.x = windowSize.x - sprite.getGlobalBounds().width;

    if (position.y < 0)
        position.y = 0;
    else if (position.y > windowSize.y - sprite.getGlobalBounds().height)
        position.y = windowSize.y - sprite.getGlobalBounds().height;

    sprite.setPosition(position);
}
void Ship::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}
sf::FloatRect Ship::getBounds() const
{
    return sprite.getGlobalBounds();
}
float Ship::initializeSpeed() const
{
    return 2.0f;
}
bool Ship::canAttack()
{
    if (attackCooldown >= attackCooldownMax)
    {
        attackCooldown = 0.f;
        return true;
    }
    return false;
}
void Ship::attack()
{
    if(attackCooldown < attackCooldownMax)
        attackCooldown += 0.3f;
}
void Ship::initializeVariables()
{
    attackCooldownMax = 30.f;
    attackCooldown = attackCooldownMax;
}
