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
//    *plant growth function - maybe later
//    *water button - done, no animation yet
//    *dig up button - just let them die
//    *animations - lol
//    *lil house - lol
//    *move to house - lol
//    *social metrics
//    *propagating seeds function - yeah!

//--------------------------------------------------------------
void ofApp::update(){

    walkDelay=600-5*approval*contact;

    parseInput();

    seedUpdate();

    //punish loneliness
    if(lonelyTime>1000){
        contact--;
        lonelyTime = 0;
    }

    rain(playerGridX, playerGridY);

    //grid movement
    playerPos.x = grid.x + playerGridX*sqSize + sqSize*0.5;
    playerPos.y = grid.y + playerGridY*sqSize + sqSize*0.2;
}

//--------------------------------------------------------------
void ofApp::draw(){

    drawPlaySpace();

    //seeds
    for(int i = 0; i<seeds.size(); i++){
        seeds[i].draw();
    }

    drawPlayer();

    joystickDebug();

}

//--------------------------------------------------------------
void ofApp::rain(int x, int y){
    for(int i = 0; i<seeds.size(); i++){
        if(seeds[i].pos.x == x && seeds[i].pos.y == y){
            seeds[i].health = 255;
        }
    }
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
    ofPushStyle();
        ofFill();
        ofDrawBitmapString("Believer count:", grid.x, grid.y - 40);
        ofDrawRectangle(grid.x + 130, grid.y - 48, contact*37, 10);
        ofDrawBitmapString("Worship quality:", grid.x, grid.y - 20);
        ofDrawRectangle(grid.x + 130, grid.y - 28, approval*37, 10);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::drawPlayer(){
    //rain
    ofPushStyle();
    ofPushMatrix();
        ofTranslate(0,-5);
        ofSetColor(0,255,255, ofMap(approval*contact, 0, 100, 90, 255));
        for(int i = 0; i<3; i++){
            ofDrawLine(playerPos.x-8+i*7, playerPos.y+10+rainCycle, playerPos.x-8+i*7, playerPos.y+15+rainCycle);
        }
        for(int i = 0; i<4; i++){
            ofDrawLine(playerPos.x-11.5+i*7, playerPos.y+10+rainCycle2, playerPos.x-11.5+i*7, playerPos.y+15+rainCycle2);

        }
        if(rainCycle2<8) rainCycle2+=0.01;
        else rainCycle2=0;
        if(rainCycle<8) rainCycle+=0.01;
        else rainCycle=0;
    ofPopStyle();

    //clouds
    ofPushStyle();
        ofFill();
        ofSetColor(211,211,211, ofMap(approval*contact, 0, 100, 90, 255));
        ofDrawCircle(playerPos, 7);
        ofDrawCircle(playerPos.x-7, playerPos.y+5, 5);
        ofDrawCircle(playerPos.x+7, playerPos.y+5, 5);
        for(int i = 0; i<6; i++){
            ofDrawCircle(playerPos.x-14+5*i, playerPos.y+8, 3);
        }
    ofPopStyle();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::seedUpdate(){
    //seeds
    for(int i = 0; i<seeds.size(); i++){
        int xPos = seeds[i].pos.x;
        int yPos = seeds[i].pos.y;
        if(seeds[i].age>800){
            for(int k = xPos-1; k<=xPos+1; k++){
                for(int j = yPos-1; j<=yPos+1; j++){
                    if(k>=0 && j>=0 && k<sqCount && j<sqCount){
                        if(hasSeed[k][j] == false && ofRandom(100000)<3){
                            seeds.push_back(seed(k, j, grid, sqSize));
                            seeds[seeds.size()-1].child(seeds[i].stems, seeds[i].size, seeds[i].colour, seeds[i].petals, seeds[i].shape);
                            hasSeed[k][j] = true;
                        }
                    }
                }
            }
        }
        if(seeds[i].health<=0){
            int x = seeds[i].pos.x;
            int y = seeds[i].pos.y;
            hasSeed[x][y]=false;
            seeds.erase(seeds.begin()+i);
        }
        seeds[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::parseInput(){
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
    if(keyIsDown[119]==1){
        if(contact<10){
            contact=10;
        }
    }
    else if(contact>0) lonelyTime++;
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
    ofDrawBitmapString(walkDelay, 50, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    cout << key << endl;
    keyIsDown[key] = true;
    if(key >57000){
        keyIsDown[key-57000] = true;
    }
    if(key==97){
        approval--;
    }
    if(key==100){
        approval++;
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
