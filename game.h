#ifndef GAME_H
#define GAME_H
#include "bar.h"
#include "ball.h"
#include "heart.h"
#include <SDL_image.h>
#include <string>
#include <vector>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include"SDL_utils.h"
class game
{
public:

	/*CREATE A GAME WINDOW AND A RENDERER FOR THAT WINDOW , PASSING IN THE WIDTH AND THE HEIGHT OF THAT WINDOW
	* FLAGS 1 for FULLSCREEN , 4 for SHOWN
	*/

	bool start = true;

	//if showing menu
	bool menu1 = true;
	bool menu2 = false;

	//if gamer are playing the game
	bool playing = false;

	//make main character OP
	bool op = true;

	//if lose the game
	bool lose = false;

	bool choose_player = false;


	int a = 15, b = 5;
	int xm, ym;
	void init(int SCREEN_WIDTH, int SCREEN_HEIGHT);
	void draw();
	void gameloop();
	void drawMenu1();
	void drawMenu2();
	void Resrest();
	int count = -1;
	bool die = false;
	bool die1 = false;
	bool sound_die = false;
	bool ball_up = false;
	bool _blood = false;
	bool _move = true;
	bool sound1 = true;
	bool sound2 = true;
	bool sound_jump = false;
	bool _choose = true;
	bool first_time = true;
	bool _cat = false;
	bool _dog = false;
	int n = 10;
	int count_die = 0;
	bool CheckM(int& x, int& y, SDL_Rect& rect);
private:

	long long health;
	long long score = 0;
	long long time = 0;
	int bg_y = 0;
	//menu
	SDL_Texture* Menu;

	//background
	SDL_Texture* background;
	SDL_Texture* _background;
	SDL_Texture* gameover;
	SDL_Texture* choose;
	SDL_Texture* blood;
	//player
	ball _ball;
	SDL_Texture* Cat_menu;
	SDL_Texture* Cat;
	SDL_Texture* CatIdle;

	SDL_Texture* Dog_menu;
	SDL_Texture* Dog;
	SDL_Texture* DogIdle;
    //item
	SDL_Texture* Heart_cat;
	SDL_Texture* Heart_dog;
    SDL_Texture* slow;


	//bar
	vector<bar> _bar1;
	vector<bar> _bar2;
	vector<heart> _heart;
	SDL_Texture* bar1;
	SDL_Texture* bar2;
	//sound
	Mix_Music* Music;
	Mix_Chunk* Mgameover;
	Mix_Chunk* jumpsound;
	Mix_Chunk* diesound;
	Mix_Chunk* healthsound;

	//font and text
	TTF_Font* gFont;
	TTF_Font* Font;
	SDL_Color textColor;
	//score
	SDL_Surface* textSurface;
	SDL_Texture* mTexture;
	string str_score;
	SDL_Rect scoreBOX;
	//menu
	SDL_Rect MENU[3];
	SDL_Surface* PlaySurface;
	SDL_Texture* PlayTexture;
	string play;

	SDL_Surface* ResrestSurface;
	SDL_Texture* ResrestTexture;
	string resrest;

	SDL_Surface* quitSurface;
	SDL_Texture* quitTexture;
	string quit;
	//heart
	SDL_Surface* healthSurface;
	SDL_Texture* healthTexture;
	SDL_Rect Health;
	string str_health;



	SDL_Renderer* renderer;
	SDL_Window* window;
};

#endif // GAME__H


