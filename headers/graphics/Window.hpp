#pragma once

#include "Entity.hpp"

#include <SFML/Graphics.hpp>
#include <vector>

class Window
{
public:
	// Constructor
	Window(const char* t, int w = sf::VideoMode::getDesktopMode().width, int h = sf::VideoMode::getDesktopMode().height);
	~Window();
	
	// Game loop
	bool isOpen() const;
	bool pollEvent(sf::Event&);
	void close();
	void render();

	// Entity management
	void addRenderEntity(Entity*);
	void remRenderEntity(Entity*);
	
private:
	sf::RenderWindow* m_Window;
	std::vector<Entity*> listToRender;
};

