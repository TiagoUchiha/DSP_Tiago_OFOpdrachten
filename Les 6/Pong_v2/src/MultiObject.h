#ifndef MULTIOBJECT_H
#define MULTIOBJECT_H
#include "ofMain.h"


class MultiObject
{
    public:
        MultiObject();
        virtual ~MultiObject();

        void setup();
		void draw();
        void update(int);

        //variables used on ball.cpp
        float x;
        float y;
        float speedY;
        float speedX;
        int radius;
        ofColor color;
        float speedXS;
        float speedYS;
    protected:
    private:
};

#endif // MULTIOBJECT_H
