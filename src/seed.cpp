#include "seed.h"

seed::seed(int x, int y, ofVec2f grid, float sqSize){
    pos.x = x;
    pos.y = y;
    drawPos = grid + pos*sqSize + sqSize*0.5;
}

void seed::draw(){
    ofDrawCircle(drawPos, 5);
}
