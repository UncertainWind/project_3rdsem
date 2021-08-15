#include "viewFiles.h"
#include "welcome.h"
#include<iostream>
#include<fstream>
#include<string>
#include<fstream>
using namespace std;
using namespace sf;

void viewFiles::draw_viewFiles(sf::RenderWindow &window)
{


    window.draw(user);
    window.draw(sprite);
    window.draw(outerBox);
    window.draw(doneBox);
    window.draw(text_done);
    for(int i=0; i<=6; i++)
    {
        window.draw(box[i]);
        window.draw(account[i]);
        window.draw(details[i]);

    }
}

viewFiles::viewFiles(float width,float height,std::string& userFile,int pos)
{
    if(!font.loadFromFile("fonts/arialmt.ttf")) {}
    texture[0].loadFromFile("image/1.bmp");
    texture[1].loadFromFile("image/2.bmp");
    texture[2].loadFromFile("image/3.bmp");
    texture[3].loadFromFile("image/4.bmp");
    texture[4].loadFromFile("image/5.bmp");
    texture[5].loadFromFile("image/6.bmp");
    texture[6].loadFromFile("image/7.bmp");

    sprite.setTexture(texture[pos]);
    sprite.setPosition(width/2,height/15);
    sprite.scale(1,1);

    sf::RenderWindow window(sf::VideoMode(width, height), "Save Details");
    sf::Event event;

    user.setFont(font);
    user.setString(userFile);
    user.setPosition((width/2)-10,165);
    user.setColor(sf::Color::White);

    outerBox.setSize(sf::Vector2f(280*2, 310));
    outerBox.setOutlineColor(sf::Color::White);
    outerBox.setOutlineThickness(1);
    outerBox.setPosition((width/5)+15,220);
    outerBox.setFillColor(Color(0,128,255));

    account[0].setFont(font);
    account[0].setCharacterSize(20);
    account[0].setString("Email: ");
    account[0].setPosition((width/4),(240));
    account[0].setColor(sf::Color::Black);

    account[1].setFont(font);
    account[1].setString("Password: ");
    account[1].setCharacterSize(20);
    account[1].setPosition((width/4),(280));
    account[1].setColor(sf::Color::Black);


    account[2].setFont(font);
    account[2].setString("Citizenship Number:");
    account[2].setCharacterSize(20);
    account[2].setPosition((width/4),(320));
    account[2].setColor(sf::Color::Black);

    account[3].setFont(font);
    account[3].setString("Credit Card Number:");
    account[3].setCharacterSize(20);
    account[3].setPosition((width/4),(360));
    account[3].setColor(sf::Color::Black);

    account[4].setFont(font);
    account[4].setString("Driver License Number");
    account[4].setCharacterSize(20);
    account[4].setPosition((width/4),(400));
    account[4].setColor(sf::Color::Black);

    account[5].setFont(font);
    account[5].setString("ATM pin");
    account[5].setCharacterSize(20);
    account[5].setPosition((width/4),(440));
    account[5].setColor(sf::Color::Black);

    account[6].setFont(font);
    account[6].setString("Social Security Number");
    account[6].setCharacterSize(20);
    account[6].setPosition((width/4),(480));
    account[6].setColor(sf::Color::Black);

    box[0].setSize(sf::Vector2f(280, 30));
    box[0].setOutlineColor(sf::Color::White);
    box[0].setOutlineThickness(2.5);
    box[0].setPosition((width/2)+(width/20),240);

    box[1].setSize(sf::Vector2f(280, 30));
    box[1].setOutlineColor(sf::Color::White);
    box[1].setOutlineThickness(2.5);
    box[1].setPosition((width/2)+(width/20),280);

    box[2].setSize(sf::Vector2f(280,30));
    box[2].setOutlineColor(sf::Color::White);
    box[2].setOutlineThickness(2.5);
    box[2].setPosition((width/2)+(width/20),320);

    box[3].setSize(sf::Vector2f(280, 30));
    box[3].setOutlineColor(sf::Color::White);
    box[3].setOutlineThickness(2.5);
    box[3].setPosition((width/2)+(width/20),360);

    box[4].setSize(sf::Vector2f(280, 30));
    box[4].setOutlineColor(sf::Color::White);
    box[4].setOutlineThickness(2.5);
    box[4].setPosition((width/2)+(width/20),400);

    box[5].setSize(sf::Vector2f(280, 30));
    box[5].setOutlineColor(sf::Color::White);
    box[5].setOutlineThickness(2.5);
    box[5].setPosition((width/2)+(width/20),440);

    box[6].setSize(sf::Vector2f(280, 30));
    box[6].setOutlineColor(sf::Color::White);
    box[6].setOutlineThickness(2.5);
    box[6].setPosition((width/2)+(width/20),480);

    details[0].setFont(font);
    details[0].setCharacterSize(20);
    details[0].setPosition((width/2)+(width/20),(240));
    details[0].setColor(sf::Color::Black);

    details[1].setFont(font);
    details[1].setCharacterSize(20);
    details[1].setPosition((width/2)+(width/20),(280));
    details[1].setColor(sf::Color::Black);

    details[2].setFont(font);
    details[2].setCharacterSize(20);
    details[2].setPosition((width/2)+(width/20),(320));
    details[2].setColor(sf::Color::Black);

    details[3].setFont(font);
    details[3].setCharacterSize(20);
    details[3].setPosition((width/2)+(width/20),(360));
    details[3].setColor(sf::Color::Black);

    details[4].setFont(font);
    details[4].setCharacterSize(20);
    details[4].setPosition((width/2)+(width/20),(400));
    details[4].setColor(sf::Color::Black);

    details[5].setFont(font);
    details[5].setCharacterSize(20);
    details[5].setPosition((width/2)+(width/20),(440));
    details[5].setColor(sf::Color::Black);

    details[6].setFont(font);
    details[6].setCharacterSize(20);
    details[6].setPosition((width/2)+(width/20),(480));
    details[6].setColor(sf::Color::Black);

    text_done.setFont(font);
    text_done.setString("Done");
    text_done.setFillColor(Color::Black);
    text_done.setCharacterSize(30);
    text_done.setPosition((width/2)+(width/3.5)+2,584);


    doneBox.setSize(sf::Vector2f(80, 35));
    doneBox.setFillColor(Color(0,128,255));
    doneBox.setPosition((width/2)+(width/3.5),588);
    doneBox.setOutlineThickness(2.0f);
    doneBox.setOutlineColor(Color::White);

    readFile(userFile);

    while (window.isOpen())
    {
        while(window.pollEvent(event))
        {

            if (event.type == Event::Closed)
            {
                window.close();
                break;
            }

        }
        float x,y;
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mousePos =Mouse::getPosition(window);      //gets position of click on mouse
            x=(float)mousePos.x;
            y=(float)mousePos.y;
            if(x>=(width/2)+(width/3.5) && y>=588 && x<=(width/2)+(width/3.5)+80 && y<=588+35 )
            {
                window.close();
                welcome(500,500);
            }
        }


        window.clear(Color(0,128,255));
        draw_viewFiles(window);
        window.display();

    }


}

