//
// Created by szymon on 01.12.2020.
//

#ifndef CPP_PROJEKT_REPOZYTORIUM_MAIN_SCOREANDGRAPH_H
#define CPP_PROJEKT_REPOZYTORIUM_MAIN_SCOREANDGRAPH_H
#include "libraries.h"

class ScoreAndGraph {
public:
    ScoreAndGraph();
    ~ScoreAndGraph();

    sf::Font font;
    sf::Text score;
    sf::Text score2;
    sf::Text time;

    int score_int;
    int count_HP;
    std::string score_text;
    sf::Texture Score_Texture;
    sf::Sprite Score_Sprite;

    sf::Texture HP_Red_Texture;
    sf::Sprite HP_Red_Sprite1;
    sf::Sprite HP_Red_Sprite2;
    sf::Sprite HP_Red_Sprite3;

    sf::Texture HP_Black_Texture;
    sf::Sprite HP_Black_Sprite;

    sf::Clock clock;
    int countdown ;
    sf::Text timerText;



};


#endif //CPP_PROJEKT_REPOZYTORIUM_MAIN_SCOREANDGRAPH_H
