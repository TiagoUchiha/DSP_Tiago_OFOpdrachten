#pragma once
#ifndef BALL_H
#define BALL_H
#include "ofMain.h"
#include "MultiObject.h"
#define ArrayBalls 5

class Ball : public MultiObject
{
    public:
        // constructor
        Ball();
        virtual ~Ball();

        // functies geinitialiseerd
		virtual void draw();

    protected:
    private:
};

#endif // BALL_H
