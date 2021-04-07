#include<iostream>
#include<SDL.h>
using namespace std;
class ball
{
    public:
	ball();

	void MoveLeft();

	void MoveRight();

	void getinput();
	void setdesrect();

	void setMoving();

	void animationMOVING();
	void setIdle();

	void animationIDLE();
	void ballup();

	bool facingLeft;

	bool idle;

	SDL_Rect playersourceRect;

	SDL_Rect playerdesRect;
private:
    int x,y;
    int FRAME_MOVING; //7
	int DELAY_MOVING;
    SDL_Rect clipsMOVING[4];
    int FRAME_Idle; //4
	int DELAY_Idle; //4
	SDL_Rect clipsIDLE[4];
    int frameClip;
};
