#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Ball.h"
#include "Square.h"
#include "Triangle.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

		ofxPanel gui;
		ofxIntSlider count;
		ofxFloatSlider speedX;
		ofxFloatSlider speedY;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        vector <Square> mySquare;
        vector <Ball> myBall;
        vector <Triangle> myTriangle;
        int tempcount;

};
