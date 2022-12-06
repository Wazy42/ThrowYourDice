#include "headers/graphics/Entity.hpp"

Entity::Entity(const sf::Texture& texture)
{
	this->m_texture = texture;
	this->m_sprite.setTexture(this->m_texture);
}

Entity::~Entity()
{
}

sf::Vector2f Entity::getPosition()
{
	return this->m_sprite.getPosition();
}

void Entity::move(float x, float y)
{
	this->m_sprite.move(x, y);
}

void Entity::move(sf::Vector2f movement)
{
	this->m_sprite.move(movement);
}

void Entity::setPosition(float x, float y)
{
	this->m_sprite.setPosition(x, y);
}

void Entity::setPosition(sf::Vector2f position)
{
	this->m_sprite.setPosition(position);
}

void Entity::setTexture(const sf::Texture& texture)
{
	this->m_texture = texture;
	this->m_sprite.setTexture(this->m_texture);
}

void Entity::setTextureRect(sf::IntRect rect)
{
	this->m_sprite.setTextureRect(rect);
}

void Entity::setScale(float x, float y)
{
	if (y == 0)
	{
		this->m_sprite.setScale(x, x);
	}
	else
	{
		this->m_sprite.setScale(x, y);
	}
}

// TODO: Animation

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}