#include "headers/Room.hpp"

Room::Room(int w, int h, int tile_size) {
	this->m_width = w;
	this->m_height = h;
	this->m_tile_size = tile_size;
}

Room::~Room()
{
}

void Room::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++) {
			sf::RectangleShape tile;
			tile.setPosition((float)x * m_tile_size, (float)y * m_tile_size);
			tile.setSize(sf::Vector2f((float)m_tile_size, (float)m_tile_size));
			if ((x + y) % 2 == 0)
				tile.setFillColor(sf::Color::Black);
			else
				tile.setFillColor(sf::Color::White);

			target.draw(tile, states);
		}
	}
}