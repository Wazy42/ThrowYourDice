#pragma once
#include <SFML/Graphics.hpp>

class Room : public sf::Drawable
{
public:
	Room(int w, int h, int tile_size);
	~Room();

protected:
	int m_width, m_height;
	int m_tile_size;
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};
