#include "game.h"
#include "stdafx.h"
#include "SDL_utils.h"
void game::init(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	//INIT ALL SDL COMPONENTS
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	//CREATE A GAME WINDOW
	window = NULL;
	window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	//CREATE A RENDERER FOR GAME
	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//LOAD TEXTURE
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	background = IMG_LoadTexture(renderer, "background.jpg");
	Ball = IMG_LoadTexture(renderer, "cat.png");
	gameover = IMG_LoadTexture(renderer, "gameover.png");
	blood = IMG_LoadTexture(renderer, "blood.png");
	Music = Mix_LoadMUS("theme_song.mp3");
	jumpsound = Mix_LoadWAV("jumpOnCrossbar.wav ");
	diesound = Mix_LoadWAV("die.wav ");
	Mgameover = Mix_LoadWAV("audio_game_over.wav ");
	health = 3;
	// LOAD FONT
	scoreBOX = { SCREEN_WIDTH / 2, 40 , 100, 100  };
	gFont = TTF_OpenFont("font.ttf", 20);
	textColor = { 0, 0, 0 };
}
void game::draw()
{
	SDL_RenderClear(renderer);
    score = SDL_GetTicks()/1000;
	bg_y -= 2;
	renderTexture(background, renderer, 0, bg_y, SCREEN_WIDTH, 3200);
	renderTexture(background, renderer, 0, bg_y + 3200, SCREEN_WIDTH, 3200);
	if (bg_y <= -3200)
	{
		bg_y = 0;
	}
	if ( _move )
    {
        _ball.getinput();
    }
	if (_ball.idle)
	{
		if (!die1)
			_ball.setdesrect();
		_ball.animationIDLE();
		SDL_RenderCopy(renderer, Ball, &_ball.playersourceRect, &_ball.playerdesRect);
	}
	else
	{

		if (!_ball.facingLeft)
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
	if ( _ball.y > 720 || _ball.y < 70)
	{
		die1 = true;
		_move = false;
		sound_die = true;
		if(sound_die && sound){
			  Mix_PlayChannel(-1, diesound, 0);
			  sound_die = false;
			  sound = false;
			 }
	}
	else(_move = true);
	//draw bar
	count++;
	//bar __bar;
	n = rand() % 4;
	if (count % (speed * 5) == 0)
	{
		if (n == 2 && _bar1.size() < 3 && _bar2.size() != NULL)
		{
		    bar __bar1;
			_bar1.push_back(__bar1);
		}
		else
		{
		    bar __bar3;
			_bar2.push_back(__bar3);
		}
	}
	for (int i = 0; i < _bar1.size(); i++)
	{

		if (_bar1[i].barRect.y < 0) {

			_bar1.erase(_bar1.begin() + i);
		}
	}
	for (int i = 0; i < _bar2.size(); i++)
	{

		if (_bar2[i].barRect.y < 0) {

			_bar2.erase(_bar2.begin() + i);
		}
	}

	for (int i = 0; i < _bar2.size(); i++)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0xFF, 0, 0xFF);
		_bar2[i].updatePos();
		SDL_RenderFillRect(renderer, &_bar2[i].barRect);
		if (die)
		{
			renderTexture(blood, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
			if(die1 == false)
                _ball.ballup();
			count_die++;
			if (count_die % 50 == 0) {
				_ball.x = _bar2[3].barRect.x;
				_ball.y = _bar2[3].barRect.y - 80;
				health--;
			}
			if(count_die % 52 == 0)
            {
                sound = true;
            }
			 die = false;
			 _move = true;
		}
		if (die1)
		{
			renderTexture(blood, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
			_ball.isDie();
			count_die++;
			ball_up = false;
			if (count_die % 50 == 0) {
				_ball.x = _bar2[3].barRect.x;
				_ball.y = _bar2[3].barRect.y - 80;
				health--;
			}
			if(count_die % 52 == 0)
            {
                sound = true;
            }
			die1 = false;
		}
		if(ball_up)
        {
             Mix_PlayChannel(-1, jumpsound, 0);
            _ball.ballup();
            ball_up = false;
        }
	}

	for (int i = 0; i < _bar2.size(); i++)
	{
	     if ((_ball.playerdesRect.x >= _bar2[i].barRect.x-29) && (_ball.playerdesRect.x <= _bar2[i].barRect.x+100) && (_ball.playerdesRect.y == _bar2[i].barRect.y-50)){

           // _ball.ballup();
            ball_up = true;
            //Mix_PlayChannel(-1, jumpsound, 0);
		}
	}
	for (int i = 0; i < _bar1.size(); i++)
	{
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0, 0xFF);
		_bar1[i].updatePos();
		SDL_RenderFillRect(renderer, &_bar1[i].barRect);

		if (SDL_HasIntersection(&_bar1[i].barRect, &_ball.playerdesRect))
		{
			die = true;
			_move = false;
			sound_die = true;

		}
		if(sound_die && sound){
			  Mix_PlayChannel(-1, diesound, 0);
			  sound_die = false;
			  sound = false;
			 }
	}
    str_score = "Score : ";
    score = SDL_GetTicks()/1000;
    textureText = to_string(score);
    str_score += textureText;
	textSurface = TTF_RenderText_Blended(gFont,  str_score.c_str(), textColor);
	mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	scoreBOX = { SCREEN_WIDTH - 100, 40 , textSurface->w, textSurface->h };
	SDL_RenderCopy(renderer, mTexture, NULL, &scoreBOX);
	SDL_RenderPresent(renderer);

}
void game::gameloop()
{
	bool start = true;
	SDL_Event e;
	Mix_PlayMusic(Music, -1);
	while (start)
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
		if (health <= 0)
		{
			Mix_PauseMusic();
			SDL_Delay(10);
			Mix_PlayChannel(-1, Mgameover, 0);
			SDL_Delay(1000);
			renderTexture(gameover, renderer, 0, 350, 600, 100);
			SDL_RenderPresent(renderer);
			start = false;
		}

	}
}
