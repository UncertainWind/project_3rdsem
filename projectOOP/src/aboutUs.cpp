#include "aboutUs.h"
using namespace sf;
using namespace std;

void aboutUs::drawabout(RenderWindow &window)
{
    window.draw(sprite);
}

aboutUs::aboutUs(float width,float height)
{
    if(!font.loadFromFile("fonts/arialmt.ttf")) {}
    texture.loadFromFile("image/rickroll.jpg");
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(0,0));

    sf::RenderWindow window(VideoMode(width,height), "About Us");
    sf::Event e;


    while (window.isOpen())
    {
        while(window.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                window.close();
                break;
            }
            if (e.type==Event::KeyReleased)
            {
                if(e.key.code==Keyboard::Return)
                {
                    window.close();
                }
            }
        }
        float x,y;
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            window.close();

        }
        window.clear(Color(119,134,235));
        drawabout(window);
        window.display();

    }


}

aboutUs::~aboutUs()
{
    //dtor
}
