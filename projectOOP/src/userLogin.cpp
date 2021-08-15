#include "userLogin.h"
#include "viewFiles.h"
#include<iostream>
#include<fstream>
#include<string>
#include<fstream>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;

void userLogin::draw_userLogin(sf::RenderWindow &window)
{
    window.draw(userText[0]);
    window.draw(userText[1]);
    window.draw(rectangle);
    window.draw(sprite);
    window.draw(details);
    window.draw(signin);
    window.draw(text_proceed);
    window.draw(view);

}

userLogin::userLogin(float width, float height,std::string& userFile,int pos)
{
    int click;

    if(!font.loadFromFile("fonts/arialmt.ttf")) {}


    texture[0].loadFromFile("image/1.bmp");
    texture[1].loadFromFile("image/2.bmp");
    texture[2].loadFromFile("image/3.bmp");
    texture[3].loadFromFile("image/4.bmp");
    texture[4].loadFromFile("image/5.bmp");
    texture[5].loadFromFile("image/6.bmp");
    texture[6].loadFromFile("image/7.bmp");
    eye.loadFromFile("image/eye.png");


    sprite.setTexture(texture[pos]);
    sprite.setPosition(width/3,height/10);
    sprite.scale(1.25,1.25);

    view.setTexture(eye);
    view.setPosition((width/8)+260,(height/2)+(height/6));
    view.scale(0.15,0.15);

    titleText[0].setFont(font);
    titleText[0].setString("Create a new account");
    titleText[0].setPosition((width/2)-(width/8),(height/2)-(height/3));
    titleText[0].setColor(sf::Color::White);

    userText[0].setFont(font);
    userText[0].setString(userFile);
    userText[0].setPosition((width/2)-(width/8),(height/2)-(height/9)+10);
    userText[0].setColor(sf::Color::White);
    userText[0].setCharacterSize(40);

    incorrect.setFont(font);
    incorrect.setString("Incorrect Password");
    incorrect.setPosition((width/2),(height/2));
    incorrect.setColor(sf::Color::White);
    incorrect.setCharacterSize(40);



    userText[1].setFont(font);
    userText[1].setString("Master Password");
    userText[1].setPosition((width/8),(height/2)+(height/9)-10);
    userText[1].setColor(sf::Color::White);
    userText[1].setCharacterSize(24);

    details.setFont(font);
    details.setPosition((width/8),(height/2)+(height/6));
    details.setColor(sf::Color::Black);
    details.setCharacterSize(24);

    rectangle.setSize(sf::Vector2f(250, 28));
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(2);
    rectangle.setPosition((width/8),(height/2)+(height/6));

    signin.setSize(sf::Vector2f(78, 30));
    signin.setFillColor(Color(0,128,255));
    signin.setPosition((width/2)+(width/4.2),(height/2)+(height/4)+40);
    signin.setOutlineThickness(2.0f);
    signin.setOutlineColor(Color::Black);

    text_proceed.setCharacterSize(22);
    text_proceed.setFont(font);
    text_proceed.setString("Log in");
    text_proceed.setFillColor(Color::White);
    text_proceed.setPosition((width/2)+(width/4),(height/2)+(height/4)+40);

    sf::RenderWindow window(sf::VideoMode(width, height), "Enter your master password");
    sf::Event event;

    while (window.isOpen())
    {
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;

            case Event::KeyPressed:

                if(event.key.code==Keyboard::Return)
                {
                    if(password==readFile(userFile))
                    {
                        window.close();
                        viewFiles(800,650,userFile,pos);
                    }
                }
                break;

            case Event::TextEntered:

                if (event.text.unicode == '\b')
                {
                    // backspace is entered

                    if(password==""|| display=="")
                    {
                        password="";
                        display="";
                    }
                    else
                    {
                        display.erase(display.size() - 1, 1);
                        password.erase(password.size() - 1, 1);
                        //  details.setString(display);
                    }
                }
                else if(event.text.unicode<128)
                {
                    //takes in string and sets it up for display on window
                    password+=static_cast<char>(event.text.unicode);
                    display+="*";
                    // details.setString(display);
                }
                break;
            }
        }
        details.setString(display);

        float x,y;
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mousePos =Mouse::getPosition(window);//gets position of click on mouse
            x=(float)mousePos.x;
            y=(float)mousePos.y;
            if(x>=(width/8)+260 && y>=(height/2)+(height/6) && x<=(width/8)+260+38.85 && y<=(height/2)+(height/6)+29.1)
            {
                details.setString(password);
            }
            if(x>=(width/2)+(width/4.2) && y>=(height/2)+(height/4)+40 && x<=(width/2)+(width/4.2)+78 && y<=(height/2)+(height/4)+40+30)
            {
                if(password== readFile(userFile))
                {
                    window.close();
                    viewFiles(800,650,userFile,pos);
                }
            }
        }
        window.clear(Color(0,128,255));
        draw_userLogin(window);
        window.display();
    }


    //ctor
}

string userLogin::readFile(std::string& userFile)
{

    std::string pass;
    std::string filename="accounts/"+userFile+".txt";
    fstream file;
    file.open(filename,ios::in);
    getline(file,pass);
    file.close();
    int asc;
    for(int ch=0; ch<pass.length(); ch++)
    {
        asc=pass[ch];
        decryptPassword+=static_cast<char>(asc-returnKey());
    }
    return decryptPassword;

}
void userLogin::draw_incorrect(sf::RenderWindow &window)
{
    window.draw(incorrect);
}



userLogin::~userLogin()
{
    //dtor
}
