#pragma once
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "view.h"
#include "Game.h"
#include "artificalintelligence.h"
#include "Menu.h"

class Game;

class gameboard
{
public:
    gameboard();
    void cleanBoard();
    void fillBoard();
    bool checkBoard();
    void boardForView();
    void changeBoard();
    bool CheckForSolution();
   // void boardForTrace();


private:
   int SZ_X;
   int SZ_Y;
   int** board;
   view* printBoard;
   Game* step_puzzle;
   artificalintelligence* winningCheck;
};

#endif
