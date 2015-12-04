#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "ofMain.h"
#include "MultiObject.h"
#define ArrayTriangle 5

class Triangle : public MultiObject
{
    public:
        Triangle();
        virtual ~Triangle();

        virtual  void draw();


    protected:
    private:
};

#endif // TRIANGLE_H
