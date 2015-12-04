#pragma once

#include "ofMain.h"

#define VOICES 6

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofSoundPlayer voicePlayer[VOICES];
		bool voicePaused[VOICES];
		int currentSpeed1;
        int currentSpeed2;
        int currentSpeed3;
        int currentSpeed4;
        int currentSpeed5;
        int currentSpeed6;
        string string1,string2,string3;
        int checkKey;
		ofTrueTypeFont speedBoard;

};
