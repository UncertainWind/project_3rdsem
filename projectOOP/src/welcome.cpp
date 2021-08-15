#include<iostream>
#include "welcome.h"
#include<string>
#include "mainMemu.h"
#include<SFML/Graphics.hpp>
using namespace sf;
void welcome::drawWelcome(RenderWindow &window)
{
     window.draw(sprite);
}

welcome::welcome(float width, float height)
{
    if(!font.loadFromFile("fonts/arialmt.ttf")) {}
    texture.loadFromFile("image/logo.jpg");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(0,0));

        sf::RenderWindow window(VideoMode(width,height), "Welcome!");
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
                    window.clear();
                    mainMemu menu(800,600);
                }
            }
        }
        float x,y;
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            window.close();
            mainMemu(800,600);
        }
        window.clear(Color(119,134,235));
        drawWelcome(window);
        window.display();

    }


    }


welcome::~welcome()
{
    //dtor
}
