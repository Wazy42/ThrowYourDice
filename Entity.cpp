#include "../../headers/graphics/Entity.hpp"

Entity::Entity(const sf::Texture& texture)
{
	this->texture = texture;
	this->sprite.setTexture(this->texture);
}

/// Sprite management

// Returns the entity's current position
sf::Vector2f Entity::getSpritePosition()
{
	return this->sprite.getPosition();
}

// Returns the entity's current sprite
sf::Sprite& Entity::getSprite()
{
	return this->sprite;
}

// Move the sprite by the given x and y pixels
void Entity::moveSprite(float x, float y)
{
	this->sprite.move(x, y);
}

// Move the sprite by the given vector
void Entity::moveSprite(sf::Vector2f movement)
{
	this->sprite.move(movement);
}

// Set the sprite's position to the given x and y pixels
void Entity::setSpritePosition(float x, float y)
{
	this->sprite.setPosition(x, y);
}

// Set the sprite's position to the given vector
void Entity::setSpritePosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

/// Texture management

// Returns the entity texture
sf::Texture& Entity::getTexture()
{
	return this->texture;
}

// Sets the entity texture
void Entity::setTexture(const sf::Texture& texture)
{
	this->texture = texture;
	this->sprite.setTexture(this->texture);
}

// Sets the texture rect
void Entity::setTextureRect(sf::IntRect rect)
{
	this->sprite.setTextureRect(rect);
}