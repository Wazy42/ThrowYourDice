#include "../../headers/graphics/Window.hpp"

/// <summary>
/// Create a new window.
/// </summary>
/// <param name="title">Title of the window</param>
/// <param name="width">Width of the window (default: width of the screen)</param>
/// <param name="height">Height of the window (default: haight of the screen)</param>
/// <param name="style">sf::Style (default: Fullscreen)</param>
Window::Window(const char* title, int width, int height, int style)
{
	m_Window = new sf::RenderWindow(sf::VideoMode(width, height), title, style);
}

Window::~Window()
{
	delete m_Window;
}

/// <summary>
/// Return the window object.
/// </summary>
/// <returns></returns>
sf::RenderWindow* Window::getWindow()
{
	return m_Window;
}

/// <summary>
/// Return the size of the window.
/// </summary>
/// <returns>Width and height in a Vector2u</returns>
sf::Vector2u Window::getSize()
{
	return m_Window->getSize();
}

/// <summary>
/// Check if the window is open.
/// </summary>
/// <returns>boolean</returns>
bool Window::isOpen() const
{
	return m_Window->isOpen();
}

/// <summary>
/// Pop the event on top of the event queue, if any, and return it.
/// </summary>
/// <param name="event"></param>
/// <returns>boolean: value of event has been changed</returns>
bool Window::pollEvent(sf::Event& event)
{
	return m_Window->pollEvent(event);
}


/// <summary>
/// Close the window.
/// </summary>
void Window::close()
{
	m_Window->close();
}

/// <summary>
/// Render all elements that should be displayed on the window.
/// </summary>
void Window::render()
{
	m_Window->clear();
	
	for (sf::Drawable* d : listToRender)
	{
		m_Window->draw(*d);
	}
	
	m_Window->display();
}

/// <summary>
/// Add a drawable object that should be displayed on the window.
/// </summary>
/// <param name="drawable">New drawable object</param>
void Window::addDrawable(sf::Drawable* drawable)
{
	listToRender.push_back(drawable);
}

/// <summary>
/// Remove a drawable object from the list of displayed drawable objects.
/// </summary>
/// <param name="drawable">Drawable object to remove</param>
void Window::remDrawable(sf::Drawable* drawable)
{
	listToRender.erase(std::remove(listToRender.begin(), listToRender.end(), drawable), listToRender.end());
}
