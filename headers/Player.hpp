#pragma once
#include "headers/graphics/Entity.hpp"

class Player : public Entity
{
public:
	Player(sf::Texture& texture);
	~Player();
	
	sf::Vector2f getCoordinates();

	void setCoordinates(sf::Vector2f);
	void setCoordinates(float x, float y);
	void setTileSize(int s);

protected:
	sf::Vector2f m_coordinates;
	int m_tile_size;
};