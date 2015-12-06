#pragma once

#include "ofMain.h"
#include "ofEvents.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofImage image[5];
		ofImage uiTop, uiDown, uiInfo;
		ofSoundPlayer sound[5];
		bool soundPaused[5];
		bool playCheck, songCheck;
		int lightValue;
		int width,height;

        ofArduino	arduino;
        bool	isArduinoInitialized;
        void setupArduino(const int & version);
        void analogPinChanged(const int & pinNum);

};
