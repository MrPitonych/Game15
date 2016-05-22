
#include <iostream>
#include <iomanip>
#include "view.h"

view::view(int viewX, int viewY)
{
   SZ_X = viewX;
   SZ_Y = viewY;
}

void view::showBoard(int** board)
{
   system("clear") ;
   std::cout << "ИГРА в 15\n";

   for (int i = 0; i < SZ_X; i++)
   {
           std::cout << "|";
       for (int j = 0; j < SZ_Y; j++)
       {
           std::cout << std::left
               << std::setw(3)
               << board[i][j]
               << "|";
       }
       std::cout << std::endl;
   }
}

////////////////////////////////////////////////////

void view::showBoardAI(int** boardAI)
{
   system("clear") ;
   std::cout << "ИГРА в 15\n";

   for (int i = 0; i < SZ_X; i++)
   {
       std::cout << "_____________" << std::endl;
       std::cout << "|";
       for (int j = 0; j < SZ_Y; j++)
       {
           std::cout << std::left
               << std::setw(2)
               << boardAI[i][j]
               << "|";
       }
       std::cout << std::endl;
   }
   std::cout << "_____________" << std::endl;
}
