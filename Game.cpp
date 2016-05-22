#include <iostream>
#include <iomanip>
#include "Game.h"
#include "Menu.h"
#include "view.h"

Game::Game(int myX, int myY)
{
    SZ_X = myX;
    SZ_Y = myY;

}

/////////////////////////////////////////////////////////////////////////

void Game::setTurn()
{
    std::cin >> turn;
}

////////////////////////////////////////////////

void Game::stepPuzzle(int** board)
{

    bool y = 0;
    while (!y)
    {
        do
        {
            std::cout << ">";
            setTurn();

        } while (turn < 0 || turn > SZ_X*SZ_Y-1);

        if (turn == 0)//для выхожа нажмите 0
        {
            //check->autoAssembly();
            //check->boardAIForView();

            return;
        }
        int getx = 0;
        int gety = 0;
        for (int i = 0; i < SZ_X; i++)
            for (int j = 0; j < SZ_Y; j++)
                if (board[i][j] == turn)
                {
                    getx = i;
                    gety = j;
                }
        int dx[] = { 0, 0, 1, -1 };
        int dy[] = { 1, -1, 0, 0 };
        for (int i = 0; i < SZ_X; i++)
            for (int j = 0; j < SZ_X; j++)
        {
            int newx = getx + dx[i];
            int newy = gety + dy[j];
            if (newx < 0 || newx > SZ_X - 1 ||
                newy < 0 || newy > SZ_Y - 1)
                continue;
            if (board[newx][newy] == 0)
            {
                board[newx][newy] = turn;
                board[getx][gety] = 0;
                y = 1;
                break;
            }
        }
        if (!y)
            std::cout << "Ошибка ввода, попробуйте снова!" << std::endl;
        if (turn > (SZ_X*SZ_Y-1))
             std::cout << "Ошибка ввода, тут нет такого пазла!" << std::endl;
    }
}


