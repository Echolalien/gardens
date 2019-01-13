#pragma once

#include "ofMain.h"
#include "seed.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        void drawPlaySpace();
        void parseInput();
        void joystickDebug();
        void plantSeed(int x, int y);
        void seedUpdate();
        void rain(int x, int y);
        void drawPlayer();

        float sqSize;
        int sqCount;
        ofVec2f playerPos;
        ofVec2f grid;
        float walkDelay;
        ofVec2f joystick;

        //change if sqcount changes!
        bool hasSeed [10][10];
        int playerGridX;
        int playerGridY;
        bool keyIsDown[400];
        float delayCool;
        float rainCycle;
        float rainCycle2 = 4;
        vector<seed> seeds;

        float contact = 10;
        float approval = 10;
        float lonelyTime = 0;
};
