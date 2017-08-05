//
// Created by ThinkPad on 2017/8/4.
//

#ifndef PBRAIN_YUKI_CEIL_H
#define PBRAIN_YUKI_CEIL_H

#include "constant.h"
#include <vector>
#include "Pattern.h"
#include "Answer.h"

using namespace std;



class Ceil
{
private:
    Pattern ptn[2][dirnum];
    int value[2][dirnum];
public:
    Ceil();
    void updateType(int direc, int color, int dist, bool set);
    int getValue(int color);
    bool checkFive(int direc, int color);
    void checkanswer(vector<answer> &ret,int direc, int color);
};

#endif //PBRAIN_YUKI_CEIL_H
