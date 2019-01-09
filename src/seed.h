#ifndef SEED_H
#define SEED_H
#include "ofMain.h"

class seed
{
public:
    seed(int x, int y, ofVec2f grid, float sqSize);
    void plant();
    void child(); // needs values to pass
    void update();
    void draw();

    void propagate();

    ofVec2f pos;
    ofVec2f drawPos;
    int stems;
    float size;
    float age;
    float hydration;
    ofColor colour;
    int petals;
    float shape;
};

#endif // SEED_H
