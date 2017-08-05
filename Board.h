//
// Created by ThinkPad on 2017/8/4.
//

#ifndef PBRAIN_YUKI_BOARD_H
#define PBRAIN_YUKI_BOARD_H

#include "constant.h"
#include "Ceil.h"
#include "BitGrid.h"
#include <iostream>

class Board
{
private:
    Ceil ceil[gridsize][gridsize];
    Bitgrid table[2];
public:
    Board();
    void updateType(point change, bool set);
    void getPoint(vector<point> &ret, int color);
    Bitgrid getreachblank();
    void procstep(point p);
    void cancelstep(point p);
    int eval(int color);
    bool checkWin(point p);
    void checkanswer(vector<point> &ret, point p);
    void debug();
};



#endif //PBRAIN_YUKI_BOARD_H
