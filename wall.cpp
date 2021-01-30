#include "wall.h"

Wall::Wall(){
    this->back_Texture.loadFromFile("tlo.png");
//    if (this->back_Texture.loadFromFile("tlo.png"))
//        std::cout<<"background loaded";

    this->wall_Texture_horizontal.loadFromFile("sciana4.png");
//    if (this->wall_Texture_horizontal.loadFromFile("sciana4.png"))
//        std::cout<<"horizontal wall loaded";

    this->wall_Texture_vertical.loadFromFile("sciana5.png");
//    if (this->wall_Texture_vertical.loadFromFile("sciana5.png"))
//        std::cout<<"vertical wall loaded";

    this->back_Sprite.setTexture(back_Texture);
    this->wall_Sprite_vertical.setTexture(wall_Texture_vertical);
    this->wall_Sprite_horizontal.setTexture(wall_Texture_horizontal);

    for (int i = 0; i < 9; i++) {
        this->walls.push_back(wall_Sprite_horizontal);
        this->walls.push_back(wall_Sprite_vertical);
    }

    generator.seed(std::time(0));
    std::uniform_real_distribution<float> random(100, 800);
    for(int i=0; i < 36; i++)
    {
        this->position[i] = random(this->generator);
    }
}

Wall::~Wall(){}

void Wall::walls2(sf::RenderWindow* window){
    int variable = 0;
    for(int i=0; i < 6; i++) {
        this->walls[i].setPosition(sf::Vector2f(position[variable], position[variable+1]));
        variable+=2;
    }

    for (int i = 0; i < 6; i++) {
        window->draw(this->walls[i]);
    }
}

void Wall::LevelMedium(sf::RenderWindow* window){
    int variable2 = 0;
    for(int i=0; i < 12; i++) {
        std::cout << variable2 << std::endl ;
        this->walls[i].setPosition(sf::Vector2f(position[variable2], position[variable2+1]));
        variable2+=2;
    }

    for (int i = 0; i < 12; i++) {
        window->draw(this->walls[i]);
    }
}

void Wall::LevelHard(sf::RenderWindow* window){
    int variable3 = 0;
    for(int i=0; i < 18; i++) {
        this->walls[i].setPosition(sf::Vector2f(position[variable3], position[variable3+1]));
        variable3+=2;
    }

    for (int i = 0; i < 18; i++) {
        window->draw(this->walls[i]);
    }
}

