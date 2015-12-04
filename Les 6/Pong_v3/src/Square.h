#ifndef SQUARE_H
#define SQUARE_H
#include "ofMain.h"

class Square
{
    public:
        Square();
        virtual ~Square();

        // functies geinitialiseerd
        void setup();
        void update(int movement);
		void draw();


        float x;
        float y;
        float speedY;
        ofColor color;

    protected:
    private:
};

#endif // SQUARE_H
