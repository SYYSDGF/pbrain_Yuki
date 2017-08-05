//
// Created by ThinkPad on 2017/8/4.
//
#include <algorithm>
#include <set>
#include "Board.h"

void Board::updateType(point change, bool set) {
    for (int dir = 0; dir < dirnum; dir++) {
        for (int dist = 0; dist <= 4; dist++) {
            int tempx = change.x + negdx[dir] * dist;
            int tempy = change.y + negdy[dir] * dist;
            if (!inMap(tempx, tempy))
                continue;
            ceil[tempx][tempy].updateType((dir+4)%8, change.color, dist, set);
        }
    }
}

void Board::getPoint(vector<point> &ret, int color) {
    Bitgrid reachblank = getreachblank();
    ret = reachblank.getOne();
    for (int i = 0; i < ret.size(); i++) {
        ret[i].color = color;
        ret[i].value = ceil[ret[i].x][ret[i].y].getValue(color);
    }
    sort(ret.begin(), ret.end(), comp_point);
}

void Board::procstep(point p) {
    updateType(p, true);
    table[p.color].change(p.x, p.y);
}



Bitgrid Board::getreachblank() {
    Bitgrid ret;
    ret.init();
    Bitgrid all = table[black] | table[white];
    vector<point> curr = all.getOne();
    for (int i = 0; i < curr.size(); i++) {
        ret = ret | near[curr[i].x][curr[i].y];
    }
    ret = ret & ~all;
    return ret;
}

void Board::cancelstep(point p) {
    updateType(p, false);
    table[p.color].change(p.x, p.y);
}

int Board::eval(int color) {
    Bitgrid reachblank = getreachblank();
    Bitgrid tempAll = reachblank | (table[black] | table[white]);
    vector<point> point_blank = tempAll.getOne();
    int retvalue = 0;
    for (int i = 0; i < point_blank.size(); i++) {
        retvalue += ceil[point_blank[i].x][point_blank[i].y].getValue(color);
    }
    return retvalue;
}

bool Board::checkWin(point p) {
    for (int dir = 0; dir < dirnum; dir++) {
        for (int dist = 0; dist <= 4; dist++) {
            int tempx = p.x + negdx[dir] * dist;
            int tempy = p.y + negdy[dir] * dist;
            if (!inMap(tempx, tempy))
                continue;
            if (ceil[tempx][tempy].checkFive((dir+4)%8, p.color))
                return true;
        }
    }
    return false;
}

void Board::checkanswer(vector<point> &ret, point p) {
    for (int dir = 0; dir < dirnum; dir++) {
        for (int dist = 0; dist <= 4; dist++) {
            vector<answer> temp;
            int tempx = p.x + negdx[dir] * dist;
            int tempy = p.y + negdy[dir] * dist;
            if (!inMap(tempx, tempy))
                continue;
            ceil[tempx][tempy].checkanswer(temp, (dir+4)%8, p.color);
            for (int i = 0; i < temp.size(); i++) {
                point curr;
                curr.x = p.x + negdx[dir] * (dist - temp[i].dist);
                curr.y = p.y + negdy[dir] * (dist - temp[i].dist);
                ret.push_back(curr);
            }
        }
    }
}

void Board::debug() {
    cout << "table" << endl;
    for (int i = 0; i < gridsize; i++) {
        for (int j = 0; j < gridsize; j++) {
            if (table[black].check(i,j))
                cout << "B ";
            else if (table[white].check(i,j))
                cout << "W ";
            else
                cout << "* ";
        }
        cout << endl;
    }
    cout << "----------------" << endl;
}

Board::Board() {
    table[0].init();
    table[1].init();
}
