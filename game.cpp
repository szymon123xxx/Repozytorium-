#include "game.h"
#include "menu.h"


void Game::initWindow() {
    int width_window = 1100;
    int height_window = 900;

    sf::VideoMode window_mode(width_window, height_window);

    int frame = 60;

    this->window = new sf::RenderWindow(window_mode, "The Virus");
    this->window->setFramerateLimit(frame);
}

void Game::SFMLevents(){
    while ( this->window->pollEvent(this->event))
    {
        if ( this->event.type == sf::Event::Closed)
        {
            this->window->close();
        }
    }
}
// musza byc 2 eventy bo inaczej dla menu i gierki robia sie jednoczesnie
void Game::SFMLeventsMenu(){
    while (this->window->pollEvent(this->event)){

        switch (event.type){

            case sf::Event::KeyReleased:
                switch (event.key.code){
                    case sf::Keyboard::W:
                        menu->MoveUp();
                        break;

                    case sf::Keyboard::S:
                        menu->MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (menu->GetPressedItem()){
                            case 0:
                                this->scoreAndGraph->score_int = 0;
                                this->scoreAndGraph->count_HP = 3;
                                menuLevelRun();
                                break;
                            case 1:
                                menuMusicRun() ;
                                break;
                            case 2:
                                menuListScoreRun();
                                break;
                            case 3:
                                this->window->close();
                        }
                }
        }
        if (this->event.type == sf::Event::Closed)
            this->window->close();

//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
//            this->window->close();
//        }
    }
}

void Game::SFMLeventsLevelMenu(){
    while (this->window->pollEvent(this->event)){

        switch (event.type){

            case sf::Event::KeyReleased:
                switch (event.key.code){
                    case sf::Keyboard::W:
                        menuLevels->MoveUp();
                        break;

                    case sf::Keyboard::S:
                        menuLevels->MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (menuLevels->GetPressedItem()){
                            case 0:
                                run();
                                break;
                            case 1:
                                run();
                                break;
                            case 2:
                                run();
                                break;
                            case 3:
                                menuRun();
                        }

                }
        }
//        if (this->event.type == sf::Event::Closed)
//            this->window->close();
    }
}

void Game::SFMLeventsMusicMenu(){
    while (this->window->pollEvent(this->event)){

        switch (event.type){

            case sf::Event::KeyReleased:
                switch (event.key.code){
                    case sf::Keyboard::W:
                        menuMusic->MoveUp();
                        break;

                    case sf::Keyboard::S:
                        menuMusic->MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (menuMusic->GetPressedItem()){
                            case 0:
                                this->menuMusic->music.play();
                                this->menuMusic->music2.stop();
                                this->menuMusic->music3.stop();

                                break;
                            case 1:
                                this->menuMusic->music.stop();
                                this->menuMusic->music3.stop();
                                this->menuMusic->music2.play();
                                break;
                            case 2:
                                this->menuMusic->music3.play();
                                this->menuMusic->music.stop();
                                this->menuMusic->music2.stop();
                                break;
                            case 3:
                                menuRun();
                        }
                }
        }
        if (this->event.type == sf::Event::Closed)
            this->window->close();

//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
//            this->window->close();
//        }
    }
}

void Game::SFMLeventsListScore(){
    while (this->window->pollEvent(this->event)){

        switch (event.type){

            case sf::Event::KeyReleased:
                switch (event.key.code){
                    case sf::Keyboard::W:
                        menuListScore->MoveUp();
                        break;

                    case sf::Keyboard::S:
                        menuListScore->MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (menuListScore->GetPressedItem()){
                            case 0:
                                menuRun();
                        }
                }
        }
        if (this->event.type == sf::Event::Closed)
            this->window->close();

//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
//            this->window->close();
//        }
    }
}



void Game::IPlayer(){
    this->player = new Player();
}

void Game::IWall(){
    this->wall = new Wall();
}

void Game::IEnemy(){
    this->enemy = new Enemy();
}

void Game::IMenu() {
    this->menu = new Menu(this->window->getSize().x, this->window->getSize().y);

}

void Game::IscoreAndGraph(){
    this->scoreAndGraph = new ScoreAndGraph();
}

void Game::IMenuLevels() {
    this->menuLevels = new MenuLevels(this->window->getSize().x, this->window->getSize().y);
}

void Game::IMenuMusic() {
    this->menuMusic = new MenuMusic(this->window->getSize().x, this->window->getSize().y);
}

void Game::IMenuListScore() {
    this->menuListScore = new MenuListScore();
}

