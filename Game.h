#pragma once
#ifndef GAME_H
#define GAME_H
#include "gameboard.h"

class gameboard;
class artificalintelligence;

class Game
{

public:
    Game(int, int);
    void stepPuzzle(int**);
    void startGame();
    bool checkBoard();
    void setTurn();

private:
    int turn = 0;
    int SZ_X;
    int SZ_Y;

};

#endif
