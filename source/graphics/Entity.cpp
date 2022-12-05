#include "../../headers/graphics/Entity.hpp"

/// <summary>
/// Create an entity, with a texture to render.
/// </summary>
/// <param name="texture">The texture that represent the Entity</param>
Entity::Entity(const sf::Texture& texture)
{
	this->texture = texture;
	this->sprite.setTexture(this->texture);
}

Entity::~Entity()
{
}

/// <summary>
/// Get the position of the entity.
/// </summary>
/// <returns></returns>
sf::Vector2f Entity::getPosition()
{
	return this->sprite.getPosition();
}

/// <summary>
/// Move the sprite by the given x and y pixels.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void Entity::move(float x, float y)
{
	this->sprite.move(x, y);
}

/// <summary>
/// Move the sprite by the given vector.
/// </summary>
/// <param name="movement"></param>
void Entity::move(sf::Vector2f movement)
{
	this->sprite.move(movement);
}

/// <summary>
/// Set the sprite's position to the given x and y pixels.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void Entity::setPosition(float x, float y)
{
	this->sprite.setPosition(x, y);
}

/// <summary>
/// Set the sprite's position to the given vector.
/// </summary>
/// <param name="position">New position</param>
void Entity::setPosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

/// <summary>
/// Set the entity texture.
/// </summary>
/// <param name="texture">New texture</param>
void Entity::setTexture(const sf::Texture& texture)
{
	this->texture = texture;
	this->sprite.setTexture(this->texture);
}

/// <summary>
/// Sets the texture rect.
/// </summary>
/// <param name="rect">New texture rect</param>
void Entity::setTextureRect(sf::IntRect rect)
{
	this->sprite.setTextureRect(rect);
}

/// <summary>
/// Set the sprite's scale.
/// </summary>
/// <param name="x">New x scale</param>
/// <param name="y">New y scale</param>
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

// Draws the entity onto the target.
void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}