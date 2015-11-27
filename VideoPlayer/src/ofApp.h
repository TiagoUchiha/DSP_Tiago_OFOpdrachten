#pragma once

#include "ofMain.h"
#include "ofEvents.h"

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

		ofImage image[5];
		ofImage uiTop, uiDown, uiInfo;
		ofSoundPlayer sound[5];
		bool soundPaused[5];
		int totalFrames;
		int currentFrame;
		bool everythingPause, playCheck;
		int lightValue;
		int width,height, totalPlay;

        ofArduino	arduino;
        bool	isArduinoInitialized;
        void setupArduino(const int & version);
        void digitalPinChanged(const int & pinNum);
        void analogPinChanged(const int & pinNum);

};
