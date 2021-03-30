#include <ctime>
#include<iostream>
#include<SDL.h>
#include "SDL_utils.h"
#include <SDL_image.h>
#include <vector>
//#include "background.h"
//#include "bar.h"
using namespace std;
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 800;
const string WINDOW_TITLE = "im";


int main(int argc, char* argv[])
{
    int score = 0;
    SDL_Window* window ;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Texture* background = loadTexture( "background.jpg", renderer );
    SDL_Texture* background_1 = loadTexture( "1.png", renderer );
    SDL_Texture* background_2 = loadTexture( "2.png", renderer );
    SDL_Texture* background_3 = loadTexture( "3.png", renderer );
    SDL_Texture* background_4 = loadTexture( "4.png", renderer );
    SDL_Texture* background_5 = loadTexture( "5.png", renderer );
    SDL_Texture* background_6 = loadTexture( "6.png", renderer );
    SDL_Texture* ball = loadTexture( "ball.png", renderer );
    SDL_Texture* gameover = loadTexture( "gameover.png", renderer );
    SDL_Event e;
    bool ballUp = true;
    bool start = true ;
    bool Gameover = false;
    int a = 0;
    int live = 3;
    SDL_Rect bar[600];
    int _bar = 0;
    srand(time(0));
    /*vector<bar> _bar;
    if(_bar.size() < 50)
    {
         bar __bar;
    _bar.push_back(__bar);
    }
    //srand(time(0));
    for (int i = 0; i < _bar.size();i++)
    {
        if(_bar[i].barRect.y < 0)
        {
            _bar[i].erase(_bar.begin()+i);
        }
    }*/

       for (int i = 0; i <600;)
    {
        bar[i].h = 15;
        bar[i].w = 100;
        a = rand() % 500;
        if(a % 80 == 0 && bar[i - 1].x != a){
        bar[i].x = a;
        i++;
        }
        bar[i].y = 800;

    }

    int x = bar[0].x + 10, y = bar[0].y - 20;
    while(start)
			{
			    SDL_Delay(10);
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						return 0;
					}
				}


				//Clear screen
				SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( renderer );
                /*while(true)
                {
                    renderTexture(background_1, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                    renderTexture(background_2, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                    renderTexture(background_3, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                    renderTexture(background_4, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                    renderTexture(background_5, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                    renderTexture(background_6, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                }*/
				renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
				renderTexture(ball, renderer, x, y, 30, 30);
                    /*a = rand()% 6;
                    if(a == 2){
                        for (int i = 0; i <= red_cur; i++) {
                            SDL_SetRenderDrawColor(renderer, 255,0, 0, 255);
                            SDL_RenderFillRect(renderer, &red_bar[i]);
                            }
                        }
                    else {*/
                        for (int i = 0; i <= _bar; i++) {
                            if(i % 5 == 0 && i != 0)
                            {
                            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                            SDL_RenderFillRect(renderer, &bar[i]);
                            }
                        else{
                            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                            SDL_RenderFillRect(renderer, &bar[i]);
                        }
                    }
                    //}

            if(Gameover)
                {
                    renderTexture(gameover, renderer, 0,350, 600, 100);
                    start = false;
                }
				//Update screen
				SDL_RenderPresent( renderer );
            if (e.type == SDL_QUIT) break;
            if (e.type == SDL_KEYDOWN) {
        	switch (e.key.keysym.sym) {
        		case SDLK_ESCAPE:quitSDL(window, renderer);return 0;
        		case SDLK_LEFT: x-= 3; break;
            	case SDLK_RIGHT:x+= 3;break;
        		default: break;
			}
        }

        if (bar[_bar].y <= 700)
            _bar++;
        for (int i = 0; i <= _bar; i++)
            bar[i].y -= 5;
        for (int i = 0; i <= _bar; i++) {
            if ((x >= bar[i].x-29) && (x <= bar[i].x+100) && (y >= bar[i].y-33) && (y <= bar[i].y-10)){
                    score += 1;
                ballUp = true;
            }
        }
        for (int i = 5; i <= _bar; i += 5) {
            if ((x >= bar[i].x-29) && (x <= bar[i].x+100) && (y >= bar[i].y-23) && (y <= bar[i].y-10)){
                    cout << live;
                    x = bar[i+1].x;
                    y = bar[i+1].y - 33;
                    live --;
            }
        }
        if( y < 0 || y > 800)
        {
            Gameover = true;
        }
        if (ballUp)
            y -= 6;
        else y += 6;
        ballUp = false;
            if(live <= 0)
            {
                Gameover = true;
            }
			}
 waitUntilKeyPressed();
 cout << score;
    return 0;
}



