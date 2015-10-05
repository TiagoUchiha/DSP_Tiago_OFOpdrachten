#ifndef BALL_H
#include "ofMain.h"
#define BALL_H
#define ArrayBalls 5

class Ball
{
    public:
        Ball();
        virtual ~Ball();

        // morgen vragen waarom hier en bij de ofApp?
		void setup();
		void update();
		void draw();


        //variables used on ball.cpp
        float x[ArrayBalls];
        float y[ArrayBalls];
        float speedY[ArrayBalls];
        float speedX[ArrayBalls];
        int radius[ArrayBalls];
        ofColor color[ArrayBalls];




    protected:
    private:
};

#endif // BALL_H
