#include <iostream>
#include "headers/graphics/Window.hpp"

int main()
{
	Window* window = new Window("Throw Your Dice");
	
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
		}
		window->render();
	}
	
	delete window;
	return 0;
}