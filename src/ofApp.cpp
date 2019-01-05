#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetColor(255);
    sqSize = 50;
    sqCount = 10;
    grid.x=ofGetWidth()/2-sqSize*sqCount/2;
    grid.y=ofGetHeight()/2-sqSize*sqCount/2;
    playerGrid.x = 3;
    playerGrid.y = 5;
}

//test change
//to do:
//    *player movement
//    *seed options
//    *water button
//    *animations
//    *lil house
//    *move to house
//    *social metrics


//--------------------------------------------------------------
void ofApp::update(){

    //grid movement
    playerPos.x = grid.x + playerGrid.x*sqSize/2 + sqSize/4;
    playerPos.y = grid.y + playerGrid.y*sqSize/2;
}

//--------------------------------------------------------------
void ofApp::draw(){

    drawPlaySpace();

    //player
    ofPushStyle();
        ofFill();
        ofDrawCircle(playerPos.x, playerPos.y, 10);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::drawPlaySpace(){
    //playspace
    ofPushStyle();
        ofSetColor(0);
        ofFill();
        ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofPopStyle();

    ofSetColor(255);
    ofNoFill();
    ofSetLineWidth(3);
    ofDrawRectangle(grid.x, grid.y, sqSize*sqCount, sqSize*sqCount);
    ofSetLineWidth(1);
    for(int i = 0; i<sqCount; i++){
        for(int j = 0; j<sqCount; j++){
            ofDrawRectangle(grid.x+i*sqSize, grid.y+j*sqSize, sqSize, sqSize);
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
