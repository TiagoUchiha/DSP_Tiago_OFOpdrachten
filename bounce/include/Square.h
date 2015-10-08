#pragma once
#ifndef SQUARE_H
#define SQUARE_H
#include "ofMain.h"
#include "MultiObject.h"
#define ArraySquares 10
#define squaresize 100

class Square : public MultiObject
{

    public:
        Square();
        virtual ~Square();

         // functies geinitialiseerd
		virtual  void draw();

    protected:
    private:
};

#endif // SQUARE_H

