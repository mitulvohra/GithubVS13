#include<SDL.h>

#include "Graphics.h"

/*
*Graphics class Deals with all the Graphics off the game
*
*/

Graphics::Graphics(){
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "CaveStory");

}

Graphics::~Graphics(){
	SDL_DestroyWindow(this->_window);
	SDL_DestroyRenderer(this->_renderer);
}