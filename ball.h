#include<iostream>
#include<SDL.h>
#include "stdafx.h"
using namespace std;
class ball
{
    public:
    int x,y;
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
    void isDie();
	bool facingLeft;

	bool idle;
    long long countdead;
	SDL_Rect playersourceRect;

	SDL_Rect playerdesRect;
private:
    int FRAME_MOVING; //7
	int DELAY_MOVING;
    SDL_Rect clipsMOVING[4];
    int FRAME_Idle; //4
	int DELAY_Idle; //4
	SDL_Rect clipsIDLE[4];
    int frameClip;
};
