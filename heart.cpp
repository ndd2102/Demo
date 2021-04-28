#include"heart.h"
heart::heart()
{
    heartRect.x = 0;
    heartRect.y = 810;
    heartRect.w = 36;
    heartRect.h = 25;
}

void heart:: updatePos()
{
   heartRect.x += 0;
   heartRect.y -= 5;
}
