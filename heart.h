#ifndef HEART_H
#define HEART_H
#include<iostream>
#include<SDL.h>
#include "bar.h"
using namespace std;
class heart
{
private:
    int z;
public:
    heart();
    int x,y;
    SDL_Rect heartRect;
    void updatePos();
};

#endif
