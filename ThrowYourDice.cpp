#include <iostream>
#include "Const.hpp"
#include "src/graphics/Window.hpp"
#include "src/graphics/Entity.hpp"
#include "src/graphics/AnimatedEntity.hpp"
#include "src/graphics/ui/BText.hpp"
#include "src/settings/Input.hpp"
#include "src/Room.hpp"

#include "src/graphics/ui/Sidebar.hpp"
#include "src/graphics/ui/WidgetSlider.h"

int main()
{
	// Create a window
	Window *window = new Window("Throw Your Dice", 1280, 720, sf::Style::Close);

	// Input manager
	Input input(window->getWindow());
	input.setKeyToBinding(sf::Keyboard::Escape, Input::escape);
	input.setKeyToBinding(sf::Keyboard::Space, Input::inventory);

	// Anmated entity test
	sf::Texture texture;
	texture.loadFromFile("assets/textures/bunny_animations.png");
	AnimatedEntity test(texture, sf::Vector2f(68, 68), 4, 10);
	test.setPosition(sf::Vector2f(100, 100));
	window->addDrawable(&test, LAYER_BEINGS);

	WidgetSlider* w = new WidgetSlider(sf::Vector2f(10, 10), sf::Vector2f(100, 20), 0.5F);
	window->addDrawable(w, 9);

	Sidebar* s = new Sidebar(BORDER_RIGHT, sf::Vector2f(100, 100));
	window->addDrawable(s, 9);
	std::cout << "Pos : " << s->getPosition().x << " " << s->getPosition().y << std::endl;

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
				case Input::Bindings::escape:
					window->close();
					break;
				default:
					break;
				}
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				// TODO: Add mouse input
			}

			w->handleEvent(event, *window->getWindow());
		}
		window->render();
	}
	
	delete window;
	return 0;
}