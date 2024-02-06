#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>

class Ship {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float attackCooldown;
    float attackCooldownMax;
public:
    Ship();
    ~Ship();
//Initialization:
    sf::FloatRect getBounds() const;
    float initializeSpeed() const;
    void initializeVariables();
    void initializeShip();
    void initializeSprite();
    void setShipPosition(float x, float y);
//Movement:
    void move(float offsetX, float offsetY, const sf::Vector2u& windowSize);
    void render(sf::RenderWindow& window);
//    Attack:
    void attack();
    bool canAttack();
};

#endif //SHIP_H
