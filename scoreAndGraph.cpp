
#include "scoreAndGraph.h"
ScoreAndGraph::ScoreAndGraph() {
    if ((!font.loadFromFile("Cherry Caramel.ttf")) && (!font.loadFromFile("ostatnie.png")) && (!font.loadFromFile("zycko3.png")))
    {
        std::cout << "scoreAndGraph error" << std::endl;
    }
    this->Score_Texture.loadFromFile("Cherry Caramel.ttf");
    this->Score_Sprite.setTexture(Score_Texture);

    this->HP_Black_Texture.loadFromFile("ostatnie.png");
    this->HP_Black_Sprite.setTexture(HP_Black_Texture);

    this->HP_Red_Texture.loadFromFile("zycko3.png");
    this->HP_Red_Sprite1.setTexture(HP_Red_Texture);
    this->HP_Red_Sprite2.setTexture(HP_Red_Texture);
    this->HP_Red_Sprite3.setTexture(HP_Red_Texture);

    score.setFont(font);
    score.setFillColor(sf::Color::Cyan);
    score.setCharacterSize(80);
    score.setPosition(sf::Vector2f(450, 5));

    score2.setFont(font);
    score2.setFillColor(sf::Color::White);
    score2.setCharacterSize(60);
    score2.setPosition(sf::Vector2f(170, 440));

    time.setFont(font);
    time.setFillColor(sf::Color::Cyan);
    time.setCharacterSize(80);
    time.setPosition(sf::Vector2f(700, 5));

    this->HP_Red_Sprite1.setPosition(950, 20);
    this->HP_Red_Sprite2.setPosition(1000, 20);
    this->HP_Red_Sprite3.setPosition(1050, 20);

    this->HP_Black_Sprite.setPosition(1050, 20);
    score_int = 0;
    count_HP = 3;

    countdown = 8;

    timerText.setFont(font);
    timerText.setFillColor(sf::Color::Cyan);
    timerText.setPosition(850, 5);
    timerText.setCharacterSize(80);



}

