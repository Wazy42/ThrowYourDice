#include <iostream>
#include "headers/graphics/Window.hpp"
#include "headers/graphics/Entity.hpp"
#include "headers/graphics/AnimatedEntity.hpp"
#include "headers/graphics/BText.hpp"
#include "headers/settings/Input.hpp"

int main()
{
    // Create a window
    Window *window = new Window("Throw Your Dice");

    // Test entity
    sf::Texture bunny;
    // cat.loadFromFile("assets/textures/cat.jpg");
    // Entity bunnyAnim(bunny);
    AnimatedEntity bunnyAnim(bunny, std::vector<sf::IntRect>({sf::IntRect(0, 0, 16, 16)} ) );
    // bunnyAnim.Animate("assets/textures/bunny_animations.png", 0);
    bunnyAnim.setScale(4, 4);
    // catTest.setPosition(100, 100);
    // catTest.setScale(0.5);
    window->addDrawable(&bunnyAnim);

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
    input.setKeyToBinding(sf::Keyboard::Escape, Input::escape);
    input.setKeyToBinding(sf::Keyboard::Space, Input::inventory);
    input.setKeyToBinding(sf::Keyboard::Z, Input::up);
    input.setKeyToBinding(sf::Keyboard::S, Input::down);
    input.setKeyToBinding(sf::Keyboard::Q, Input::left);
    input.setKeyToBinding(sf::Keyboard::D, Input::right);

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
                case Input::Bindings::up:
                    std::cout << "up" << std::endl;
                    bunnyAnim.move(0, -1);
                    bunnyAnim.Animate("assets/textures/slime_pink.png", 16);
                    //orientation
                    break;
                case Input::Bindings::down:
                    std::cout << "down" << std::endl;
                    bunnyAnim.move(0, 1);
                    bunnyAnim.Animate("assets/textures/slime_pink.png", 0);
                    //orientation
                    break;
                case Input::Bindings::left:
                    std::cout << "left" << std::endl;
                    bunnyAnim.move(-1, 0);
                    bunnyAnim.Animate("assets/textures/slime_pink.png", 48);
                    //orientation
                    break;
                case Input::Bindings::right:
                    std::cout << "right" << std::endl;
                    bunnyAnim.move(1, 0);
                    bunnyAnim.Animate("assets/textures/slime_pink.png", 32);
                    //orientation
                    break;

                case Input::Bindings::escape:
                    test2text.setString("Escape key pressed");
                    window->close();
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