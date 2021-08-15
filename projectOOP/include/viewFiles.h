#ifndef VIEWFILES_H
#define VIEWFILES_H
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class viewFiles
{
public:
    viewFiles(float width,float height,std::string& userFile,int pos);
    void draw_viewFiles(sf::RenderWindow &window);
    void readFile(std::string& userFile);
    int returnKey()
    {
        return key;
    }

    virtual ~viewFiles();

protected:

private:
    int key=3;
    sf::Font font;
    sf::Texture texture[7];
    sf::Sprite sprite;
    sf::Text user;
    sf::RectangleShape outerBox;
    sf::Text account[7];
    sf::RectangleShape box[7];
    sf::Text details[7];
    sf::RectangleShape doneBox;
    sf::Text text_done;
    std::string encryptPassword[7];
    std::string encrypt0;
    std::string encrypt1;
    std::string encrypt2;
    std::string encrypt3;
    std::string encrypt4;
    std::string encrypt5;
    std::string encrypt6;
    std::string encrypt7;
};

#endif // VIEWFILES_H
