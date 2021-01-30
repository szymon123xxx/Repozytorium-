

#ifndef CPP_PROJEKT_REPOZYTORIUM_MAIN_MENULISTSCORE_H
#define CPP_PROJEKT_REPOZYTORIUM_MAIN_MENULISTSCORE_H
#include "libraries.h"
#define MAX_NUMBER_OF_ITE 1

class MenuListScore {
public:
    MenuListScore();
    ~MenuListScore();
    void MoveUp();
    void MoveDown();
    void menu_ListScore_draw(sf::RenderWindow *window);
    int GetPressedItem() {return selectedItemIndex;}

    void draw(float width, float height, std::vector<int> array);

    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITE];
    sf::Texture Menu_Texture;
    sf::Sprite Menu_Sprite;

    sf::Text menu1;
    sf::Text menu2;

};


#endif
