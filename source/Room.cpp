#include "headers/Room.hpp"

Room::Room(int width, int height)
{
	this->regenerate(width, height);
}

Room::~Room()
{
}

void Room::regenerate(int width, int height)
{
	// You want to generate the obstacles first, into the obstacle layer
	m_map.clear();
	m_map.resize(1);
	for (auto layer : m_map)
	{
		layer.resize(height);
		for (auto row : layer)
		{
			row.resize(width);
			for (auto tile : row)
			{
				tile = 1;
			}
		}
	}
}