#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		ofVideoGrabber gabbie;
        ofVideoPlayer video;
        ofImage image1;
        ofImage image2;
        ofImage image3;
		int rotate;
		int width;
		int height;
		bool changeColor;


};
