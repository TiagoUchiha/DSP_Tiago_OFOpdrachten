#pragma once
#ifndef MULTIOBJECT_H
#define MULTIOBJECT_H


#include "ofMain.h"
#define MultiObjectMAX 10


class MultiObject
{
    public:
        MultiObject();
        virtual ~MultiObject();

        void setup();
		void update();
		void makeSquareVector();

        //variables used on ball.cpp
        float x[MultiObjectMAX];
        float y[MultiObjectMAX];
        float speedY[MultiObjectMAX];
        float speedX[MultiObjectMAX];
        int radius[MultiObjectMAX];
        ofColor color[MultiObjectMAX];

    protected:
    private:
};

#endif // MULTIOBJECT_H

