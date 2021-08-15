#ifndef MAINMEMU_H
#define MAINMEMU_H
#include <SFML/Graphics.hpp>
#define maxMenu 3
class mainMemu
{
public:
    mainMemu(float width, float height);
    void drawMenu(sf::RenderWindow &window);
    void moveDown();
    void moveUp();
    int option()
    {
        return optionSelected;
    }
    virtual ~mainMemu();

protected:

private:
    int pageNumber;
    int optionSelected;
    sf::Font font;
    sf::Text main_menu[maxMenu];
};

#endif // MAINMEMU_H
