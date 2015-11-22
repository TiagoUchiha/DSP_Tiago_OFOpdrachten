#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
        void audioOut(float * output, int bufferSize, int nChannels);
            ofSoundStream soundStream;
            float phase;
};
