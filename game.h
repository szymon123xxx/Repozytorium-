#ifndef GAME_H
#define GAME_H


#include "libraries.h"
#include "player.h"
#include "enemy.h"
#include "wall.h"
#include "menu.h"
#include "scoreAndGraph.h"
#include "menuLevels.h"
#include "menuMusic.h"
#include "menuListScore.h"
class Game{
private:
    
    sf::RenderWindow *window;
    sf::Event event;
    Player *player;
    Enemy *enemy;
    Wall *wall;
    Menu *menu;
    ScoreAndGraph *scoreAndGraph;
    MenuLevels *menuLevels;
    MenuMusic *menuMusic;
    MenuListScore * menuListScore;

    void initWindow();
    void IPlayer();
    void IEnemy();
    void IWall();
    void IMenu();
    void IscoreAndGraph();
    void IMenuLevels();
    void IMenuMusic();

    void IMenuListScore();

public:
    
    Game();
    ~Game();

    
    void SFMLevents();
    void SFMLeventsMenu();
    void SFMLeventsLevelMenu();
    void SFMLeventsMusicMenu();
    void SFMLeventsListScore();
    void playerMove(); //updating move
    void update();
    void render();
    void run();
    void renderMenu();
    void menuRun();
    void menuLevelRun();
    void renderLevelMenu();
    void renderMusicMenu();
    void menuMusicRun();

    void renderListScoreRun();
    void menuListScoreRun();

};

#endif // GAME_H
