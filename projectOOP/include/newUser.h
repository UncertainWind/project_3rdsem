#ifndef NEWUSER_H
#define NEWUSER_H
#include <SFML/Graphics.hpp>
#include<string>
#define maxoption 2
using namespace sf;
class newUser
{
public:
    void moveDown();
    void moveUp();
    int option()
    {
        return optionSelected;
    }

    newUser(float width,float height);
    void draw_newUser(sf::RenderWindow &window);
    void createFile(std::string& userFile,std::string& encryptPassword);
    int returnKey()
    {
        return key;
    }

    virtual ~newUser();
protected:

private:
    sf::Texture texture;
    sf::Sprite sprite;
    int optionSelected;
    sf::Text main_menu[maxoption];
    std::string encryptPassword;
    int key=3;                      //key for encryption
    sf::Font font;
    sf::Text titleText[2];
    sf::Text userText[4];
    sf::Text text[2];
    std::string username;
    std::string password;
    std::string display;
    sf::Text text_proceed[2];
    sf::Text details[2];
    sf::RectangleShape rectangle[2];
    sf::RectangleShape signin;
    int signup=0;
};

#endif // NEWUSER_H
