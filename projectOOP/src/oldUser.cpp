#include<iostream>
#include<string>
#include "oldUser.h"
#include "userLogin.h"
#include<fstream>
#include<conio.h>
#include<dirent.h>
#include <bits/stdc++.h>
using namespace std;
using namespace sf;

void oldUser::draw_usersList(RenderWindow &window,int k)
{
    window.draw(userText[0]);
    int j;
    for(j=0; j<k-3; j++)
    {
        window.draw(users[j]);
        window.draw(sprite[j]);
        // window.draw(usersign[j]);
    }
}

oldUser::oldUser(float width, float height)
{
    if(!font.loadFromFile("fonts/arialmt.ttf")) {}

    sf::RenderWindow window(VideoMode(width,height), "Returning User");
    sf::Event event;
    userText[0].setFont(font);
    userText[0].setString("Choose your Account");
    userText[0].setPosition((width/2)-(width/8),(height/8));
    userText[0].setColor(Color::White);

    texture[0].loadFromFile("image/1.bmp");
    texture[1].loadFromFile("image/2.bmp");
    texture[2].loadFromFile("image/3.bmp");
    texture[3].loadFromFile("image/4.bmp");
    texture[4].loadFromFile("image/5.bmp");
    texture[5].loadFromFile("image/6.bmp");
    texture[6].loadFromFile("image/7.bmp");

    while (window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

        }
        viewfiles(window,width,height);
        window.clear(Color(119,134,235));
        draw_usersList(window,viewfiles(window,width,height));
        window.display();
    }

    //ctor
}
int oldUser::viewfiles(RenderWindow &window,float width,float height)
{
    int done, i=1,j,k,l=0;
    DIR *dir;
    dirent *pdir;
    l++;
    dir=opendir("accounts/");
    while(pdir=readdir(dir))
    {
        if(i>2)
        {
            userList[i-3]=pdir->d_name;
        }
        i++;
    }
    if(l=2)
    {
        options(window,i,width,height);
        return i;
    }

    closedir(dir);


}
void oldUser::options(sf::RenderWindow &window,int k,float width,float height)
{
    int j, l;
    int sze=0;
    for(j=0; j<k-3; j++)
    {
        for(l=0; l<=3; l++)
        {
            userList[j].erase(userList[j].size() - 1, 1);
        }
        users[j].setFont(font);
        users[j].setString(userList[j]);
        users[j].setColor(Color::Green);
        users[j].setCharacterSize(26);

        sprite[j].setTexture(texture[j]);
        sprite[j].scale(1,1);

        sze++;
    }
    float divide=width/sze;
    for(int pos=0; pos<=sze; pos++)
    {
        users[pos].setPosition(20+pos*divide,(height/4)+(height/16)+130);
        sprite[pos].setPosition(10+pos*divide,(height/4)+(height/16));
    }

    float x,y;
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        Vector2i mousePos =Mouse::getPosition(window);      //gets position of click on mouse
        x=(float)mousePos.x;
        y=(float)mousePos.y;
        for(int pos=0; pos<=sze; pos++)
        {
            if(x>=10+pos*divide && y>=(height/4)+(height/16) && x<=10+pos*divide+128 && y<=(height/4)+(height/16)+128)
            {
                window.close();
                userLogin(400,600,userList[pos],pos);
            }
        }
    }


}

oldUser::~oldUser()
{
    //dtor
}