void Game::playerMove(){
    // generowanie zakresu dla obiektu
    std::mt19937 generator;
    generator.seed(std::time(0));
    std::uniform_int_distribution<uint32_t> dice(150, 1000);
    std::uniform_int_distribution<uint32_t> dice2(150, 850);
    int scores;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        menuRun();
    }
    if (this->scoreAndGraph->count_HP == 0){

        scores = scoreAndGraph->score_int;
        std::ofstream file;
        file.open ("scoresfile.txt", std::ios::app);
        file << scores << std::endl;
        file.close();


        std::fstream myfiles("scoresfile.txt", std::ios_base::in);
        std::vector<int> array;
        int x;
        while (myfiles >> x)
            array.insert(array.begin() , x);

        for (unsigned i = 0; i < array.size(); i++)
            std::cout << array[i] <<' ';

//        renderListScoreRun();

        this->menuListScore->draw(this->window->getSize().x, this->window->getSize().y, array);

//
//        this->menuListScore->menu_ListScore_draw(this->window);
//        renderListScoreRun();
//        menuListScoreRun();
        menuRun();

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        if (this->player->_Position.y <= 0) {
            this->player->_Position.y += 900;
        }
        else if (this->menuLevels->selectedItemIndex == 0){
            this->player->moving({this->player->Speed.x =0, this->player->Speed.y = -5});
        }
        else if (this->menuLevels->selectedItemIndex == 1){
            this->player->moving({this->player->Speed.x =0, this->player->Speed.y = -8});
        }
        else if (this->menuLevels->selectedItemIndex == 2){
            this->player->moving({this->player->Speed.x =0, this->player->Speed.y = -13});
        }}

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        if (this->player->_Position.y >= 900) {
            this->player->_Position.y -= 900;
        }
        else if (this->menuLevels->selectedItemIndex == 0){
            this->player->moving({this->player->Speed.x =0, this->player->Speed.y = 5});
        }
        else if (this->menuLevels->selectedItemIndex == 1){
            this->player->moving({this->player->Speed.x =0, this->player->Speed.y = 8});
        }
        else if (this->menuLevels->selectedItemIndex == 2){
            this->player->moving({this->player->Speed.x =0, this->player->Speed.y = 13});
        }}

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if (this->player->_Position.x <= 0) {
            this->player->_Position.x += 1100;
        }
        else if (this->menuLevels->selectedItemIndex == 0){
            this->player->moving({this->player->Speed.x =-5, this->player->Speed.y = 0});
        }
        else if (this->menuLevels->selectedItemIndex == 1){
            this->player->moving({this->player->Speed.x =-8, this->player->Speed.y = 0});
        }
        else if (this->menuLevels->selectedItemIndex == 2){
            this->player->moving({this->player->Speed.x =-13, this->player->Speed.y = 0});
        }}

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if (this->player->_Position.x >= 1050) {
            this->player->_Position.x -= 1100;
        }
        else if (this->menuLevels->selectedItemIndex == 0){
            this->player->moving({this->player->Speed.x =5, this->player->Speed.y = 0});
        }
        else if (this->menuLevels->selectedItemIndex == 1){
            this->player->moving({this->player->Speed.x =8, this->player->Speed.y = 0});
        }
        else if (this->menuLevels->selectedItemIndex == 2){
            this->player->moving({this->player->Speed.x =13, this->player->Speed.y = 0});
        }}

    for (unsigned i = 0; i < this->wall->walls.size(); i++ ){
    if (this->enemy->Enemy_Sprite.getGlobalBounds().intersects(this->player->_Sprite.getGlobalBounds()) ) {
        this->enemy->Enemy_Sprite.setPosition(dice(generator),dice2(generator)); // kolizja postac - cel
        this->scoreAndGraph->score_int += 1; // zwiekszanie punktow
        this->menuMusic->obejcthit.play(); // dzwiek przy kolizji
        this->scoreAndGraph->countdown = 8;

    }}


    for (unsigned i = 0; i < this->wall->walls.size(); i++ ){
        if (this->enemy->Enemy_Sprite.getGlobalBounds().intersects(this->wall->walls[i].getGlobalBounds()) ) {
            this->enemy->Enemy_Sprite.setPosition(dice(generator),dice2(generator)); // kolizja sciany - cel
        }}

    for (unsigned i = 0; i < this->wall->walls.size(); i++ ){
        if (this->player->_Sprite.getGlobalBounds().intersects(this->wall->walls[i].getGlobalBounds())) {
            this->menuMusic->hitWall.play();
            this->player->moving({-(this->player->_Position.x) + 350, -(this->player->_Position.y)+ 80});
            this->scoreAndGraph->countdown = 8;
            this->scoreAndGraph->count_HP -= 1;
        }
//        if (this->scoreAndGraph->countdown == 0 ) {
//            this->menuMusic->hitWall.play();
//            this->player->moving({-(this->player->_Position.x) + 80, -(this->player->_Position.y)+ 80});
//            this->scoreAndGraph->countdown = 8;
//            this->scoreAndGraph->count_HP -= 1;
//        }

//score



    }
}

