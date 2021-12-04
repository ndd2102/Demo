#include<iostream>
#include<SDL.h>
#include"stdafx.h"
using namespace std;
class bar
{
private:
    int z;
public:
    bar();
    int x,y;
    SDL_Rect barRect;
    void updatePos();
};
