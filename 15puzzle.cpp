#include <clocale>
#include "Menu.h"


int main()
{
    setlocale(LC_CTYPE, "rus");
    Menu* game = new Menu;
    game->mainMenu();
    return 0;
}

