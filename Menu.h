#ifndef MENU_H
#define MENU_H
#include "Game.h"
#include "artificalintelligence.h"

class Menu
{

public:
    Menu();
    void setMenu();
    void mainMenu();
    void startGame();

private:
    bool y;
    int choice;
    gameboard* startNewGame;
    artificalintelligence* check;
};


#endif
