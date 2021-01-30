#include "enemy.h"

Enemy::Enemy()
{
    this->Enemy_Texture.loadFromFile("player.png");
//    if (this->Enemy_Texture.loadFromFile("player.png"))
//        std::cout<<"Enemy loaded";

    this->Enemy_Sprite.setTexture(Enemy_Texture);

    float x = 500;
    float y = 400;

    this->Enemy_Sprite.setPosition(x, y);

    this->Enemy_Position = {x,y};
}

