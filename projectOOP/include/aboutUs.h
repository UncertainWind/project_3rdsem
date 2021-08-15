#ifndef ABOUTUS_H
#define ABOUTUS_H
#include <SFML/Graphics.hpp>

class aboutUs
{
public:
    aboutUs(float width,float height);
    void drawabout(sf::RenderWindow &window);
    virtual ~aboutUs();

protected:

private:
    sf::Font font;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif // ABOUTUS_H
