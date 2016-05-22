
#include "Menu.h"
#include <iostream>
#include <iomanip>
#include "Game.h"


Menu::Menu()
{
    y = 0;
    choice = 0;
}


void Menu::setMenu()
{
    std::cin >> choice;
}

void Menu::mainMenu()
{
    check = new artificalintelligence;
    std::cout << "\tИГРА В 15!\n";

    std::cout << "\tНажмите 1 для начала новой игры!\n"
        << "\tНажмите 2 чтобы вызвать помощь.\n"
        << "\tНажмите 3 чтобы выйти.\n";
    std::cout << ">";

    setMenu();

    while (!y)
    {
        std::cout << ">";

        if (choice < 1 || choice > 3)
            std::cout << "Неверно введённые данные, попробуйте снова!" << std::endl;
        else
            y = 1;
    }


    switch (choice)
    {
    case 1:
        startGame();
        break;
    case 2:
        std::cout << "\nВыберите номер пятнашки который\n"
            << "хотите сдвинуть. Эта пятнашка\n"
            << "встанет на место 0. Удачи!\n"
            << std::endl;
        system("pause");
        startGame();
    case 3:
        exit(0);
    case 4:
        check->autoAssembly();
        break;
    }
}


void Menu::startGame()
{
    startNewGame = new gameboard();

    do
    {
        startNewGame->cleanBoard();
        startNewGame->fillBoard();
     }while (!startNewGame->CheckForSolution());

    int turns = 0;
    while (!startNewGame->checkBoard())
    {
       startNewGame->boardForView();
       startNewGame->changeBoard();
        turns++;
    }


    std::cout << "Ты сделал "
        << turns << " перемещений!"
        << std::endl;
    system("pause");

}
