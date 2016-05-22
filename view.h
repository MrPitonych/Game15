#pragma once
#ifndef VIEW_H
#define VIEW_H

class view
{
public:
    view(const int, const int);
    void showBoard(int**);
    void showBoardAI(int**);

private:
    int SZ_X;
    int SZ_Y;
};

#endif
