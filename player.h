#ifndef PLAYER_H
#define PLAYER_H

#include "libraries.h"

class Player{

public:
 Player();
 ~Player();

 sf::Texture _Texture;
 sf::Sprite _Sprite; //Player sprite
 sf::Vector2f _Position;
 sf::Vector2f Speed;

 sf::Vector2f _Position2;

 void moving(sf::Vector2f _Position );

};

#endif
