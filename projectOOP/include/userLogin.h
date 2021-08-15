#ifndef USERLOGIN_H
#define USERLOGIN_H
#include <SFML/Graphics.hpp>
#include<string>
using namespace sf;
using namespace std;
class userLogin
{
public:
    userLogin(float width,float height,std::string& userFile,int pos);
    void draw_userLogin(sf::RenderWindow &window);
    string readFile(std::string& userFile);
    void draw_incorrect(sf::RenderWindow &window);
    int returnKey()
    {
        return key;
    }

    virtual ~userLogin();

protected:

private:
    int key=3;
    sf::Texture texture[7];
    sf::Texture eye;
    sf::Sprite view;
    sf::Sprite sprite;
    sf::Font font;
    sf::Text text[2];
    sf::Text incorrect;
    sf::Text userText[2];
    sf::Text titleText[2];
    std::string password;
    std::string display;
    sf::Text text_proceed;
    sf::Text details;;
    sf::RectangleShape rectangle;
    sf::RectangleShape signin;
    int signup=0;
    int login=0;
    std::string decryptPassword;

};

#endif // USERLOGIN_H
