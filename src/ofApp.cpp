#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetColor(255);
    sqSize = 50;
    sqCount = 10;
    grid.x=ofGetWidth()/2-sqSize*sqCount/2;
    grid.y=ofGetHeight()/2-sqSize*sqCount/2;
    playerGridX = 0;
    playerGridY = 0;
    walkDelay = 100;
}

//to do:
//    *player movement TICK
//    *seed options -decided seeds should be random (maybe with SOME choice? maybe same button for plant or water...)
//    *plant growth function
//    *water button
//    *dig up button
//    *animations
//    *lil house
//    *move to house
//    *social metrics
//    *propagating seeds function

//--------------------------------------------------------------
void ofApp::update(){

    parseInput();

    //seeds
    for(int i = 0; i<seeds.size(); i++){
        seeds[i].update();
    }

    //grid movement
    playerPos.x = grid.x + playerGridX*sqSize + sqSize*0.3;
    playerPos.y = grid.y + playerGridY*sqSize + sqSize*0.7;
}

//--------------------------------------------------------------
void ofApp::draw(){

    drawPlaySpace();

    //player
    ofPushStyle();
        ofFill();
        ofDrawCircle(playerPos.x, playerPos.y, 10);
    ofPopStyle();

    //seeds
    for(int i = 0; i<seeds.size(); i++){
        seeds[i].draw();
    }

    joystickDebug();

}

//--------------------------------------------------------------
void ofApp::plantSeed(int x, int y){
    if(hasSeed[x][y]==false){
        seeds.push_back(seed(x, y, grid, sqSize));
        seeds[seeds.size()-1].plant();
        hasSeed[x][y]=true;
    }
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

        if(keyIsDown[356]==1 && playerGridX>0){
            playerGridX-=1;
        }
        else if(keyIsDown[358]==1 && playerGridX<sqCount-1){
            playerGridX+=1;
        }

        if(keyIsDown[357]==1 && playerGridY>0){
            playerGridY-=1;
        }
        else if(keyIsDown[359]==1 && playerGridY<sqCount-1){
            playerGridY+=1;
        }

        delayCool=walkDelay;
    }
    else{
        delayCool--;
    }

    if(keyIsDown[32]==1){
        plantSeed(playerGridX, playerGridY);
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
