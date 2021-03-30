#ifndef SDL_UTILS__H
#define SDL_UTILS__H

#include<iostream>
#include<SDL.h>

using namespace std;

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT,
             const string WINDOW_TITLE);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
bool loadMedia(SDL_Texture* gTexture,SDL_Texture* loadTexture( std::string path ));
SDL_Texture* loadTexture( std::string path ,SDL_Renderer* renderer);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);

#endif // SDL_UTILS__H
