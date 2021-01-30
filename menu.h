
#ifndef CPP_PROJEKT_REPOZYTORIUM_MAIN_MENU_H
#define CPP_PROJEKT_REPOZYTORIUM_MAIN_MENU_H

#include "libraries.h"
#define MAX_NUMBER_OF_ITEMS 4

class Menu{
public:
    Menu(float width, float height);
    ~Menu();

    void menu_draw(sf::RenderWindow *window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() {return selectedItemIndex;}


    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Texture Menu_Texture;
    sf::Sprite Menu_Sprite;
};





#endif //CPP_PROJEKT_REPOZYTORIUM_MAIN_MENU_H
