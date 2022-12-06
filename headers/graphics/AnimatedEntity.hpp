#pragma once

#include <SFML/Graphics.hpp>
#include "Const.hpp"
#include "Entity.hpp"

class AnimatedEntity : public Entity
{
public:
	/// <summary>
	/// Create an animated entity, with a texture to render.
	/// </summary>
	/// <param name="texture">The texture containing all animations</param>
	/// <param name="frameSize">The size of one frame, in pixels</param>
	/// <param name="framesPerAnimation">Number of frames per animations</param>
	/// <param name="delayBetweenFrames">Delay in game frame between each animation frame</param>
	AnimatedEntity(const sf::Texture&, sf::Vector2f frameSize, int framesPerAnimation, int delayBetweenFrames);
	~AnimatedEntity();

	// Animation

	/// <summary>
	/// Get the current frame number.
	/// </summary>
	int getCurrentFrame();

	/// <summary>
	/// Set the current frame.
	/// </summary>
	/// <param name="frame">Frame number</param>
	void setCurrentFrame(int);

	/// <summary>
	/// Move to the next frame.
	/// </summary>
	void nextFrame();

	/// <summary>
	/// Get the current animation number.
	/// </summary>
	int getCurrentAnimation();
	
	/// <summary>
	/// Set the current animation.
	/// </summary>
	/// <param name="animation">Animation number</param>
	void setCurrentAnimation(int);

	/// <summary>
	/// Update the animation.
	/// </summary>
	void update();
	
	/// <summary>
	/// Chnage the delay between frames.
	/// </summary>
	void setDelayBetweenFrames(int);
	

protected:
	sf::Vector2f m_frameSize; // Size of a frame in pixel
	int m_framesPerAnimation; // Number of frames in an animation
	int m_currentFrame; // Current frame in the animation
	int m_currentAnimation; // Current animation
	int m_delayBetweenFrames; // Number of game frames to wait beween each animation frame
	int m_delayBeforeNextFrame; // Number of game frames to wait before the next frame
};