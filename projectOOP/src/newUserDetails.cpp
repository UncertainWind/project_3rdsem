#include "newUserDetails.h"
#include<iostream>
#include<fstream>
#include<string>
#include<fstream>
using namespace std;
using namespace sf;


void newUserDetails::draw_newUserDetails(sf::RenderWindow &window)
{
    window.draw(user[0]);
    window.draw(sprite);
    window.draw(outerBox);
    window.draw(saveBox);
    window.draw(text_save[0]);
    window.draw(cancelBox);
    window.draw(text_cancel[0]);
    for(int i=0; i<=6; i++)
    {
        window.draw(box[i]);
        window.draw(account[i]);
        window.draw(details[i]);

    }
}
newUserDetails::newUserDetails(float width, float height,std::string& userFile)
{

    if(!font.loadFromFile("fonts/arialmt.ttf")) {}
    texture.loadFromFile("image/account.jpg");
    sprite.setTexture(texture);
    sprite.setPosition(width/2,height/15);
    sprite.scale(0.25,0.25);


    sf::RenderWindow window(sf::VideoMode(width, height), "Save Details");
    sf::Event event;

    user[0].setFont(font);
    user[0].setString(userFile);
    user[0].setPosition((width/2)-10,165);
    user[0].setColor(sf::Color::White);

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

    details[0].setFont(font);
    details[0].setCharacterSize(20);
    details[0].setPosition((width/2)+(width/20),(240));
    details[0].setColor(sf::Color::Black);

    box[0].setSize(sf::Vector2f(280, 30));
    box[0].setOutlineColor(sf::Color::Black);
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

    text_save[0].setFont(font);
    text_save[0].setString("Save");
    text_save[0].setFillColor(Color::Black);
    text_save[0].setCharacterSize(30);
    text_save[0].setPosition((width/2)+(width/3.5)+2,584);


    saveBox.setSize(sf::Vector2f(80, 35));
    saveBox.setFillColor(Color(0,128,255));
    saveBox.setPosition((width/2)+(width/3.5),588);
    saveBox.setOutlineThickness(2.0f);
    saveBox.setOutlineColor(Color::White);

    text_cancel[0].setFont(font);
    text_cancel[0].setString("Cancel");
    text_cancel[0].setFillColor(Color::Black);
    text_cancel[0].setCharacterSize(30);
    text_cancel[0].setPosition((width/2)+2,584);

    cancelBox.setSize(sf::Vector2f(100, 35));
    cancelBox.setFillColor(Color(0,128,255));
    cancelBox.setPosition((width/2),588);
    cancelBox.setOutlineThickness(2.0f);
    cancelBox.setOutlineColor(Color::White);



    optionSelected=0;
//     int x = newUserDetails::option();
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
                    //marking--;
                    newUserDetails::moveUp();
                    break;

                    //if(marking==-1)
                     //   marking=0;
                }

                else if(event.key.code==Keyboard::Down)
                {
                    //marking++;
                    newUserDetails::moveDown();
                        break;
                }

                break;

            case Event::TextEntered:
                if (option() ==0)
                {
                    if (event.text.unicode == '\b')
                    {
                        //deleats a letter when backspace is entered

                        if(str[0]=="")
                        {
                            str[0]="";
                        }
                        else
                        {
                            str[0].erase(str[0].size() - 1, 1);
                            display[0]=str[0];
                            details[0].setString(display[0]);
                        }
                    }
                    else if(event.text.unicode<128)
                    {
                        //takes in string and sets it up for display on window
                        str[0]+=static_cast<char>(event.text.unicode);
                        display[0]=str[0];
                        details[0].setString(display[0]);
                    }
                }
                else if(option()==1)
                {


                    if (event.text.unicode == '\b')
                    {
                        //deleats a letter when backspace is entered

                        if(str[1]=="")
                        {
                            str[1]="";
                        }
                        else
                        {
                            str[1].erase(str[1].size() - 1, 1);
                            display[1]=str[1];
                            details[1].setString(display[1]);
                        }
                    }
                    else if(event.text.unicode<128)
                    {
                        //takes in string and sets it up for display on window
                        str[1]+=static_cast<char>(event.text.unicode);
                        display[1]=str[1];
                        details[1].setString(display[1]);
                    }
                }
                  else if(option()==2)
                {


                    if (event.text.unicode == '\b')
                    {
                        //deleats a letter when backspace is entered

                        if(str[2]=="")
                        {
                            str[2]="";
                        }
                        else
                        {
                            str[2].erase(str[2].size() - 1, 1);
                            display[2]=str[2];
                            details[2].setString(display[2]);
                        }
                    }
                    else if(event.text.unicode<128)
                    {
                        //takes in string and sets it up for display on window
                        str[2]+=static_cast<char>(event.text.unicode);
                        display[2]=str[2];
                        details[2].setString(display[2]);
                    }
                }
                  else if(option()==3)
                {


                    if (event.text.unicode == '\b')
                    {
                        //deleats a letter when backspace is entered

                        if(str[3]=="")
                        {
                            str[3]="";
                        }
                        else
                        {
                            str[3].erase(str[3].size() - 1, 1);
                            display[3]=str[3];
                            details[3].setString(display[3]);
                        }
                    }
                    else if(event.text.unicode<128)
                    {
                        //takes in string and sets it up for display on window
                        str[3]+=static_cast<char>(event.text.unicode);
                        display[3]=str[3];
                        details[3].setString(display[3]);
                    }
                }

                 else if(option()==4)
                {


                    if (event.text.unicode == '\b')
                    {
                        //deleats a letter when backspace is entered

                        if(str[4]=="")
                        {
                            str[4]="";
                        }
                        else
                        {
                            str[4].erase(str[4].size() - 1, 1);
                            display[4]=str[4];
                            details[4].setString(display[4]);
                        }
                    }
                    else if(event.text.unicode<128)
                    {
                        //takes in string and sets it up for display on window
                        str[4]+=static_cast<char>(event.text.unicode);
                        display[4]=str[4];
                        details[4].setString(display[4]);
                    }
                }

                   else if(option()==5)
                {


                    if (event.text.unicode == '\b')
                    {
                        //deleats a letter when backspace is entered

                        if(str[5]=="")
                        {
                            str[5]="";
                        }
                        else
                        {
                            str[5].erase(str[5].size() - 1, 1);
                            display[5]=str[5];
                            details[5].setString(display[5]);
                        }
                    }
                    else if(event.text.unicode<128)
                    {
                        //takes in string and sets it up for display on window
                        str[5]+=static_cast<char>(event.text.unicode);
                        display[5]=str[5];
                        details[5].setString(display[5]);
                    }
                }

                   else if(option()==6)
                {


                    if (event.text.unicode == '\b')
                    {
                        //deleats a letter when backspace is entered

                        if(str[6]=="")
                        {
                            str[6]="";
                        }
                        else
                        {
                            str[6].erase(str[6].size() - 1, 1);
                            display[6]=str[6];
                            details[6].setString(display[6]);
                        }
                    }
                    else if(event.text.unicode<128)
                    {
                        //takes in string and sets it up for display on window
                        str[6]+=static_cast<char>(event.text.unicode);
                        display[6]=str[6];
                        details[6].setString(display[6]);
                    }
                }

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
                save=1;
             //  editFile(userFile,encryptPassword);
            }
            if(x>=(width/2) && y>=588 && x<=(width/2)+100 && y<= 588+35)
            {
            cancel=1;
                window.close();
            }
        }
        window.clear(Color(0,128,255));
        draw_newUserDetails(window);
        window.display();
    }

        encrypt0=str[0];
        encrypt1=str[1];
        encrypt2=str[2];
        encrypt3=str[3];
        encrypt4=str[4];
        encrypt5=str[5];
        encrypt6=str[6];
         int asc[7];
         for(int ch=0; ch<encrypt0.length(); ch++)
    {
        asc[0]=encrypt0[ch];
         encryptPassword[0]+=static_cast<char>(asc[0]+returnKey());

    }
     for(int ch1=0; ch1<encrypt1.length(); ch1++)
    {
        asc[1]=encrypt1[ch1];
        encryptPassword[1]+=static_cast<char>(asc[1]+returnKey());
    }
     for(int ch2=0; ch2<encrypt2.length(); ch2++)
    {
        asc[2]=encrypt2[ch2];
        encryptPassword[2]+=static_cast<char>(asc[2]+returnKey());
    }
     for(int ch3=0; ch3<encrypt3.length(); ch3++)
    {
        asc[3]=encrypt3[ch3];
        encryptPassword[3]+=static_cast<char>(asc[3]+returnKey());
    }
     for(int ch4=0; ch4<encrypt4.length(); ch4++)
    {
        asc[4]=encrypt4[ch4];
        encryptPassword[4]+=static_cast<char>(asc[4]+returnKey());
    }
     for(int ch5=0; ch5<encrypt5.length(); ch5++)
    {
        asc[5]=encrypt5[ch5];
        encryptPassword[5]+=static_cast<char>(asc[5]+returnKey());
    }
     for(int ch6=0; ch6<encrypt6.length(); ch6++)
    {
        asc[6]=encrypt6[ch6];
        encryptPassword[6]+=static_cast<char>(asc[6]+returnKey());
    }


    if(save=1){
         editFile(userFile,encryptPassword);
    }

}
//ctor

void newUserDetails::editFile(std::string& userFile,std::string info[7])
{
    std::string filename="accounts/"+userFile;
    fstream file;
    file.open(filename+".txt",ios::app);
   // file<<encryptPassword;
   for(int i=0;i<=6;i++){
   file<<info[i]<<endl;
   }
    file.close();
}




void newUserDetails::moveDown()
{
    if(optionSelected+1<=maxMenu)
    {
       box[optionSelected].setOutlineColor(sf::Color::White);
        optionSelected++;

        if(optionSelected==7)
        {
            optionSelected=0;
        }
         box[optionSelected].setOutlineColor(sf::Color::Black);
    }

}


void newUserDetails::moveUp()
{
    if(optionSelected-1>=-1)
    {
       box[optionSelected].setOutlineColor(sf::Color::White);
        optionSelected--;
        if(optionSelected==-1)
        {
            optionSelected=6;
        }
        box[optionSelected].setOutlineColor(sf::Color::Black);
    }

}

newUserDetails::~newUserDetails()
{
    //dtor
}
