#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H
#include<map>
#include<string>
#include<vector>
#include "Globals.h"
#include "Sprite.h"


class Graphics;

/*
 *AnimatedSprite class 
 *Holds the logic for animating sprites
 */

class AnimatedSprite : public Sprite{
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height
		, float posX, float posY, float timeToUpdate);

	/*
	* void playAnimation
	* play the animation provided it is not already playing
	*
	*/

	void playAnimation(std::string animation, bool once =false);

	/*void update
	 *Updates the animated sprite
	 */
	void update(int elapsedTime);

	/* void draw
	 * Draws the sprite to the string
	 */
	void draw(Graphics &graphics, int x, int y);


protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;
	/*
	* void addAnimation
	* Adds an animation to the map of animations for the sprite
	*/
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

	/*
	* void resetAnimation
	* resets all animations associated with the sprite
	*/

	void resetAnimation();

	/*
	*void stopAnimation
	*stops the current animation
	*/
	void stopAnimation();

	/*
	* void setVisible
	*Changes the visibility of the animated sprite
	*/
	void setVisible(bool visible);

	/*
	*void animationDone
	*Logic which happens when animation completes
	*/
	virtual void animationDone(std::string currentAnimation)=0;

	/*void setupAnimations
	*A required function that sets up all animations for a sprite
	*/

	virtual void setupAnimations()=0;


private:
 std::map<std::string, std::vector<SDL_Rect>> _animations;
 std::map<std::string, Vector2> _offsets;

 int _frameIndex;
 double _timeElapsed;
 bool _visible;

};

#endif