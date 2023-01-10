#include <iostream>
#include <TYDEngine/Graphics.hpp>
#include <TYDEngine/Inputs.hpp>
#include "Const.hpp"
#include "src/Room.hpp"

int main()
{
	// Create a window
	Window *window = new Window("LightHunters", 1280, 720, sf::Style::Close);

	// Input manager
	Input input(window->getWindow());
	input.setKeyToBinding(sf::Keyboard::Escape, Bindings::Escape);
	input.setKeyToBinding(sf::Keyboard::Space, Bindings::Inventory);
	
	sf::Texture m_background_texture;
	m_background_texture.loadFromFile("assets/textures/background.png");
	sf::Sprite background(m_background_texture);
	window->addDrawable(&background, LAYER_DOWN);


	window->switchInMainMenu();
	// Anmated entity test
	sf::Texture texture;
	texture.loadFromFile("assets/textures/bunny_animations.png");
	AnimatedEntity test(texture, sf::Vector2f(68, 68), 4, 10);
	test.setPosition(sf::Vector2f(100, 100));
	window->addDrawable(&test, LAYER_BEINGS);

	WidgetSlider* w = new WidgetSlider(sf::Vector2f(10, 10), sf::Vector2f(100, 20), 0.5F);
	window->addDrawable(w, 9);
	
	

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
				case Bindings::Escape:
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