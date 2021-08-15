#include<iostream>
#include "aboutUs.h"
#include <mainMemu.h>
#include"newUser.h"
#include"oldUser.h"
using namespace sf;

mainMemu::mainMemu(float width, float height)
{
    if(!font.loadFromFile("fonts/arialmt.ttf")) {}
    main_menu[0].setFont(font);
    main_menu[0].setString("New User");
    main_menu[0].setCharacterSize(40);
    main_menu[0].setColor(Color::Green);
    main_menu[0].setPosition(Vector2f((width/2)-40,height/(maxMenu+1)*1));
    main_menu[0].setFillColor(Color::White);

    main_menu[1].setFont(font);
    main_menu[1].setString("Existing User");
    main_menu[1].setCharacterSize(40);
    main_menu[1].setColor(Color::Green);
    main_menu[1].setPosition(Vector2f((width/2)-40,height/(maxMenu+1)*2));

    main_menu[2].setFont(font);
    main_menu[2].setString("About Us");
    main_menu[2].setCharacterSize(40);
    main_menu[2].setColor(Color::Green);
    main_menu[2].setPosition(Vector2f((width/2)-40,height/(maxMenu+1)*3));

    optionSelected=0;
    //ctor

    sf::RenderWindow window(sf::VideoMode(width, height), "Main Menu");
    sf::Event event;

    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type==sf::Event::KeyReleased)
            {
                if(event.key.code==sf::Keyboard::Up)
                {
                    mainMemu::moveUp();
                    break;
                }
                if(event.key.code==sf::Keyboard::Down)
                {
                    mainMemu::moveDown();
                    break;
                }
                if(event.key.code==sf::Keyboard::Return)
                {
                    int x = mainMemu::option();
                    if(x==0)
                    {

                        window.close();
                        pageNumber=0;

                    }
                    if(x==1)
                    {
                        window.close();
                        pageNumber=1;
                    }
                    if(x==2)
                    {
                        window.close();
                        pageNumber=2;
                    }
                }
            }
        }



        float x,y;
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mousePos =Mouse::getPosition(window);//gets position of click on mouse
            x=(float)mousePos.x;
            y=(float)mousePos.y;
            if(x>=(width/2)-40 && y >=height/(maxMenu+1)*1 && y<=height/(maxMenu+1)*1.75)
            {
                window.close();
                newUser(400,600);
            }
            else if(x>=(width/2)-40 && y >=height/(maxMenu+1)*2 && y<=height/(maxMenu+1)*2.75)
            {
                window.close();
                oldUser(800,800);
            }
            else if(x>=(width/2)-40 && y >=height/(maxMenu+1)*3 && y<=height/(maxMenu+1)*3.75)
            {
                window.close();
                aboutUs(468,351);
            }
        }
        window.clear(Color(119,134,235));
        mainMemu::drawMenu(window);
        window.display();

        if(pageNumber==0)
        {
            window.close();
            newUser(400,600);
        }
        if(pageNumber==1)
        {
            window.close();
            oldUser(800,800);
        }
        if(pageNumber==2)
        {
            window.close();
            aboutUs(468,351);
        }

    }

}


void mainMemu::drawMenu(RenderWindow &window)
{
    for (int i=0; i<=2; i++)
    {

        window.draw(main_menu[i]);
    }
}

void mainMemu::moveDown()
{
    if(optionSelected+1<=maxMenu)
    {
        main_menu[optionSelected].setColor(Color::Green);
        optionSelected++;

        if(optionSelected==3)
        {
            optionSelected=0;
        }
        main_menu[optionSelected].setColor(Color::White);
    }

}

void mainMemu::moveUp()
{
    if(optionSelected-1>=-1)
    {
        main_menu[optionSelected].setColor(Color::Green);
        optionSelected--;
        if(optionSelected==-1)
        {
            optionSelected=2;
        }
        main_menu[optionSelected].setColor(Color::White);
    }

}


mainMemu::~mainMemu()
{
    //dtor
}
