//
// Created by ThinkPad on 2017/8/5.
//

#include "Ceil.h"
#include "BitGrid.h"
#include "Answer.h"

void Ceil::updateType(int direc, int color, int dist, bool set) {
    ptn[color][direc].type ^= ((unsigned char) 1 << dist);
    if (set) {
        value[color ^ 1][direc] = 0;//破坏对方棋型
        if (ptn[color ^ 1][direc].type == (unsigned char) 0)
            value[color][direc] = ptnvalue[ptn[color][direc].type];//对方在这一路无子，形成我方棋型
    } else {
        if (ptn[color ^ 1][direc].type == (unsigned char) 0) {
            value[color ^ 1][direc] = 0;//对方失去棋型
            value[color][direc] = ptnvalue[ptn[color][direc].type];//对方在这一路无子，形成我方棋型
        } else if (ptn[color][direc].type == (unsigned char) 0) {//我方在这一路无子
            value[color][direc] = 0;//失去我方棋型
            value[color ^ 1][direc] = ptnvalue[ptn[color ^ 1][direc].type];//形成对方棋型
        } else {//双方均有子
            value[color][direc] = value[color ^ 1][direc] = 0;
        }
    }
}

int Ceil::getValue(int color) {
    int retvalue = 0;
    for (int dir = 0; dir < dirnum; dir++) {
        retvalue += (value[color][dir] - value[color ^ 1][dir]);
    }
    return retvalue;
}

bool Ceil::checkFive(int direc, int color) {
    return ptn[color][direc].type == (unsigned char) 31;
}

void Ceil::checkanswer(vector<answer> &ret, int direc, int color) {
    switch (ptn[color][direc].type)
    {
        case 15:
            ret.emplace_back(direc, 4);
            break;
        case 23:
            ret.emplace_back(direc, 3);
            break;
        case 27:
            ret.emplace_back(direc, 2);
            break;
        case 29:
            ret.emplace_back(direc, 1);
            break;
        case 30:
            ret.emplace_back(direc, 0);
            break;
        case 14:
            ret.emplace_back(direc, 0);
            ret.emplace_back(direc, 4);
            break;
        default:
            break;
    }
}

Ceil::Ceil() {
    for (int color = 0; color < 2; color++) {
        for (int direc = 0; direc < 4; direc++) {
            value[color][direc] = 0;
        }
    }
}

