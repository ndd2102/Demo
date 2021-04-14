#include "bar.h"
#include "ball.h"
#include "stdafx.h"
class game
{
public :

	/*CREATE A GAME WINDOW AND A RENDERER FOR THAT WINDOW , PASSING IN THE WIDTH AND THE HEIGHT OF THAT WINDOW
	* FLAGS 1 for FULLSCREEN , 4 for SHOWN
	*/
	void init(int SCREEN_WIDTH, int SCREEN_HEIGHT);
	void draw();
	void gameloop();
	int count = -1;
	bool die = false;
	bool die1 = false;
	bool _blood = false;
	int n = 10;
	int count_die = 0;

private:

	long long health;
	long long score = 0;
    int bg_y = 0;

	//mouse pos && angle for gun and bullet
	/*int angle;
	int mouseposx;
	int mouseposy;
	bool mousedown;
	int delaybullet;*/

	//map
	SDL_Texture* background;
    SDL_Texture* gameover;
	//player
	ball _ball;
	SDL_Texture* Ball;
	SDL_Texture* playerTextureidle;
	SDL_Texture* blood;


	//enemy
	vector<bar> _bar1;
	vector<bar> _bar2;
	/*SDL_Texture* enemyBlow;
	SDL_Texture* enemyBlow2;
	SDL_Texture* enemyTex;*/

	//sound
	Mix_Music* Music;
	Mix_Chunk* Mgameover;
	/*Mix_Chunk* zombiesound;

	//font and text
	SDL_Color textColor;
	SDL_Surface* textSurface;
	SDL_Texture* mTexture;
	string textureText;
	SDL_Rect scoreBOX;
	SDL_Rect healthbardesrect;
	SDL_Rect healthbarsourcerect;
	TTF_Font* gFont;
	SDL_Texture* HEALTHBARTexture;
	int healbox;*/

	SDL_Renderer* renderer;
	SDL_Window* window;
};


