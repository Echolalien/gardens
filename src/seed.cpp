#include "seed.h"

seed::seed(int x, int y, ofVec2f grid, float sqSize){
    pos.x = x;
    pos.y = y;
    drawPos.x = grid.x + pos.x*sqSize + sqSize*0.5;
    drawPos.y = grid.y + pos.y*sqSize + sqSize*0.8;
}

void seed::plant(){
    stems = ofRandom(5);
    size = ofRandom(10);
    colour.r = ofRandom(255);
    colour.g = ofRandom(255);
    colour.b = ofRandom(255);
    petals = ofRandom(20);
    shape = ofRandom(5);
}

void seed::update(){

    //make it grow
    age++;


}

void seed::draw(){

    if(age>250){
        ofDrawCurve(drawPos.x, drawPos.y-10, drawPos.x, drawPos.y, drawPos.x-age+250, drawPos.y-age+250, drawPos.x, drawPos.y);
    }

    ofPushStyle();
        ofSetColor(255,255,255,255-age*0.1);
        ofDrawCircle(drawPos, 5);
    ofPopStyle();
}
