
#include "menu.h"

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("Cherry Caramel.ttf"))
    {
         // handle error
    }
    this->Menu_Texture.loadFromFile("menu-tlo2.png");
    this->Menu_Sprite.setTexture(Menu_Texture);

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setCharacterSize(80);
    menu[0].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Music");
    menu[1].setCharacterSize(50);
    menu[1].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Scores");
    menu[2].setCharacterSize(50);
    menu[2].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS + 1) * 3));


    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setCharacterSize(50);
    menu[3].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS + 1) * 4));

    selectedItemIndex = 0;
}

Menu::~Menu() {

}

void Menu::menu_draw(sf::RenderWindow *window) {
    for (int i=0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window->draw(this->menu[i]);
    }
}

void Menu::MoveUp() {
    if(selectedItemIndex - 1 >= 0)
    {
        this->menu[selectedItemIndex].setFillColor(sf::Color::White);
        this->menu[selectedItemIndex].setCharacterSize(50);
        selectedItemIndex--;
        this->menu[selectedItemIndex].setCharacterSize(80);
        this->menu[selectedItemIndex].setFillColor(sf::Color::Red);

    }
}

void Menu::MoveDown() {
    if(selectedItemIndex + 1 <= MAX_NUMBER_OF_ITEMS-1)
    {
        this->menu[selectedItemIndex].setFillColor(sf::Color::White);
        this->menu[selectedItemIndex].setCharacterSize(50);
        selectedItemIndex++;
        this->menu[selectedItemIndex].setCharacterSize(80);
        this->menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