void viewFiles::readFile(std::string& userFile)
{
    int i=0;
    std::string line;
    std::string str[8];
    std::string filename="accounts/"+userFile+".txt";
    fstream file;
    file.open(filename,ios::in);
    while(getline(file,line))
    {
        cout<<line<<endl;
        str[i]=line;
        i++;
    }
    encrypt0=str[0];
    encrypt1=str[1];
    encrypt2=str[2];
    encrypt3=str[3];
    encrypt4=str[4];
    encrypt5=str[5];
    encrypt6=str[6];
    encrypt6=str[7];
    file.close();

    int asc[7];
    for(int ch=0; ch<encrypt0.length(); ch++)
    {
        asc[0]=encrypt0[ch];
        encryptPassword[0]+=static_cast<char>(asc[0]-returnKey());

    }
    for(int ch1=0; ch1<encrypt1.length(); ch1++)
    {
        asc[1]=encrypt1[ch1];
        encryptPassword[1]+=static_cast<char>(asc[1]-returnKey());
    }
    for(int ch2=0; ch2<encrypt2.length(); ch2++)
    {
        asc[2]=encrypt2[ch2];
        encryptPassword[2]+=static_cast<char>(asc[2]-returnKey());
    }
    for(int ch3=0; ch3<encrypt3.length(); ch3++)
    {
        asc[3]=encrypt3[ch3];
        encryptPassword[3]+=static_cast<char>(asc[3]-returnKey());
    }
    for(int ch4=0; ch4<encrypt4.length(); ch4++)
    {
        asc[4]=encrypt4[ch4];
        encryptPassword[4]+=static_cast<char>(asc[4]-returnKey());
    }
    for(int ch5=0; ch5<encrypt5.length(); ch5++)
    {
        asc[5]=encrypt5[ch5];
        encryptPassword[5]+=static_cast<char>(asc[5]-returnKey());
    }
    for(int ch6=0; ch6<encrypt6.length(); ch6++)
    {
        asc[6]=encrypt6[ch6];
        encryptPassword[6]+=static_cast<char>(asc[6]-returnKey());
    }
    for(int ch7=0; ch7<encrypt7.length(); ch7++)
    {
        asc[7]=encrypt7[ch7];
        encryptPassword[7]+=static_cast<char>(asc[7]-returnKey());
    }
    for(int j=1; j<i; j++)
    {
        details[j-1].setString(encryptPassword[j]);
    }

}

viewFiles::~viewFiles()
{
    //dtor
}
