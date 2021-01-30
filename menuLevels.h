

#ifndef CPP_PROJEKT_REPOZYTORIUM_MAIN_MENULEVELS_H
#define CPP_PROJEKT_REPOZYTORIUM_MAIN_MENULEVELS_H
#include "libraries.h"
#define MAX_NUMBER_OF_ITEMSS 4

class MenuLevels {
public:
    MenuLevels(float width, float height);
    ~MenuLevels();
    void MoveUp();
    void MoveDown();
    void menu_level_draw(sf::RenderWindow *window);
    int GetPressedItem() {return selectedItemIndex;}

    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMSS];
    sf::Texture Menu_Texture;
    sf::Sprite Menu_Sprite;

};


#endif //CPP_PROJEKT_REPOZYTORIUM_MAIN_MENULEVELS_H
