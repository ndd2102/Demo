
#include "game.h"
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
	_background = IMG_LoadTexture(renderer, "_background.png");
	background = IMG_LoadTexture(renderer, "background.jpg");
	choose = IMG_LoadTexture(renderer, "choose.jpg");
	Cat = IMG_LoadTexture(renderer, "cat.png");
	CatIdle = IMG_LoadTexture(renderer, "CatIdle.png");
	Cat_menu = IMG_LoadTexture(renderer, "Cat_menu.png");

	DogIdle = IMG_LoadTexture(renderer, "DogIdle.png");
	Dog = IMG_LoadTexture(renderer, "Dog.png");
	Dog_menu = IMG_LoadTexture(renderer, "Dog_menu.png");
	Heart_cat = IMG_LoadTexture(renderer, "heart_cat.png");
	Heart_dog = IMG_LoadTexture(renderer, "heart_dog.png");
	bar1 = IMG_LoadTexture(renderer, "bar1.png");
	bar2 = IMG_LoadTexture(renderer, "bar2.jpg");
	gameover = IMG_LoadTexture(renderer, "gameover.png");
	blood = IMG_LoadTexture(renderer, "blood.png");
	Menu = IMG_LoadTexture(renderer, "menu.jpg");
	//Load music
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Music = Mix_LoadMUS("music.mp3");
	healthsound = Mix_LoadWAV("heart.wav ");
	jumpsound = Mix_LoadWAV("jumpOnCrossbar.wav ");
	diesound = Mix_LoadWAV("die.mp3 ");
	Mgameover = Mix_LoadWAV("gameover.mp3 ");
	health = 3;
	// LOAD FONT
	gFont = TTF_OpenFont("font.ttf", 30);
	Font = TTF_OpenFont("ExtraFont.ttf", 40);
	textColor = { 0, 0, 0 };
}
void game::drawMenu1()
{
	SDL_Event m_event;
	SDL_RenderClear(renderer);
	renderTexture(Menu, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	play = "PLAY";
	PlaySurface = TTF_RenderText_Blended(Font, play.c_str(), textColor);
	PlayTexture = SDL_CreateTextureFromSurface(renderer, PlaySurface);
	MENU[0] = { 250, 370 , PlaySurface->w, PlaySurface->h };
	SDL_RenderCopy(renderer, PlayTexture, NULL, &MENU[0]);


	quit = "QUIT";
	quitSurface = TTF_RenderText_Blended(Font, quit.c_str(), textColor);
	quitTexture = SDL_CreateTextureFromSurface(renderer, quitSurface);
	MENU[1] = { 250, 440 , quitSurface->w, quitSurface->h };
	SDL_RenderCopy(renderer, quitTexture, NULL, &MENU[1]);
	SDL_RenderPresent(renderer);
}

void game::drawMenu2() {
	play = "PLAY";
	PlaySurface = TTF_RenderText_Blended(Font, play.c_str(), textColor);
	PlayTexture = SDL_CreateTextureFromSurface(renderer, PlaySurface);
	MENU[0] = { 250, 300 , PlaySurface->w, PlaySurface->h };
	SDL_RenderCopy(renderer, PlayTexture, NULL, &MENU[0]);

	resrest = "RESREST";
	ResrestSurface = TTF_RenderText_Blended(Font, resrest.c_str(), textColor);
	ResrestTexture = SDL_CreateTextureFromSurface(renderer, ResrestSurface);
	MENU[2] = { 250, 370 , ResrestSurface->w, ResrestSurface->h };
	SDL_RenderCopy(renderer, ResrestTexture, NULL, &MENU[2]);

	quit = "QUIT";
	quitSurface = TTF_RenderText_Blended(Font, quit.c_str(), textColor);
	quitTexture = SDL_CreateTextureFromSurface(renderer, quitSurface);
	MENU[1] = { 250, 440 , quitSurface->w, quitSurface->h };
	SDL_RenderCopy(renderer, quitTexture, NULL, &MENU[1]);
	SDL_RenderPresent(renderer);
}

void game::draw()
{
	SDL_RenderClear(renderer);
	if (score == 300)
	{
		a = 20;
		b = 4;
	}
	if (score == 700)
	{
		a = 25;
		b = 3;
	}
	if (score == 1200)
	{
		a = 30;
		b = 2;
	}
	if (score == 2000)
	{
		a = 35;
		b = 1;
	}
	bg_y -= 2;
	renderTexture(background, renderer, 0, bg_y, SCREEN_WIDTH, 3200);
	renderTexture(background, renderer, 0, bg_y + 3200, SCREEN_WIDTH, 3200);
	renderTexture(_background, renderer, 0, 50, 600, 50);
	if (bg_y <= -3200)
	{
		bg_y = 0;
	}
	if (_move)
	{
		_ball.getinput();
	}
	//animation
	if (_choose) {
		if (_ball.idle)
		{
			if (!die1) _ball.setdesrect();
			_ball.animationIDLE();
			SDL_RenderCopy(renderer, CatIdle, &_ball.playersourceRect, &_ball.playerdesRect);
		}
		else
		{
			if (!_ball.facingLeft)
			{
				_ball.setdesrect();
				_ball.animationMOVING();
				SDL_RenderCopyEx(renderer, Cat, &_ball.playersourceRect, &_ball.playerdesRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
			}
			else
			{
				_ball.setdesrect();
				_ball.animationMOVING();
				SDL_RenderCopyEx(renderer, Cat, &_ball.playersourceRect, &_ball.playerdesRect, NULL, NULL, SDL_FLIP_NONE);
			}

		}
	}
	else
	{
		if (_ball.idle)
		{
			if (!die1) _ball.setdesrect();
			_ball.animationIDLE();
			SDL_RenderCopy(renderer, DogIdle, &_ball.playersourceRect, &_ball.playerdesRect);
		}
		else
		{
			if (!_ball.facingLeft)
			{
				_ball.setdesrect();
				_ball.animationMOVING();
				SDL_RenderCopyEx(renderer, Dog, &_ball.playersourceRect, &_ball.playerdesRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
			}
			else
			{
				_ball.setdesrect();
				_ball.animationMOVING();
				SDL_RenderCopyEx(renderer, Dog, &_ball.playersourceRect, &_ball.playerdesRect, NULL, NULL, SDL_FLIP_NONE);
			}

		}
	}
	//draw bar
	count++;
	n = rand() % 4;
	int m = rand() % 10;

	if (count % a == 0)
	{
		if (n == 2 && _bar1.size() < 3 && _bar2.size() != NULL && count > 50)
		{
			bar __bar1;
			_bar1.push_back(__bar1);
		}
		else
		{
			bar __bar2;
			_bar2.push_back(__bar2);

			if (m == 1)
			{
				heart __heart;
				__heart.heartRect.x = __bar2.barRect.x + 30;
				_heart.push_back(__heart);
			}
		}
	}
	for (int i = 0; i < _bar1.size(); i++)
	{

		if (_bar1[i].barRect.y < 50) {

			_bar1.erase(_bar1.begin() + i);
		}
	}
	for (int i = 0; i < _bar2.size(); i++)
	{

		if (_bar2[i].barRect.y < 50) {

			_bar2.erase(_bar2.begin() + i);
		}
	}
	for (int i = 0; i < _heart.size(); i++)
	{

		if (SDL_HasIntersection(&_heart[i].heartRect, &_ball.playerdesRect)) {

			_heart.erase(_heart.begin() + i);
			Mix_PlayChannel(-1, healthsound, 0);
			health++;
		}
	}

	if (_ball.y > 750 || _ball.y < 70)
	{
		die1 = true;
		_move = false;
		sound_die = true;
		if (sound_die && sound2) {
			Mix_PlayChannel(-1, diesound, 0);
			sound_die = false;
			sound2 = false;
		}
	}
	else(_move = true);
	//draw bar2
	for (int i = 0; i < _bar2.size(); i++)
	{
		if ((_ball.playerdesRect.x >= _bar2[i].barRect.x - 30) && (_ball.playerdesRect.x <= _bar2[i].barRect.x + 80) && (_ball.playerdesRect.y + 58 >= _bar2[i].barRect.y) && (_ball.playerdesRect.y + 43 <= _bar2[i].barRect.y)) {

			ball_up = true;
			if (sound1 && !die1)
			{
				score += 10;
				Mix_PlayChannel(-1, jumpsound, 0);
				sound1 = false;
			}
		}
	}

	if (!ball_up)
		sound1 = true;

	for (int i = 0; i < _bar2.size(); i++)
	{
		_bar2[i].updatePos();
		SDL_RenderCopy(renderer, bar2, NULL, &_bar2[i].barRect);
		if (die)
		{
			renderTexture(blood, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
			if (die1 == false)
				_ball.ballup();
			count_die++;
			if (count_die % 50 == 0) {
				_ball.x = _bar2[b].barRect.x + 30;
				_ball.y = _bar2[b].barRect.y - 100;
				health--;
			}
			if (count_die % 52 == 0)
			{
				sound2 = true;
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
				_ball.x = _bar2[b].barRect.x + 30;
				_ball.y = _bar2[b].barRect.y - 100;
				health--;
			}
			if (count_die % 52 == 0)
			{
				sound2 = true;
			}
			die1 = false;
		}
		if (ball_up)
		{
			_ball.ballup();
			ball_up = false;
		}
	}




	for (int i = 0; i < _bar1.size(); i++)
	{
		_bar1[i].updatePos();
		SDL_RenderCopy(renderer, bar1, NULL, &_bar1[i].barRect);

		if ((_ball.playerdesRect.x >= _bar1[i].barRect.x - 29) && (_ball.playerdesRect.x <= _bar1[i].barRect.x + 100) && (_ball.playerdesRect.y + 50 >= _bar1[i].barRect.y) && (_ball.playerdesRect.y + 43 <= _bar1[i].barRect.y))
		{
			die = true;
			_move = false;
			sound_die = true;

		}
		if (sound_die && sound2) {
			Mix_PlayChannel(-1, diesound, 0);
			sound_die = false;
			sound2 = false;
		}
	}

	for (int i = 0; i < _heart.size(); i++)
	{
		_heart[i].updatePos();
		if (_choose)
			SDL_RenderCopy(renderer, Heart_cat, NULL, &_heart[i].heartRect);
		else SDL_RenderCopy(renderer, Heart_dog, NULL, &_heart[i].heartRect);
	}
	str_score = "Score : ";
	str_score += to_string(score);
	textSurface = TTF_RenderText_Solid(gFont, str_score.c_str(), textColor);
	mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	scoreBOX = { SCREEN_WIDTH - 200, 10 , textSurface->w, textSurface->h };
	SDL_RenderCopy(renderer, mTexture, NULL, &scoreBOX);
	str_health = "x ";
	str_health += to_string(health);
	healthSurface = TTF_RenderText_Solid(gFont, str_health.c_str(), textColor);
	healthTexture = SDL_CreateTextureFromSurface(renderer, healthSurface);
	Health = { 100, 10 , healthSurface->w, healthSurface->h };
	SDL_RenderCopy(renderer, healthTexture, NULL, &Health);

	if (_choose)	renderTexture(Heart_cat, renderer, 10, 0, 80, 60);
	else renderTexture(Heart_dog, renderer, 10, 0, 80, 60);


	SDL_RenderPresent(renderer);

}
void game::Resrest()
{
	_bar1.erase(_bar1.begin(), _bar1.end());
	_bar2.erase(_bar2.begin(), _bar2.end());
	_heart.erase(_heart.begin(), _heart.end());
	score = 0;
	_ball.x = 200;
	_ball.y = 100;
	health = 3;
}
void game::gameloop()
{
	SDL_Event e;
	//main game running
	Mix_PlayMusic(Music, -1);
	while (start)
	{
		SDL_Delay(10);
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			if (menu1)
			{
				switch (e.type)
				{
				case SDL_QUIT:
				{
					quitSDL(window, renderer);
				}
				case SDL_MOUSEBUTTONDOWN:
				{
					SDL_GetMouseState(&xm, &ym);
					//start
					if (first_time && xm > 250 && xm < 350 && ym > 370 && ym < 420) {
						choose_player = true;
						menu1 = false;
					}
					if (!first_time && xm > 250 && xm < 350 && ym > 370 && ym < 420) {
						playing = true;
						menu1 = false;
					}
					//quit
					if (xm > 250 && xm < 350 && ym > 440 && ym < 490) {
						quitSDL(window, renderer);
					}

					break;
				}

				}
			}
			if (menu2)
			{
				switch (e.type)
				{
				case SDL_QUIT:
				{
					quitSDL(window, renderer);
				}
				case SDL_MOUSEBUTTONDOWN:
				{
					SDL_GetMouseState(&xm, &ym);
					//start
					if (xm > 250 && xm < 350 && ym > 300 && ym < 350) {
						playing = true;
						menu2 = false;
					}
					//quit
					if (xm > 250 && xm < 420 && ym > 370 && ym < 420) {
						Resrest();
						playing = true;
						menu2 = false;

					}
					if (xm > 250 && xm < 350 && ym > 440 && ym < 490)
					{
						quitSDL(window, renderer);
					}
					break;
				}

				}
			}
			if (choose_player && first_time)
			{
				switch (e.type)
				{
                case SDL_QUIT:
				{
					quitSDL(window, renderer);
				}
				case SDL_MOUSEMOTION:
				{

					SDL_GetMouseState(&xm, &ym);
					if (xm > 350 && xm < 600 && ym > 350 && ym < 800) {
						_ball.animationIDLE();
						SDL_RenderCopy(renderer, DogIdle, &_ball.playersourceRect, &_ball.DogdesRect);
					}
					if (xm > 0 && xm < 250 && ym > 350 && ym < 800) {
						_ball.animationIDLE();
						SDL_RenderCopy(renderer, CatIdle, &_ball.playersourceRect, &_ball.CatdesRect);
					}

					SDL_RenderPresent(renderer);
					break;
				}
				case SDL_MOUSEBUTTONDOWN:
				{

					//start
					if (xm > 0 && xm < 250 && ym > 350 && ym < 800) {
						first_time = false;
						_choose = true;
						playing = true;
						choose_player = false;
					}

					if (xm > 350 && xm < 600 && ym > 350 && ym < 800) {
						first_time = false;
						_choose = false;
						playing = true;
						choose_player = false;
					}
				}
				}

			}

			if (playing)
			{
				switch (e.type)
				{
				    case SDL_QUIT:
				{
					quitSDL(window, renderer);
				}
				case SDL_KEYDOWN:
				{
					if (e.key.keysym.sym == SDLK_ESCAPE)
						if (menu2)
						{
							menu2 = false;
							playing = true;
						}
						else
						{
							menu2 = true;
							playing = false;
						}
					break;
				}
				}
			}
		}
		if (menu1)
		{
			drawMenu1();
		}
		if (menu2)
		{
			drawMenu2();
		}
		else if (choose_player)
		{
			SDL_RenderClear(renderer);
			renderTexture(choose, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
			renderTexture(Cat_menu, renderer, 10, 460, 300, 290);
			renderTexture(Dog_menu, renderer, 310, 460, 300, 290);
			SDL_RenderPresent(renderer);
		}
		else if (playing)
		{
			draw();

		}
		if (health <= 0)
		{
			Mix_PauseMusic();
			SDL_Delay(10);
			Mix_PlayChannel(-1, Mgameover, 0);
			SDL_Delay(10);
			renderTexture(gameover, renderer, 0, 350, 600, 100);
			SDL_RenderPresent(renderer);
			SDL_Delay(3000);
			waitUntilKeyPressed();
			Resrest();
			Mix_PlayMusic(Music, -1);
			menu1 = true;
			playing = false;
		}

	}
}
