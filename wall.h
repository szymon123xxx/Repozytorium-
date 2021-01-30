#ifndef _WALL_H
#define _WALL_H

#include "libraries.h"

class Wall{
public:
    Wall();
    ~Wall();

    sf::Texture back_Texture;
    sf::Sprite back_Sprite;

    sf::Texture wall_Texture_horizontal;
    sf::Sprite wall_Sprite_horizontal;

    sf::Texture wall_Texture_vertical;
    sf::Sprite wall_Sprite_vertical;

    std::vector<sf::Sprite> walls;

    float position[36];
    std::mt19937 generator;

//    std::uniform_int_distribution<uint32_t> wall_x = std::uniform_int_distribution<uint32_t> (0, 800);
//    std::uniform_int_distribution<uint32_t> wall_y = std::uniform_int_distribution<uint32_t> (0, 800);


    void walls2(sf::RenderWindow* window);
    void LevelMedium(sf::RenderWindow* window);
    void LevelHard(sf::RenderWindow* window);
};

#endif //_WALL_H
