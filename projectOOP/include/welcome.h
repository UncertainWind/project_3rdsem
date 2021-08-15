#ifndef WELCOME_H
#define WELCOME_H
#include <SFML/Graphics.hpp>

class welcome
{
    public:
        welcome(float width, float height);
    void drawWelcome(sf::RenderWindow &window);
        virtual ~welcome();

    protected:

    private:
    sf::Font font;
    sf::Texture texture;
	sf::Sprite sprite;

};

#endif // WELCOME_H
