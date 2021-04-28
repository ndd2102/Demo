#include<SDL.h>
#include"game.h"

using namespace std;



int main(int argc, char* args[])
{
    srand(time(NULL));
	game game;
	game.init(SCREEN_WIDTH,SCREEN_HEIGHT);
	game.gameloop();
	SDL_Delay(4000);
	return 0;
}
