#ifndef SEED_H
#define SEED_H
#include "ofMain.h"


class seed
{
public:
    seed(float x, float y);
    void update();
    void draw();

    ofVec2f pos;

};

#endif // SEED_H
