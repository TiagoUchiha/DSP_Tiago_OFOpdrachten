#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Planet.h"
#define MAXplanet 4

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);

        ofxPanel gui;
        ofParameterGroup planetParams;
        //Planet planet01;
        //Planet planet02;
        Planet planet[MAXplanet];
        bool drawGrid;
        ofEasyCam cam;
        ofLight light;
        bool drawLight;


        ofImage image;

};
