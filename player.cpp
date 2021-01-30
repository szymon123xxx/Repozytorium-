#include "player.h"

Player::Player()
{
    this->_Texture.loadFromFile("postac.png");
//    if (this->_Texture.loadFromFile("postac.png"))
//      std::cout<<"Player loaded";

    this->_Sprite.setTexture(_Texture);

    float x = 350;
    float y = 20;

    this->_Sprite.setPosition(x, y);
    
    this->_Position = {x,y};

    this->Speed = {0.f, 0.f};
}


void Player::moving(sf::Vector2f _Position ){
    this->_Position.x += _Position.x;
    this->_Position.y += _Position.y;

    this->_Sprite.setPosition(this->_Position );
}



