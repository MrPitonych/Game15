#include <iostream>
#include <iomanip>
#include "gameboard.h"


gameboard::gameboard()
{
    std::cout << "Пожалуйста введите размерность доски:" << std::endl
        << "Размер по вертикали >";
   std::cin >> SZ_X;
   std::cout << "Размер по горизонтали >";
   std::cin >> SZ_Y;

    board = new int * [SZ_X];
    for (int i = 0; i < SZ_X; i++)
        board[i] = new int[SZ_Y];

    printBoard = new view(SZ_X, SZ_Y);
    step_puzzle = new Game(SZ_X, SZ_Y);
}

////////////////////////////////////////////////////////////////

void gameboard::cleanBoard()
{
    for (int i = 0; i < SZ_X; i++)
        for (int j = 0; j < SZ_Y; j++)
            board[i][j] = 0;
}

////////////////////////////////////////////////////////////////

void gameboard::fillBoard()
{
    bool already[SZ_X*SZ_Y-1] = { 0 };
    int count = 1;
    for (int i = 0; i < SZ_X; i++)
        for (int j = 0; j < SZ_Y; j++, count++)
        {
            if (i == SZ_X - 1 && j == SZ_Y - 1)
                break;
            srand(time(0));
            while (true)
            {
                int randpuzzle = SZ_X*SZ_Y-1;
                int randNum = rand() % randpuzzle;
                if (!already[randNum])
                {
                    already[randNum] = 1;
                    board[i][j] = randNum + 1;
                    break;
                }
            }
        }
}

////////////////////////////////////////////////////////////////


bool gameboard::checkBoard()
{
    int count = 1;
    for (int i = 0; i < SZ_X; i++)
        for (int j = 0; j < SZ_Y; j++, count++)
        {
            if (i == SZ_X - 1 && j == SZ_Y - 1 && board[i][j] == 0) break;
            if (board[i][j] != count)
                return 0;
        }
    return 1;
}

bool gameboard::CheckForSolution()
{
    int solution[SZ_X*SZ_Y] = { 0 };
    int index = 0;
    for (int i = 0; i < SZ_X; i++)
        for (int j = 0; j < SZ_Y; j++, index++)
            solution[index] = board[i][j];
    int inv = 0;
    for (int i = 0; i < SZ_X*SZ_Y; i++)
        if (solution[i])
            for (int j = 0; j < i; j++)
                if (solution[j] > solution[i])
                    ++inv;
    for (int i = 0; i < SZ_X*SZ_Y; i++)
        if (solution[i] == 0)
            inv += 1 + i / 4;
    return (inv & 1) ? 0 : 1;
}
    ////////////////////////////////////////////////////////////////

void gameboard::boardForView()
{
    printBoard->showBoard(board);
}

////////////////////////////////////////////////////////////////

void gameboard::changeBoard()
{
    step_puzzle->stepPuzzle(board);
}

////////////////////////////////////////////////////////////////


