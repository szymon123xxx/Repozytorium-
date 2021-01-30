
#ifndef ENEMY_H
#define _ENEMY_H

#include "libraries.h"

class Enemy{

public:
    Enemy();
    ~Enemy();

    sf::Texture Enemy_Texture;
    sf::Sprite Enemy_Sprite; //Enemy sprite
    sf::Vector2f Enemy_Position;

};


#endif // _ENEMY_H
