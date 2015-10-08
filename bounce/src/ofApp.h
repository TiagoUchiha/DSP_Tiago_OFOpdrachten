#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "Square.h"
#include "triangle.h"
#include "ofxGui.h"

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

        Ball ball;
        Square square;
        Triangle triangle;
        vector <Square> mySquare;
};
