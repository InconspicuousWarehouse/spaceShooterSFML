#include "../headers/View.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

View::View() : hpValue(3)
{
    window.create(sf::VideoMode(800, 750), "Space Shooter!", sf::Style::Default);
    window.setFramerateLimit(144);
    ship.initializeShip();
    ship.initializeSprite();
    ship.setShipPosition(window.getSize().x / 2.f, window.getSize().y / 2.f + 100.f);
    initializeBackground();
    initializeFonts();
    setFonts();
    setHPfonts();
    initializeHeart();
}
View::~View()
{
    window.close();
    clearAsteroids();
    clearAsteroids();
}
float View::getShipSpeed() const
{
    return ship.initializeSpeed();
}
std::vector<Asteroid*>& View::getAsteroids()
{
    return asteroids;
}
sf::Vector2u View::getWindowSize() const
{
    return window.getSize();
}
std::vector<Bullet *> &View::getBullets()
{
    return bullets;
}
/////////////////////////////////// Events ///////////////////////////////////
void View::pollEvents()
{
    sf::Event eve;
    while (window.pollEvent(eve))
    {
        if (eve.type == sf::Event::Closed)
            window.close();
        if (eve.type == sf::Event::KeyPressed && eve.key.code == sf::Keyboard::Escape)
            window.close();
    }
}
void View::render(float dirX, float dirY)
{
    window.clear();
    window.draw(backgroundSprite);

    ship.move(dirX, dirY, window.getSize());
    setHP(hpValue);

    if (gameEnded == false)
    {
        ship.render(window);
        renderHeart(window);
        drawHP();
        for (Asteroid *asteroid: asteroids)
        {
            asteroid->render(window);
        }
        for (Bullet *bullet: bullets)
        {
            bullet->render(window);
        }
    }
    else
    {
        drawGameOver();
    }
    window.display();
}
bool View::isOpen() const
{
    return window.isOpen();
}
void View::initializeBackground()
{
    if (!backgroundTexture.loadFromFile("C:\\Users\\SUPERKOMP\\CLionProjects\\Space\\Textures\\back.png"))
    {
        std::cout<< "Error";
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(static_cast<float>(window.getSize().x) / backgroundSprite.getLocalBounds().width,
                              static_cast<float>(window.getSize().y) / backgroundSprite.getLocalBounds().height);
}
/////////////////////////////////// Asteroids ///////////////////////////////////
void View::addAsteroid(float pos_x, float pos_y)
{
    Asteroid* newAsteroid = new Asteroid;
    newAsteroid->initializeAstShape();
    newAsteroid->setAsteroidPosition(pos_x, pos_y);
    newAsteroid->initializeSpeed();
    asteroids.push_back(newAsteroid);
}
void View::spawnAsteroid(float spawnTimerMax)
{
    static sf::Clock clock;
    if (clock.getElapsedTime().asSeconds() >= spawnTimerMax)
    {
        int randomPosition = std::max(0, rand() % (800 - 90));
        addAsteroid(static_cast<float>(randomPosition), -100.f);
        clock.restart();
    }
}
void View::removeAsteroid(unsigned index)
{
    if (index < asteroids.size())
    {
        asteroids.erase(asteroids.begin() + index);
    }
}
void View::clearAsteroids()
{
    for (Asteroid* asteroid : asteroids)
    {
        delete asteroid;
    }
    asteroids.clear();
}
void View::removeAsteroids(const std::vector<int>& indicesToRemove)
{
    for (int index : indicesToRemove)
    {

        if (index >= 0 && index < asteroids.size())
        {

            delete asteroids[index];
            asteroids.erase(asteroids.begin() + index);
        }
    }
}
/////////////////////////////////// Bullets: ///////////////////////////////////
void View::addBullet(float pos_x, float pos_y)
{
    Bullet* newBullet = new Bullet;
    newBullet->initializeBulletShape();
    newBullet->setBulletPosition(pos_x, pos_y);
    newBullet->initializeSpeed();
    bullets.push_back(newBullet);
}
void View::spawnBullet()
{
    sf::FloatRect shipBounds = ship.getBounds();
    sf::Vector2f shipPosition(shipBounds.left, shipBounds.top);
    float shipWidth = shipBounds.width;
    float bulletPosX = shipPosition.x + shipWidth / 2.f;
    float bulletPosY = shipPosition.y;
    addBullet(bulletPosX, bulletPosY);
}
void View::clearBullets()
{
    for (Bullet* bullet : bullets)
    {
        delete bullet;
    }
    bullets.clear();
}
void View::removeBullets(const std::vector<int>& indicesToRemove)
{
    for (int index : indicesToRemove)
    {
        if (index >= 0 && index < bullets.size())
        {
            delete bullets[index];
            bullets.erase(bullets.begin() + index);
        }
    }
}
/////////////////////////////////// Fonts ///////////////////////////////////
void View::initializeFonts()
{
    if(!font.loadFromFile("C:\\Users\\SUPERKOMP\\CLionProjects\\Space\\Fonts\\RobotoSlab-ExtraBold.ttf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
    }
}
void View::setFonts()
{
    text.setPosition(250.f, 300.f);
    text.setFont(this->font);
    std::string string="Game Over ";
    text.setString(string);

    text.setCharacterSize(60);
    text.setFillColor(sf::Color::White);
}
/////////////////////////////////// HP ///////////////////////////////////
void View::setHPfonts()
{
    hpText.setPosition(28.5f, 20.f);
    hpText.setFont(this->font);

    hpText.setCharacterSize(20);
    hpText.setFillColor(sf::Color::Green);
}
void View::initializeHeart()
{
    if (!texture.loadFromFile("C:\\Users\\SUPERKOMP\\CLionProjects\\Space\\Textures\\heart4.png"))
    {
        std::cout << "ERROR, Asteroid, initializeHeartShape: Couldn't load texture file." << "\n";
    }
    sprite.setTexture(texture);
}
void View::HPstatus()
{
    hpValue -= 1;
    setHP(hpValue);
}
void View::setHP(int hpValue)
{
    hpText.setString(std::to_string(hpValue));
}
void View::drawHP()
{
    window.draw(hpText);
}
void View::renderHeart(sf::RenderWindow& window)
{
    window.draw(sprite);
}
/////////////////////////////////// endGame ///////////////////////////////////
void View::endGame()
{
    gameEnded = true;
    clearAsteroids();
    clearBullets();
}
void View::drawGameOver()
{
    window.draw(text);
}