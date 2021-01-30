#ifndef CPP_PROJEKT_REPOZYTORIUM_MAIN_MENUMUSIC_H
#define CPP_PROJEKT_REPOZYTORIUM_MAIN_MENUMUSIC_H
#include "libraries.h"
#define MAX_NUMBER_OF_ITEMSSs 4

class MenuMusic {
public:
    MenuMusic(float width, float height);
    ~MenuMusic();
    void MoveUp();
    void MoveDown();
    void menu_music_draw(sf::RenderWindow *window);
    int GetPressedItem() {return selectedItemIndex;}

    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMSSs];
    sf::Texture Menu_Texture;
    sf::Sprite Menu_Sprite;

    sf::Music music;
    sf::Music music2;
    sf::Music music3;
    sf::Music obejcthit;

    sf::Music hitWall;


};



#endif //CPP_PROJEKT_REPOZYTORIUM_MAIN_MENUMUSIC_H
