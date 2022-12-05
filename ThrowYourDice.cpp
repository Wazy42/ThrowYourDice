#include <iostream>
#include "headers/graphics/Window.hpp"
#include "headers/graphics/Entity.hpp"
#include "headers/graphics/BText.hpp"
#include "headers/settings/Input.hpp"
#include "headers/Room.hpp"
#include "headers/Player.hpp"

int main()
{
	// Create a window
	Window* window = new Window("Throw Your Dice");

	// Input manager
	Input input(window->getWindow());
	input.setKeyToBinding(sf::Keyboard::Escape, input.escape);
	input.setKeyToBinding(sf::Keyboard::Space, input.inventory);

	// Room test 
	Room room(20, 20, 32);
	window->addDrawable(&room);

	// player Test
	sf::Texture cat;
	cat.loadFromFile("assets/textures/cat.jpg");
	Player player(cat);
	player.setTileSize(32);
	
	window->addDrawable(&player);


	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				switch (input.getKeyBinding(event.key.code))
				{
				default:
					break;
				}
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				player.setCoordinates(input.getMouseCoordinates().x / 32, input.getMouseCoordinates().y / 32);
			}
		}
		window->render();
	}
	
	delete window;
	return 0;
}