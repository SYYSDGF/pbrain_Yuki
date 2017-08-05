#include <iostream>
#include "BitGrid.h"
#include "AI.h"

using namespace std;


int main() {
    Board test;
    test.procstep(point(7,7,black));
    test.procstep(point(1,1,white));
    test.procstep(point(8,8,black));
    test.procstep(point(3,3,white));
    test.procstep(point(6,6,black));
    /*
    vector<point> temp;
    test.getPoint(temp, black);
    test.debug();
    cout << temp.size() << endl;
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i].x << "," << temp[i].y << "," << temp[i].value << endl;
    }*/
    vector<point> temp;
    test.checkanswer(temp, point(6,6,black));
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i].x << "," << temp[i].y << "," << temp[i].value << endl;
    }
}