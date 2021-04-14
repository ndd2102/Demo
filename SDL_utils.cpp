
#include<SDL.h>
#include "SDL_utils.h"
#include<iostream>
#include<SDL_image.h>

using namespace std;
void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


SDL_Texture* LoadTexture(const std::string filepath, SDL_Renderer *render)
{
	//create temp surface then load IMG to it
	SDL_Surface* tmpsurface = NULL;
	tmpsurface = IMG_Load(filepath.c_str());
if( tmpsurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", filepath.c_str(), IMG_GetError() );
	}
	//create texture to load it into
	SDL_Texture* texture = NULL;
	texture = SDL_CreateTextureFromSurface(render, tmpsurface);
if( texture == NULL )
		{
			cout <<  "Unable to create texture from %s! SDL Error: %s\n", filepath.c_str(), SDL_GetError() ;
		}
	//free temp surface
	SDL_FreeSurface(tmpsurface);

	//return the loadedtexture
	return texture;
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{
	//Thiết lập hình chữ nhật đích mà chúng ta muốn vẽ ảnh vào trong
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Truy vẫn texture để lấy chiều rộng và cao (vào chiều rộng và cao tương ứng của hình chữ nhật đích)
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    //Đưa toàn bộ ảnh trong texture vào hình chữ nhật đích
	SDL_RenderCopy(ren, tex, NULL, &dst);
}
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{
	//Thiết lập hình chữ nhật đích mà chúng ta muốn vẽ ảnh vào trong
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
    dst.w = w;
    dst.h = h;
    //Đưa toàn bộ ảnh trong texture vào hình chữ nhật đích
    //(ảnh sẽ co dãn cho khớp với kích cỡ mới)
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

