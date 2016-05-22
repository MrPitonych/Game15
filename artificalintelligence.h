#pragma once
#ifndef ARTIFICALINTELLIGENCE_H
#define ARTIFICALINTELLIGENCE_H
#include "view.h"
#include "gameboard.h"

class gameboard;
class Game;

class artificalintelligence
{
public:
    artificalintelligence();
    ////////////
    void RanddomMass(void);
    void BoardToMass(int**);
    void autoAssembly();
    void Trasser_Init(void);
    bool MakeOneLine(void);
    bool MakeTwoLine(void);
    bool MakeEndLine(void);
    void Set_ElementPosition(int, int);
    void ZeroPositions(int);
    void Trasser_patch(int, int);
    int FindElements(int);
    void SwapElements(int);
    int Steps(int, int);
    int Trass_Parent(int);
    int Trasser_Area(int);
    bool Check_Block_Position(int);
    ///////////
    void Map_15ToBoard();
    void showBoardAI();


private:
    const int SZ = 10;
    int SZ_X;
    int SZ_Y;
    int** boardAI;
    view* printBoardAI;
    //int close_list[16];
    //int Min_F = 100;

};

#endif
