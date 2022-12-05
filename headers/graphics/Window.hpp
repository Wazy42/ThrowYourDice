#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Window
{
public:
	// Constructor
	Window(const char* t, int w = sf::VideoMode::getDesktopMode().width, int h = sf::VideoMode::getDesktopMode().height, int s = sf::Style::Fullscreen);
	~Window();
	
	// Window
	sf::RenderWindow* getWindow();
	sf::Vector2u getSize();

	// Game loop
	bool isOpen() const;
	bool pollEvent(sf::Event&);
	void close();
	void render();

	// Entity management
	void addDrawable(sf::Drawable*);
	void remDrawable(sf::Drawable*);
	
private:
	sf::RenderWindow* m_Window;
	std::vector<sf::Drawable*> listToRender;
};

