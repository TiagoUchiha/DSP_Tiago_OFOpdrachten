#pragma once
#ifndef BALL_H
#define BALL_H

#include "ofMain.h"

class Ball
{
    public:
        Ball();
        virtual ~Ball();

        void setup();
        void update();
        void draw();
        void speedChange();

        // variables
        float x;
        float y;
        float speedY;
        float speedX;
        int radius;
        ofColor color;
    protected:
    private:
};

#endif // BALL_H
