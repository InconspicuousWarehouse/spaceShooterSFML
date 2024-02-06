#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Asteroid.h"
#include "Ship.h"
#include "Bullet.h"

class View
{
private:
    bool gameEnded = false;
    int hpValue;
    std::vector<std::pair<int, int>> collisions;
    std::vector<Asteroid*> asteroids;
    std::vector<Bullet*> bullets;
    sf::RenderWindow window;
    Ship ship;
//Graphics:
    sf::Font font;
    sf::Text text;
    sf::Text hpText;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
public:
    View();
    ~View();
//Variables:
    float getShipSpeed() const;
    std::vector<Asteroid*>& getAsteroids();
    Ship& getShip() { return ship; };
    sf::Vector2u getWindowSize() const;
    std::vector<Bullet*>& getBullets();
//Events:
    void pollEvents();
    void render(float dirX, float dirY);
    bool isOpen() const;

    void initializeBackground();
//Asteroids:
    void addAsteroid(float pos_x, float pos_y);
    void spawnAsteroid(float spawnTimerMax);
    void removeAsteroid(unsigned index);
    void clearAsteroids();
    void removeAsteroids(const std::vector<int>& indicesToRemove);
//Bullets:
    void addBullet(float pos_x, float pos_y);
    void spawnBullet();
    void clearBullets();
    void removeBullets(const std::vector<int>& indicesToRemove);
//Fonts:
    void initializeFonts();
    void setFonts();
//HP:
    void setHPfonts();
    void initializeHeart();
    void HPstatus();
    void setHP(int hpValue);
    void drawHP();
    void renderHeart(sf::RenderWindow& window);
//endGame:
    void endGame();
    void drawGameOver();

};
#endif // VIEW_H

