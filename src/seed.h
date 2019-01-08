#ifndef SEED_H
#define SEED_H
#include "ofMain.h"

class seed
{
public:
    seed(int x, int y, ofVec2f grid, float sqSize);
    void update();
    void draw();

    ofVec2f pos;
    ofVec2f drawPos;

};

#endif // SEED_H
