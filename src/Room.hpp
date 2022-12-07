#pragma once
#include <SFML/Graphics.hpp>
#include "Const.hpp"
#include "graphics/Entity.hpp"

/// <summary>
/// Room is a set of tiles
/// </summary>
class Room
{
public:
	Room(int w, int h);
	~Room();

	// TODO: Procedural generation of the room
	void regenerate(int w, int h);

protected:
	std::vector<std::vector<std::vector<int>>> m_map;
};
