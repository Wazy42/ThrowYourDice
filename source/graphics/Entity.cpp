#include "headers/graphics/Entity.hpp"

Entity::Entity(const sf::Texture &texture)
{
    this->m_texture = texture;
    this->m_sprite.setTexture(texture);
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

sf::Vector2f Entity::getCoordinates()
{
	return this->m_coordinates;
}

void Entity::setCoordinates(sf::Vector2f coordinates)
{
	this->m_coordinates = coordinates;
}

void Entity::setCoordinates(float x, float y)
{
	this->m_coordinates = sf::Vector2f(x, y);
}

void Entity::setTexture(const sf::Texture& texture)
{
    this->m_texture = texture;
    this->m_sprite.setTexture(texture);
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

void Entity::calculateOrigin()
{
	m_sprite.setOrigin(
		(m_sprite.getGlobalBounds().width - SIZE_TILE) / 2,
		m_sprite.getGlobalBounds().height - SIZE_TILE
	);
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}