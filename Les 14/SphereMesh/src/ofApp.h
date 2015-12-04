#pragma once

#include "ofMain.h"

#define IMAGE_WIDTH 480
#define IMAGE_HEIGHT 300

#define MESH_SIZE 10


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    ofEasyCam cam;
    ofLight light;
    ofImage image;
    ofSpherePrimitive sphere;

    vector<int> origZ;

};
