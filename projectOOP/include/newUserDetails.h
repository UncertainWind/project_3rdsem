#ifndef NEWUSERDETAILS_H
#define NEWUSERDETAILS_H
#include<SFML/Graphics.hpp>
#define maxMenu 7
class newUserDetails
{
public:
    newUserDetails(float width, float height,std::string& userFile);
    void draw_newUserDetails(sf::RenderWindow &window);
    void editFile(std::string& userFile,std::string info[7]);
      void moveDown();
    void moveUp();
    int returnKey(){
    return key;
    }
    int option()
    {
        return optionSelected;
    }

    virtual ~newUserDetails();

protected:

private:
    int key=3;
    sf::Texture texture;
	sf::Sprite sprite;
    int optionSelected;
    sf::Text user[1];
    sf::Font font;
    sf::Text account[7];
    sf::Text details[7];
    sf::Text text_save[1];
    sf::Text text_cancel[1];
    sf::Text title[1];
    std::string str[7];
    std::string display[7];
    std::string encrypt0;
    std::string encrypt1;
    std::string encrypt2;
    std::string encrypt3;
    std::string encrypt4;
    std::string encrypt5;
    std::string encrypt6;
    std::string encryptPassword[7];
    sf::RectangleShape box[7];
    sf::RectangleShape outerBox;
    sf::RectangleShape saveBox;
     sf::RectangleShape cancelBox;
     int save=0;
     int cancel=0;
};

#endif // NEWUSERDETAILS_H
