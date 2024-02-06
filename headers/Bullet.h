#ifndef SPACE_BULLET_H
#define SPACE_BULLET_H

#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float movementSpeed;
public:
    Bullet();
    ~Bullet();
    const sf::FloatRect getBounds() const;
    float initializeSpeed();
    void initializeBulletShape();
    void render(sf::RenderWindow& window);
    void setBulletPosition(float pos_x, float pos_y);

    void update();
};

#endif //SPACE_BULLET_H
