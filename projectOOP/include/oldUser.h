#ifndef OLDUSER_H
#define OLDUSER_H
#include <SFML/Graphics.hpp>

class oldUser
{
public:
    oldUser(float width,float height);
    int viewfiles(sf::RenderWindow &window,float width,float height);
    void options(sf::RenderWindow &window,int k,float width,float height);
    void draw_usersList(sf::RenderWindow &window,int k);
    virtual ~oldUser();

protected:

private:
    sf::Font font;
    sf::Texture texture[10];
    sf::Sprite sprite[10];
    sf::Text userText[1];
    std::string input;
    sf::Text output;
    sf::Text users[10];
    sf::Text usersign[10];
    std::string userList[10];

};

#endif // OLDUSER_H
