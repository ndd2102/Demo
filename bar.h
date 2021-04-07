#include<iostream>
#include<SDL.h>
using namespace std;
class bar
{
public:
    bar();
    int x,y;
    SDL_Rect barRect;
    void updatePos();
};
