//
// Created by ThinkPad on 2017/8/5.
//

#include <iostream>
#include "AI.h"


int Ai::abprune(int alpha, int beta, int depth, int color) {
    if (depth == 0)
        return brd.eval(color);
    point lastPoint = historyPoints[turnTD - 1];
    if (brd.checkWin(lastPoint))
        return LOSE;
    vector<point> myvictory;
    brd.checkanswer(myvictory, historyPoints[turnTD - 2]);
    if (!myvictory.empty())
        return WIN;
    vector<point> enemyattax;
    brd.checkanswer(enemyattax, historyPoints[turnTD - 1]);
    if (!enemyattax.empty()) {
        for (int i = 0; i < enemyattax.size(); i++) {
            brd.procstep(enemyattax[i]);
            historyPoints[turnTD++] = enemyattax[i];
            int value = -abprune(-beta, -alpha, depth - 1, color ^ 1);
            turnTD--;
            brd.cancelstep(enemyattax[i]);
            if (value >= beta)
                return beta;
            if (value > alpha)
                alpha = value;
        }
    } else {
        vector<point> validpoints;
        brd.getPoint(validpoints, color);
        if (validpoints.empty())
            return DRAW;
        else {
            for (int i = 0; i < validpoints.size(); i++) {
                brd.procstep(validpoints[i]);
                historyPoints[turnTD++] = validpoints[i];
                int value = -abprune(-beta, -alpha, depth - 1, color ^ 1);
                turnTD--;
                brd.cancelstep(validpoints[i]);
                if (value >= beta)
                    return beta;
                if (value > alpha)
                    alpha = value;
            }
        }
    }
    return alpha;
}

int Ai::idfs(point &ret) {
    vector<point> myvictory;
    brd.checkanswer(myvictory, historyPoints[turnTD - 2]);
    if (!myvictory.empty()) {
        ret = myvictory[0];
        return WIN;
    }
    vector<point> enemyattax;
    brd.checkanswer(enemyattax, historyPoints[turnTD - 1]);
    vector<point> sons;
    brd.getPoint(sons, botcolor);
    for (int depth = 0; depth < 10; depth++) {
        int alpha = LOSE;
        if (!enemyattax.empty()) {
            for (int i = 0; i < enemyattax.size(); i++) {
                brd.procstep(enemyattax[i]);
                historyPoints[turnTD++] = enemyattax[i];
                int value = -abprune(LOSE, WIN, depth - 1, botcolor ^ 1);
                turnTD--;
                brd.cancelstep(enemyattax[i]);
                if (value > alpha) {
                    alpha = value;
                    ret = enemyattax[i];
                }
            }
        } else {
            if (sons.empty())
                return DRAW;
            else {
                for (int i = 0; i < sons.size(); i++) {
                    brd.procstep(sons[i]);
                    historyPoints[turnTD++] = sons[i];
                    int value = -abprune(LOSE, WIN, depth - 1, botcolor ^ 1);
                    turnTD--;
                    brd.cancelstep(sons[i]);
                    if (value > alpha) {
                        alpha = value;
                        ret = sons[i];
                    }
                }
            }
        }
    }
}

void Ai::open(point &ret) {
    if (turnTD == 0)
        ret = point(7,7,botcolor);
    else if (turnTD == 1)
        ret = point(6,7, botcolor);
    else
        idfs(ret);
}

void Ai::print(point ret) {
    cout << ret.x << "," << ret.y << endl;
}

void Ai::debug() {
    brd.debug();
}

void Ai::process(int x, int y, int color) {
    point p(x, y, color);
    brd.procstep(p);
}
