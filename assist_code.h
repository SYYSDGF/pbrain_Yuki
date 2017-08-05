//
// Created by ThinkPad on 2017/8/4.
//

#ifndef PBRAIN_YUKI_ASSIST_CODE_H
#define PBRAIN_YUKI_ASSIST_CODE_H
/*
for (int x = 0; x < gridsize; x++) {
        for (int y = 0; y < gridsize; y++) {
            Bitgrid temp;
            temp.init();
            for (int delta = 0; delta < 24; delta++) {
                int tempx = x + negdx[delta];
                int tempy = y + negdy[delta];
                if (!inMap(tempx, tempy))
                    continue;
                temp.change(tempx, tempy);
            }
            farf[x][y] = temp;
        }
    }
    for (int x = 0; x < gridsize; x++) {
        cout << "{" << endl;
        for (int y = 0; y < gridsize; y++) {
            cout << "{" << farf[x][y].state[0] << ","
                  << farf[x][y].state[1] << ","
                  << farf[x][y].state[2] << ","
                  << farf[x][y].state[3] << "}";
            if (y != gridsize - 1)
                cout << ",";
            cout << endl;
        }
        cout << "}," << endl;
    }
*/
#endif //PBRAIN_YUKI_ASSIST_CODE_H
