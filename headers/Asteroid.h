
#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>

class Asteroid
{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float movementSpeed;

public:
    Asteroid();
    ~Asteroid();
    const sf::FloatRect getBounds() const;
    float initializeSpeed();
    void setAsteroidPosition(float pos_x, float pos_y);
    void initializeAstShape();
    void render(sf::RenderWindow& window);

    void update();
};

#endif //ASTEROID_H

