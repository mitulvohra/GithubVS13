#ifndef GRAPHICS_H
#define GRAPHICS_H

/*
*Graphics class Deals with all the Graphics off the game
*
*/
#include<map>
#include<string>

struct SDL_Window; //forward Declaration
struct SDL_Renderer;

class Graphics{
public:
	Graphics();
	~Graphics();

	/*
	*SDL_Surface* loadImage
	*Loads an image into the _spriteSheets map if it doesn't already exist
	*A as result each image will be only loaded once
	*Returns the image from the map regardless of whether or not it was loaded
	*/
	SDL_Surface* loadImage(const std::string &filepath);

	/*
	*void blitSurface
	*Draws a texture to a certain part of the screen
	*/
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/*
	* void flip
	*Renderes everything to the screen
	*/
	void flip();

	/*
	* void clear
	*Clears the screen
	*/
	void clear();

	/*
	* SDL_renderer gerRenderer
	* Returns renderer
	*/
	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window;   //Window Pointer variable
	SDL_Renderer* _renderer; //Rendered Pointer variable
    std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif