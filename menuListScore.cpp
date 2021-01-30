//
// Created by szymon on 25.01.2021.
//

#include "menuListScore.h"


MenuListScore::MenuListScore()
{
//    if (!font.loadFromFile("Cherry Caramel.ttf"))
//    {
//        // handle error
//    }
//    this->Menu_Texture.loadFromFile("menu-tlo2.png");
//    this->Menu_Sprite.setTexture(Menu_Texture);
//
////    std::fstream myfiles("scoresfile.txt", std::ios_base::in);
////    int a , b, c;
////    myfiles >> a ;
////    std::cout << a ;
////    std::cout << b ;
////    std::cout << c ;
////    while (myfiles >> a)
////    {
////        std::cout<< a <<' ';
////    }
//
//    std::fstream myfiles("scoresfile.txt", std::ios_base::in);
//
//    while (myfiles >> x)
//        array.insert(array.begin() , x);
//
//    for (unsigned i = 0; i < array.size(); i++)
//        std::cout << array[i] <<' ';
//
//
//
//    menu[0].setFont(font);
//    menu[0].setFillColor(sf::Color::Red);
//    menu[0].setString( "Back");
//    menu[0].setCharacterSize(80);
//    menu[0].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITE + 1) * 1));
//
//    menu[1].setFont(font);
//    menu[1].setFillColor(sf::Color::White);
//    menu[1].setString(std::to_string(array[1]));
//    menu[1].setCharacterSize(50);
//    menu[1].setPosition(sf::Vector2f(width/(MAX_NUMBER_OF_ITE + 1) * 3, height/(MAX_NUMBER_OF_ITE + 1) * 2));
//
//    menu[2].setFont(font);
//    menu[2].setFillColor(sf::Color::White);
//    menu[2].setString(std::to_string(array[0]));
//    menu[2].setCharacterSize(50);
//    menu[2].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITE + 1) * 2));
//
//    selectedItemIndex = 0;
}

void MenuListScore::draw(float width, float height, std::vector<int> array)
{
    if (!font.loadFromFile("Cherry Caramel.ttf"))
    {
        // handle error
    }
    this->Menu_Texture.loadFromFile("menu-tlo2.png");
    this->Menu_Sprite.setTexture(Menu_Texture);

//    std::fstream myfiles("scoresfile.txt", std::ios_base::in);
//    int a , b, c;
//    myfiles >> a ;
//    std::cout << a ;
//    std::cout << b ;
//    std::cout << c ;
//    while (myfiles >> a)
//    {
//        std::cout<< a <<' ';
//    }
//
//    std::fstream myfiles("scoresfile.txt", std::ios_base::in);
//
//    while (myfiles >> x)
//        array.insert(array.begin() , x);
//
//    for (unsigned i = 0; i < array.size(); i++)
//        std::cout << array[i] <<' ';



    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString( "Back");
    menu[0].setCharacterSize(80);
    menu[0].setPosition(sf::Vector2f(width/2, 200));

    menu1.setFont(font);
    menu1.setFillColor(sf::Color::White);
    menu1.setString(std::to_string(array[0]));
    menu1.setCharacterSize(50);
    menu1.setPosition(sf::Vector2f(550, 445));

    menu2.setFont(font);
    menu2.setFillColor(sf::Color::White);
    menu2.setString(std::to_string(array[1]));
    menu2.setCharacterSize(50);
    menu2.setPosition(sf::Vector2f(750, 445));

    selectedItemIndex = 0;
}

MenuListScore::~MenuListScore() {};

void MenuListScore::menu_ListScore_draw(sf::RenderWindow *window) {

    window->draw(this->menu2);
    window->draw(this->menu1);

    for (int i=0; i < MAX_NUMBER_OF_ITE; i++)
    {
        window->draw(this->menu[i]);
    }
}

void MenuListScore::MoveUp() {
    if(selectedItemIndex - 1 >= 0)
    {
        this->menu[selectedItemIndex].setFillColor(sf::Color::White);
        this->menu[selectedItemIndex].setCharacterSize(50);
        selectedItemIndex--;
        this->menu[selectedItemIndex].setCharacterSize(80);
        this->menu[selectedItemIndex].setFillColor(sf::Color::Red);

    }
}

void MenuListScore::MoveDown() {
    if(selectedItemIndex + 1 <= MAX_NUMBER_OF_ITE-1)
    {
        this->menu[selectedItemIndex].setFillColor(sf::Color::White);
        this->menu[selectedItemIndex].setCharacterSize(50);
        selectedItemIndex++;
        this->menu[selectedItemIndex].setCharacterSize(80);
        this->menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
