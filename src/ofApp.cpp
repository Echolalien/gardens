#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetColor(255);
    sqSize = 50;
    sqCount = 10;
    grid.x=ofGetWidth()/2-sqSize*sqCount/2;
    grid.y=ofGetHeight()/2-sqSize*sqCount/2;
    playerGrid.x = 0;
    playerGrid.y = 0;
    walkDelay = 100;
}

//to do:
//    *player movement TICK
//    *seed options
//    *water button
//    *animations
//    *lil house
//    *move to house
//    *social metrics


//--------------------------------------------------------------
void ofApp::update(){

    parseInput();

    //grid movement
    playerPos.x = grid.x + playerGrid.x*sqSize + sqSize*0.3;
    playerPos.y = grid.y + playerGrid.y*sqSize + sqSize*0.7;
}

//--------------------------------------------------------------
void ofApp::draw(){

    drawPlaySpace();

    //player
    ofPushStyle();
        ofFill();
        ofDrawCircle(playerPos.x, playerPos.y, 10);
    ofPopStyle();

    joystickDebug();

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
void ofApp::parseInput(){
    //input parsing
    if(delayCool<=0){

        if(keyIsDown[356]==1 && playerGrid.x>0){
            playerGrid.x-=1;
        }
        else if(keyIsDown[358]==1 && playerGrid.x<sqCount-1){
            playerGrid.x+=1;
        }

        if(keyIsDown[357]==1 && playerGrid.y>0){
            playerGrid.y-=1;
        }
        else if(keyIsDown[359]==1 && playerGrid.y<sqCount-1){
            playerGrid.y+=1;
        }

        delayCool=walkDelay;
    }
    else{
        delayCool--;
    }
}

//--------------------------------------------------------------
void ofApp::joystickDebug(){

    //joystick feedback
    if(keyIsDown[356] == 1){
        ofDrawBitmapString("<", 20,10);
    }
    if(keyIsDown[358] == 1){
        ofDrawBitmapString(">", 10,10);
    }
    if(keyIsDown[357] == 1){
        ofDrawBitmapString("^", 30,10);
    }
    if(keyIsDown[359] == 1){
        ofDrawBitmapString("V", 40, 10);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    cout << key << endl;
    keyIsDown[key] = true;
    if(key >57000){
        keyIsDown[key-57000] = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    keyIsDown[key] = false;
    if(key == 97){
        keyIsDown[356]=0;
    }
    if(key >57000){
        keyIsDown[key-57000] = false;
    }
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
