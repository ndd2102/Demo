#include "bar.h"

bar::bar()
{
    barRect.x = rand() % 500;
    barRect.y = 800;
    barRect.w = 100;
	barRect.h = 15;
}

void bar:: updatePos()
{
   barRect.x += 0;
   barRect.y -= 5;
}
