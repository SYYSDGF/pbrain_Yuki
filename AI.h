//
// Created by ThinkPad on 2017/8/5.
//

#ifndef PBRAIN_YUKI_AI_H
#define PBRAIN_YUKI_AI_H

#include "Board.h"
#include <stack>
#include "constant.h"

using namespace std;

class Ai
{
private:
    Board brd;
    int botcolor = white;
    int turnTD = 0;
    point historyPoints[gridsize * gridsize];
public:
    int abprune(int alpha, int beta, int depth, int color);
    void process(int x, int y, int color);
    int idfs(point &ret);
    void open(point &ret);
    void print(point ret);
    void debug();
};


#endif //PBRAIN_YUKI_AI_H
