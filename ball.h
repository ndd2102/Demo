#ifndef BALL_H
#define BALL_H
#include<iostream>
#include<SDL.h>

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

	void setDead();
	void animationDead();

	void ballup();
    void isDie();
	bool facingLeft;

	bool idle;
    long long countdead;
	SDL_Rect playersourceRect;
	SDL_Rect playerdesRect;

	SDL_Rect CatdesRect;
	SDL_Rect DogdesRect;
private:
    int FRAME_MOVING;
	int DELAY_MOVING;
    SDL_Rect clipsMOVING[8];

    int FRAME_Idle;
	int DELAY_Idle;
	SDL_Rect clipsIDLE[10];

    int FRAME_Dead;
	int DELAY_Dead;
	SDL_Rect clipsDead[10];
    int frameClip;
};
#endif
