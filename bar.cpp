#include "bar.h"

bar::bar()
{
    barRect.x =  (rand() % 11 * 50);
    barRect.y = 830;
    barRect.w = 100;
	barRect.h = 20;
}

void bar:: updatePos()
{
   barRect.x += 0;
   barRect.y -= 5;
}
