#include "headers/Player.hpp"

Player::Player(sf::Texture& texture) 
	: Entity(texture)
{
}

Player::~Player()
{
}

sf::Vector2f Player::getCoordinates()
{
	return this->m_coordinates;
}

void Player::setCoordinates(sf::Vector2f coordinates)
{
	this->m_coordinates = coordinates;
	this->setPosition(coordinates.x * this->m_tile_size, coordinates.y * this->m_tile_size);
}

void Player::setCoordinates(float x, float y)
{
	this->m_coordinates = sf::Vector2f(x, y);
	this->setPosition(x * this->m_tile_size, y * this->m_tile_size);
}

void Player::setTileSize(int tile_size)
{
	this->m_tile_size = tile_size;
	this->setScale(tile_size / this->m_sprite.getLocalBounds().width, tile_size / this->m_sprite.getLocalBounds().height);
}
