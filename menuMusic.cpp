

#include "menuMusic.h"

MenuMusic::MenuMusic(float width, float height) {
    if (!font.loadFromFile("Cherry Caramel.ttf"))
    {
        // handle error
    }
    this->Menu_Texture.loadFromFile("menu-tlo2.png");
    this->Menu_Sprite.setTexture(Menu_Texture);

    this->music.openFromFile("music1.wav");
    this->music2.openFromFile("music2.wav");
    this->music3.openFromFile("music3.wav");
    this->obejcthit.openFromFile("PUNCH.wav");
    this->hitWall.openFromFile("uff.wav");

    this->music.setVolume(50);
    this->music2.setVolume(50);
    this->music3.setVolume(50);
    this->obejcthit.setVolume(50);
    this->hitWall.setVolume(50);

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Deep shadows");
    menu[0].setCharacterSize(80);
    menu[0].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMSSs + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Final round");
    menu[1].setCharacterSize(50);
    menu[1].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMSSs + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Itachi");
    menu[2].setCharacterSize(50);
    menu[2].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMSSs + 1) * 3));

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Back");
    menu[3].setCharacterSize(50);
    menu[3].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMSSs + 1) * 4));

    selectedItemIndex = 0;
}


MenuMusic::~MenuMusic() {}

void MenuMusic::menu_music_draw(sf::RenderWindow *window) {
    for (int i=0; i < MAX_NUMBER_OF_ITEMSSs; i++)
    {
        window->draw(this->menu[i]);
    }
}

void MenuMusic::MoveUp() {
    if(selectedItemIndex - 1 >= 0)
    {
        this->menu[selectedItemIndex].setFillColor(sf::Color::White);
        this->menu[selectedItemIndex].setCharacterSize(50);
        selectedItemIndex--;
        this->menu[selectedItemIndex].setCharacterSize(80);
        this->menu[selectedItemIndex].setFillColor(sf::Color::Red);

    }
}

void MenuMusic::MoveDown() {
    if(selectedItemIndex + 1 <= MAX_NUMBER_OF_ITEMSSs-1)
    {
        this->menu[selectedItemIndex].setFillColor(sf::Color::White);
        this->menu[selectedItemIndex].setCharacterSize(50);
        selectedItemIndex++;
        this->menu[selectedItemIndex].setCharacterSize(80);
        this->menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
