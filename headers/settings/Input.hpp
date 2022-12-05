#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <array>

class Input
{
public:
	Input(sf::RenderWindow* w);
	~Input();
	
	// Possibles bindings
	enum Bindings {
		// Menu
		escape,
		inventory,
		map,
		skill_tree,
		// Movement
		movement,
		// Abilities
		ability_1,
		ability_2,
		ability_3,
		ability_4,
		ability_5,
		ability_6,
		// Other
		skip,
		DEBUG, // must be the last one, used to know the size of the array (not a real binding) 
	};

	bool setKeyToBinding(sf::Keyboard::Key k, Bindings b, bool s = true);
	Bindings getKeyBinding(sf::Keyboard::Key k);
	
private:
	sf::RenderWindow* m_window;
	std::vector<sf::Keyboard::Key> keyBindings;
};

