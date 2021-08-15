#include<iostream>
#include<fstream>
#include "newUser.h"
#include "newUserDetails.h"
#include<string>
#include<fstream>
using namespace std;
using namespace sf;

void newUser::draw_newUser(sf::RenderWindow &window)
{
    window.draw(sprite);
    window.draw(signin);
    window.draw(text_proceed[0]);
    for(int i=0; i<2; i++)
    {
        window.draw(rectangle[i]);
        window.draw(userText[i]);
        window.draw(details[i]);
    }
}

newUser::newUser(float width, float height)
{

    if(!font.loadFromFile("fonts/arialmt.ttf")) {}
    texture.loadFromFile("image/account.jpg");
    sprite.setTexture(texture);
    sprite.setPosition(width/3,height/10);
    sprite.scale(0.25,0.25);

    sf::RenderWindow window(sf::VideoMode(width, height), "New User Registration");
    sf::Event event;
    titleText[0].setFont(font);
    titleText[0].setString("Create a new account");
    titleText[0].setPosition((width/2)-(width/8),(height/2)-(height/3));
    titleText[0].setColor(sf::Color::White);

    userText[0].setFont(font);
    userText[0].setString("Username");
    userText[0].setPosition((width/8),(height/2)-(height/9));
    userText[0].setColor(sf::Color::White);
    userText[0].setCharacterSize(24);

    rectangle[0].setSize(sf::Vector2f(250, 28));
    rectangle[0].setOutlineColor(sf::Color::Black);
    rectangle[0].setOutlineThickness(2);
    rectangle[0].setPosition((width/8),(height/2)-(height/19));

    userText[1].setFont(font);
    userText[1].setCharacterSize(24);
    userText[1].setString("Password");
    userText[1].setPosition((width/8),(height/2)+(height/20));
    userText[1].setColor(sf::Color::White);

    rectangle[1].setSize(sf::Vector2f(250, 28));
    rectangle[1].setOutlineColor(sf::Color::White);
    rectangle[1].setOutlineThickness(2);
    rectangle[1].setPosition((width/8),(height/2)+(height/9));

    details[0].setFont(font);
    details[0].setCharacterSize(25);
    details[0].setColor(sf::Color::Black);
    details[0].setPosition((width/8),(height/2)-(height/18));

    details[1].setFont(font);
    details[1].setCharacterSize(25);
    details[1].setColor(sf::Color::Black);
    details[1].setPosition((width/8),(height/2)+(height/9));

    signin.setSize(sf::Vector2f(78, 30));
    signin.setFillColor(Color(0,128,255));
    signin.setPosition((width/2)+(width/4.2),(height/2)+(height/4));
    signin.setOutlineThickness(2.0f);
    signin.setOutlineColor(Color::Black);

    text_proceed[0].setCharacterSize(22);
    text_proceed[0].setFont(font);
    text_proceed[0].setString("Sign up");
    text_proceed[0].setFillColor(Color::White);
    text_proceed[0].setPosition((width/2)+(width/4),(height/2)+(height/4));

    userText[2].setFont(font);
    userText[2].setString("By signing in,You are agreeing our Terms and Conditions");
    userText[2].setPosition((width/26),(height/2)+(height/2.5));
    userText[2].setColor(sf::Color::White);
    userText[2].setCharacterSize(15);

    int asc;
    optionSelected=0;
    while (window.isOpen())
    {
        while(window.pollEvent(event))
        {

            if (event.type == Event::Closed)
            {
                window.close();
                break;
            }
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if(event.key.code==Keyboard::Up)
                {
                    newUser::moveUp();
                    break;
                }

                else if(event.key.code==Keyboard::Down)
                {
                    newUser::moveDown();
                    break;
                }

                break;

            case Event::TextEntered:
                if (option()==0)
                {

                    if (event.text.unicode == '\b')
                    {
                        // backspace is entered

                        if(username=="")
                        {
                            username="";
                        }
                        else
                        {
                            username.erase(username.size() - 1, 1);
                            details[0].setString(username);
                        }
                    }
                    else if(event.text.unicode<128)
                    {
                        //takes in string and sets it up for display on window
                        username+=static_cast<char>(event.text.unicode);
                        details[0].setString(username);
                    }
                }
                else if(option()==1)
                {

                    if ((event.text.unicode) == '\b')
                    {
                        if(password=="" || display=="")
                        {
                            display="";
                            password="";
                        }
                        else
                        {
                            //backspace is entered
                            display.erase(display.size() - 1, 1);
                            password.erase(password.size() - 1, 1);
                            details[1].setString(display);
                        }
                    }
                    else if(event.text.unicode<128)
                    {
                        //takes in string and sets it up for display on window
                        password+=static_cast<char>(event.text.unicode);
                        display+="*";
                        details[1].setString(display);
                    }
                }

                break;
            }
        }
        float x,y;
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mousePos =Mouse::getPosition(window);//gets position of click on mouse
            x=(float)mousePos.x;
            y=(float)mousePos.y;
            if(x>=(width/2)+(width/4.2) && y>=(height/2)+(height/4) && x<=(width/2)+(width/4.2)+75&& y<=(height/2)+(height/4)+30 )
            {
                signup=1;
                window.close();
            }
        }
        window.clear(Color(0,128,255));
        draw_newUser(window);
        window.display();
    }

    for(int ch=0; ch<password.length(); ch++)
    {
        asc=password[ch];

        encryptPassword+=static_cast<char>(asc+returnKey());
    }

    string nameoffile=username+".txt";
    if(signup==1)
    {
        createFile(nameoffile,encryptPassword);
        newUserDetails(800,650,username);
    }



}

void newUser::createFile(std::string& userFile,std::string& encryptPassword)
{
    std::string filename="accounts/"+userFile;
    fstream file;
    file.open(filename,ios::in | ios::out |ios:: trunc);
    file<<encryptPassword<<endl;
    file.close();
}


void newUser::moveDown()
{
    if(optionSelected+1<=maxoption)
    {
        rectangle[optionSelected].setOutlineColor(sf::Color::White);
        optionSelected++;

        if(optionSelected==2)
        {
            optionSelected=0;
        }
        rectangle[optionSelected].setOutlineColor(sf::Color::Black);
    }

}

void newUser::moveUp()
{
    if(optionSelected-1>=-1)
    {
        rectangle[optionSelected].setOutlineColor(sf::Color::White);
        optionSelected--;
        if(optionSelected==-1)
        {
            optionSelected=1;
        }
        rectangle[optionSelected].setOutlineColor(sf::Color::Black);
    }

}


newUser::~newUser()
{
    //dtor
}
