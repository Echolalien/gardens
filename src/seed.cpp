#include "seed.h"

seed::seed(int x, int y, ofVec2f grid, float sqSize){
    pos.x = x;
    pos.y = y;
    drawPos.x = grid.x + pos.x*sqSize + sqSize*0.5;
    drawPos.y = grid.y + pos.y*sqSize + sqSize*0.5;
    health = 255;
}

void seed::plant(){
    stems = ofRandom(1,5);
    size = ofRandom(2,10);
    colour.r = ofRandom(255);
    colour.g = ofRandom(255);
    colour.b = ofRandom(255);
    petals = ofRandom(4,10);
    shape = ofRandom(5);
}

void seed::child(int a, float b, ofColor c, int d, float e){
    stems = a;
    size = b;
    colour = c;
    petals = d;
    shape = e;

}

void seed::propagate(){

}

void seed::update(){

    //make it grow
    age++;
    health-=0.05;

}

void seed::draw(){
    ofPushStyle();
    ofPushMatrix();
        ofFill();
        ofTranslate(drawPos);
        ofSetColor(colour, health);
        for(int i = 0; i<petals; i++){
            ofRotate(360/petals);
            ofPushMatrix();
                ofTranslate(0,size);
                ofDrawCircle(0,0,size);
            ofPopMatrix();
        }
        ofSetColor(255, 255, 51, health);
        ofDrawCircle(0,0,size);
    ofPopMatrix();
    ofPopStyle();
}
