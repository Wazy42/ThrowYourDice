#include "headers/graphics/Entity.hpp"

Entity::Entity(const sf::Texture& texture)
{
	this->texture = texture;
	this->sprite.setTexture(this->texture);
}

Entity::~Entity()
{
}

sf::Vector2f Entity::getPosition()
{
	return this->sprite.getPosition();
}

void Entity::move(float x, float y)
{
	this->sprite.move(x, y);
}

void Entity::move(sf::Vector2f movement)
{
	this->sprite.move(movement);
}

void Entity::setPosition(float x, float y)
{
	this->sprite.setPosition(x, y);
}

void Entity::setPosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

void Entity::setTexture(const sf::Texture& texture)
{
	this->texture = texture;
	this->sprite.setTexture(this->texture);
}

void Entity::setTextureRect(sf::IntRect rect)
{
	this->sprite.setTextureRect(rect);
}

void Entity::setScale(float x, float y)
{
	if (y == 0)
	{
		this->sprite.setScale(x, x);
	}
	else
	{
		this->sprite.setScale(x, y);
	}
}

// TODO: Animation

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}