void Game::update(){
    this->SFMLevents();
    this->playerMove();
}

void Game::render(){
    this->window->clear();
    this->window->draw(this->wall->back_Sprite);

    if (this->menuLevels->selectedItemIndex == 0)
        this->wall->walls2(this->window);

    else if (this->menuLevels->selectedItemIndex == 1)
        this->wall->LevelMedium(this->window);

    else if (this->menuLevels->selectedItemIndex == 2)
        this->wall->LevelHard(this->window);

    this->window->draw(this->player->_Sprite);
    this->window->draw(this->enemy->Enemy_Sprite);

    std::string score_text = "Score: " + std::to_string(this->scoreAndGraph->score_int);
    this->scoreAndGraph->score.setString(score_text);
    this->window->draw(this->scoreAndGraph->score);

    std::string stringTime = "Time: ";
    this->scoreAndGraph->time.setString(stringTime);
    this->window->draw(this->scoreAndGraph->time);

    int timer = this->scoreAndGraph->clock.getElapsedTime().asSeconds();
    this->window->draw(this->scoreAndGraph->timerText);

    if (timer > 0) {
        this->scoreAndGraph->countdown--;
        this->scoreAndGraph->timerText.setString(std::to_string(this->scoreAndGraph->countdown));
        this->scoreAndGraph->clock.restart();
    }

    if (this->scoreAndGraph->countdown == 0 ) {
        this->menuMusic->hitWall.play();
        this->player->moving({-(this->player->_Position.x) + 350, -(this->player->_Position.y)+ 80});
        this->scoreAndGraph->countdown = 8;
        this->scoreAndGraph->count_HP -= 1;
    }


    if(this->scoreAndGraph->count_HP == 3) {
        this->window->draw(this->scoreAndGraph->HP_Red_Sprite1);
        this->window->draw(this->scoreAndGraph->HP_Red_Sprite2);
        this->window->draw(this->scoreAndGraph->HP_Red_Sprite3);
    }
    else if (this->scoreAndGraph->count_HP == 2){
        this->window->draw(this->scoreAndGraph->HP_Red_Sprite2);
        this->window->draw(this->scoreAndGraph->HP_Red_Sprite3);
    }
    else if (this->scoreAndGraph->count_HP == 1){
        this->window->draw(this->scoreAndGraph->HP_Black_Sprite);
    }

    this->window->display();
}

void Game::renderMenu() {
    this->window->clear();
    this->window->draw(this->menu->Menu_Sprite);
    this->menu->menu_draw(this->window);
    this->window->display();
}

void Game::renderLevelMenu() {
    this->window->clear();
    this->window->draw(this->menuLevels->Menu_Sprite);
    this->menuLevels->menu_level_draw(this->window);
    this->window->display();
}

void Game::renderMusicMenu() {
    this->window->clear();
    this->window->draw(this->menuMusic->Menu_Sprite);
    this->menuMusic->menu_music_draw(this->window);
    this->window->display();
}

void Game::renderListScoreRun() {
    this->window->clear();

    this->window->draw(this->menuListScore->Menu_Sprite);

    std::string score_text = "Last score: ";
    this->scoreAndGraph->score2.setString(score_text);
    this->window->draw(this->scoreAndGraph->score2);

    this->menuListScore->menu_ListScore_draw(this->window);


    this->window->display();
}

void Game::menuRun(){
    while ( this->window->isOpen())
    {
        this->SFMLeventsMenu();
        this->renderMenu();
    }
}

void Game::menuLevelRun(){
    while ( this->window->isOpen())
    {
        this->SFMLeventsLevelMenu();
        this->renderLevelMenu();
    }
}

void Game::menuMusicRun(){
    while ( this->window->isOpen())
    {
        this->SFMLeventsMusicMenu();
        this->renderMusicMenu();
    }
}

void Game::menuListScoreRun() {
    while ( this->window->isOpen())
    {
        this->SFMLeventsListScore();
        this->renderListScoreRun();
    }
}


void Game::run(){
    while ( this->window->isOpen())
    {

        this->update();
        this->render();

    }
}

Game::Game(){
    this->initWindow();
    this->IPlayer();
    this->IEnemy();
    this->IWall();
    this->IMenu();
    this->IscoreAndGraph();
    this->IMenuLevels();
    this->IMenuMusic();
    this->IMenuListScore();
}

Game::~Game(){
    delete this->window;

}
