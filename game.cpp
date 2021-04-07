#include "game.h"
#include "stdafx.h"
#include "SDL_utils.h"
void game::init(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	//INIT ALL SDL COMPONENTS
	SDL_Init(SDL_INIT_EVERYTHING);
	//TTF_Init();

	//CREATE A GAME WINDOW
	window = NULL;
	window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	//CREATE A RENDERER FOR GAME
	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |SDL_RENDERER_PRESENTVSYNC);

	//LOAD TEXTURE
	background = IMG_LoadTexture( renderer, "background.jpg");
    Ball = IMG_LoadTexture( renderer ,"foo.png");
    Music = Mix_LoadMUS( "beat.wav" );
}
void game :: draw()
{
    SDL_RenderClear( renderer );
    bg_y -= 2;
    renderTexture(background, renderer, 0, bg_y, SCREEN_WIDTH, 3200);
    renderTexture(background, renderer, 0, bg_y + 3200, SCREEN_WIDTH, 3200);
				if(bg_y <= -3200 )
                {
                    bg_y = 0;
                }
    _ball.getinput();
    if (_ball.idle == true)
	{
	    _ball.setdesrect();
		_ball.animationIDLE();
		SDL_RenderCopy(renderer, Ball, &_ball.playersourceRect, &_ball.playerdesRect);
	}
	else
	{

		if (_ball.facingLeft == true)
		{
		    _ball.setdesrect();
			_ball.animationMOVING();
			SDL_RenderCopyEx(renderer, Ball, &_ball.playersourceRect, &_ball.playerdesRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
		}
		else
		{
		    _ball.setdesrect();
			_ball.animationMOVING();
			SDL_RenderCopyEx(renderer, Ball, &_ball.playersourceRect, &_ball.playerdesRect, NULL, NULL, SDL_FLIP_NONE);
		}

	}
	for (int i = 0; i < _bar.size(); i++)
	{

		if (_bar[i].barRect.y < 600)
	{
		bar __bar;
		_bar.push_back(__bar);
	}
	}
	/*if (_bar.size() < 50)
	{
		bar __bar;
		_bar.push_back(__bar);
	}*/
	for (int i = 0; i < _bar.size(); i++)
	{

		if (_bar[i].barRect.y < 0) {

				_bar.erase(_bar.begin() + i);
		}
	}

	for (int i = 0; i < _bar.size(); i++)
	{
		_bar[i].updatePos();
		SDL_SetRenderDrawColor( renderer, 0, 0xFF, 0, 0xFF );
		//SDL_RenderCopyEx(renderer, enemyTex, &_player.playersourceRect, &_enemy[i].enemyDesRect, NULL, NULL, SDL_FLIP_NONE);
		 SDL_RenderFillRect(renderer, &_bar[i].barRect);
		/*if (_enemy[i].isDead == false)
		{

			if (_enemy[i].faceLeft == true)
			{
				SDL_RenderCopyEx(maingamerenderer, enemyTex, &_player.playersourceRect, &_enemy[i].enemyDesRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
			}
			else
			{
				SDL_RenderCopyEx(maingamerenderer, enemyTex, &_player.playersourceRect, &_enemy[i].enemyDesRect, NULL, NULL, SDL_FLIP_NONE);
			}
		}

*/

		if (SDL_HasIntersection(&_bar[i].barRect, &_ball.playerdesRect))
		{
			_ball.ballup();
		}
	}
    SDL_RenderPresent( renderer );
}
void game::gameloop()
{
    bool start = true;
    SDL_Event e;
    Mix_PlayMusic(Music, -1);
    while(start)
			{
			    SDL_Delay(10);
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{

			case SDL_KEYDOWN:
			{
				if (e.key.keysym.sym == SDLK_ESCAPE)
				start = false;
				break;
			}
			}
		}
    draw();


}
}
