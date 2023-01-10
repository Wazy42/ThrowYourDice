#include "AnimatedEntity.hpp"

AnimatedEntity::AnimatedEntity(const sf::Texture &texture, sf::Vector2f frameSize, int framesPerAnimation, int delayBetweenFrames) 
: Entity(texture)
{
	this->m_frameSize = frameSize;
	this->m_framesPerAnimation = framesPerAnimation;
	this->m_currentFrame = 0;
	this->m_currentAnimation = 0;
	this->m_delayBetweenFrames = delayBetweenFrames;
	this->m_delayBeforeNextFrame = delayBetweenFrames;
	this->setTextureRect(sf::IntRect(0, 0, (int)frameSize.x, (int)frameSize.y));
}

AnimatedEntity::~AnimatedEntity()
{
}

int AnimatedEntity::getCurrentFrame()
{
	return this->m_currentFrame;
}

void AnimatedEntity::setCurrentFrame(int frame)
{
	this->m_currentFrame = frame;
	this->setTextureRect(sf::IntRect(
		this->m_currentFrame * (int)this->m_frameSize.x,
		this->m_currentAnimation * (int)this->m_frameSize.y,
		(int)this->m_frameSize.x,
		(int)this->m_frameSize.y
	));
}

void AnimatedEntity::nextFrame()
{
	if (this->m_currentFrame >= this->m_framesPerAnimation - 1)
		this->setCurrentFrame(0);
	else
		this->setCurrentFrame(this->m_currentFrame + 1);

}

int AnimatedEntity::getCurrentAnimation()
{
	return this->m_currentAnimation;
}

void AnimatedEntity::setCurrentAnimation(int animation)
{
	this->m_currentAnimation = animation;
	this->setCurrentFrame(this->m_currentFrame);
}

void AnimatedEntity::update()
{
	this->m_delayBeforeNextFrame--;
	if (this->m_delayBeforeNextFrame <= 0)
	{
		this->m_delayBeforeNextFrame = this->m_delayBetweenFrames;
		this->nextFrame();
	}
}

void AnimatedEntity::setDelayBetweenFrames(int delay)
{
	this->m_delayBetweenFrames = delay;
	this->m_delayBeforeNextFrame = std::max(this->m_delayBeforeNextFrame, delay);
}