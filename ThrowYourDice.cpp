#include <iostream>
#include "headers/graphics/Window.hpp"
#include "headers/graphics/Entity.hpp"
#include "headers/graphics/BText.hpp"
#include "headers/settings/Input.hpp"

int main()
{
	// Create a window
	Window* window = new Window("Throw Your Dice");
	
	// Test entity
	sf::Texture cat;
	cat.loadFromFile("assets/textures/cat.jpg");
	Entity catTest(cat);
	catTest.setPosition(100, 100);
	catTest.setScale(0.5);
	window->addDrawable(&catTest);

	// Test text
	sf::Font font;
	font.loadFromFile("assets/fonts/spinwerad.ttf");
	BText testText("Hello World!", font, 50, sf::Color::Red);
	testText.setPosition(100, 700);
	testText.setBackgroundMargin(10);
	testText.setBackgroundColor(sf::Color::Blue);
	window->addDrawable(&testText);

	BText test2text("Copy of Hello world", &testText);
	test2text.setPosition(100, 800);
	window->addDrawable(&test2text);

	// Input manager
	Input input(window->getWindow());
	input.setKeyToBinding(sf::Keyboard::Escape, input.escape);
	input.setKeyToBinding(sf::Keyboard::Space, input.inventory);
	
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
					test2text.setString("Escape pressed");
					break;
				case Input::Bindings::inventory:
					test2text.setString("Inventory pressed");
					break;
				default:
					break;
				}
			}
		}
		window->render();
	}
	
	delete window;
	return 0;
}