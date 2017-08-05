//
// Created by ThinkPad on 2017/8/5.
//

#ifndef PBRAIN_YUKI_ANSWER_H
#define PBRAIN_YUKI_ANSWER_H

class answer
{
public:
    int direction = -1;
    int dist = -1;
    answer(int a, int b) {
        direction = a;
        dist = b;
    }
};

#endif //PBRAIN_YUKI_ANSWER_H
