#include <iostream>
#include "Const.hpp"
#include "headers/graphics/Window.hpp"
#include "headers/graphics/Entity.hpp"
#include "headers/graphics/AnimatedEntity.hpp"
#include "headers/graphics/BText.hpp"
#include "headers/settings/Input.hpp"
#include "headers/Room.hpp"

int main()
{
    // Create a window
    Window *window = new Window("Throw Your Dice");

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
		}
		window->render();
	}
	
	delete window;
	return 0;
}