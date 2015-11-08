#ifndef BALL_H
#define BALL_H
#include "ofMain.h"
#include "MultiObject.h"
#include "ofSoundPlayer.h"

class Ball : public MultiObject
{
    public:
        Ball();
        virtual ~Ball();

        // functies geinitialiseerd
        void setup();
        void update(int playerY, int enemyY);
		void draw();
		void updateSpeed(float, float);
        float x;
        float y;
        float speedY;
        float speedX;
        int radius;
        ofColor color;
        float speedXS;
        float speedYS;

        ofSoundPlayer playerSound;
        ofSoundPlayer enemySound;
        ofSoundPlayer pongSound;


    protected:
    private:
};

#endif // BALL_H
