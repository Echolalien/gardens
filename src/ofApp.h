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

        //my laptop has a fault where, unless a secondary screen is connected, oF runs at 10x usual speed, meaning i have to control passage of time manually using this float lol
        float debugSpeed = 10;

        //change if sqcount changes!
        bool hasSeed [10][10];
        int playerGridX;
        int playerGridY;
        bool keyIsDown[400];
        float delayCool;
        float rainCycle;
        float rainCycle2 = 4;
        vector<seed> seeds;

        bool touch = false;
        int contact = 10;
        int approval = 10;
        float lonelyTime = 0;

        //firmata code, based on oF firmata example
        ofArduino	ard;
        bool		bSetupArduino;			// flag variable for setting up arduino once

    private:

        void setupArduino(const int & version);
        void digitalPinChanged(const int & pinNum);
        void analogPinChanged(const int & pinNum);
        void updateArduino();
};
