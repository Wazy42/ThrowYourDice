#pragma once

#include <SFML/Graphics.hpp>
#include "Const.hpp"
#include <vector>

class Window
{
public:
	/// <summary>
	/// Create a new window.
	/// </summary>
	/// <param name="title">Title of the window</param>
	/// <param name="width">Width of the window (default: width of the screen)</param>
	/// <param name="height">Height of the window (default: haight of the screen)</param>
	/// <param name="style">sf::Style (default: Fullscreen)</param>
	Window(const char* title, int width = sf::VideoMode::getDesktopMode().width, int height = sf::VideoMode::getDesktopMode().height, int style = sf::Style::Fullscreen);
	~Window();

	/// <summary>
	/// Return the window object.
	/// </summary>
	/// <returns></returns>
	sf::RenderWindow* getWindow();
	
	/// <summary>
	/// Return the size of the window.
	/// </summary>
	/// <returns>Width and height in a Vector2u</returns>
	sf::Vector2u getSize();
	
	/// <summary>
	/// Check if the window is open.
	/// </summary>
	/// <returns>boolean</returns>
	bool isOpen() const;
	
	/// <summary>
	/// Pop the event on top of the event queue, if any, and return it.
	/// </summary>
	/// <param name="event"></param>
	/// <returns>boolean: value of event has been changed</returns>
	bool pollEvent(sf::Event& event);
	
	/// <summary>
	/// Close the window.
	/// </summary>
	void close();
	
	/// <summary>
	/// Render all elements that should be displayed on the window.
	/// </summary>
	void render();
	
	/// <summary>
	/// Add a drawable object that should be displayed on the window.
	/// Note that layers 3, 5 and 7 are reserved for animations.
	/// </summary>
	/// <param name="drawable">New drawable object</param>
	/// <param name="layer">Layer of the object (0 = background, 9 = foreground)</param>
	void addDrawable(sf::Drawable* drawable, int layer);
	
	/// <summary>
	/// Remove a drawable object from the list of displayed drawable objects.
	/// </summary>
	/// <param name="drawable">Drawable object to remove</param>
	void remDrawable(sf::Drawable* drawable);
	
private:

	sf::RenderWindow* m_Window;
	std::map<int, std::vector<sf::Drawable*>> m_listToRender;
};

