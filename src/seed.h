#ifndef SEED_H
#define SEED_H
#include "ofMain.h"

class seed
{
public:
    seed(int x, int y, ofVec2f grid, float sqSize);
    void plant();
    void child(int a, float b, ofColor c, int d, float e); //acquire variables frm parents
    void update();
    void draw();
    void shoots(float x, float y);

    void propagate(); //pass variables to children

    ofVec2f pos;
    ofVec2f drawPos;
    int stems;
    float size;
    float age;
    float hydration;
    float health;
    ofColor colour;
    int petals;
    float shape;
};

#endif // SEED_H
