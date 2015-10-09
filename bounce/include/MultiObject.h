#pragma once
#ifndef MULTIOBJECT_H
#define MULTIOBJECT_H
#include "ofMain.h"

class MultiObject
{
    public:
        MultiObject();
        virtual ~MultiObject();

        void setup();
		void update();

        //variables used on ball.cpp
        float x;
        float y;
        float speedY;
        float speedX;
        int radius;
        ofColor color;

    protected:
    private:
};

#endif // MULTIOBJECT_H

