#include "headers/graphics/Window.hpp"

Window::Window(const char* title, int width, int height, int style)
{
	m_Window = new sf::RenderWindow(sf::VideoMode(width, height), title, style);
}

Window::~Window()
{
	delete m_Window;
}

sf::RenderWindow* Window::getWindow()
{
	return m_Window;
}

sf::Vector2u Window::getSize()
{
	return m_Window->getSize();
}

bool Window::isOpen() const
{
	return m_Window->isOpen();
}

bool Window::pollEvent(sf::Event& event)
{
	return m_Window->pollEvent(event);
}

void Window::close()
{
	m_Window->close();
}

void Window::render()
{
	m_Window->clear();
	
	for (int layer = LAYER_DOWN; layer < LAYER_UP; layer++)
	{
		for (std::pair<sf::Drawable*, int> pair : m_listToRender)
		{
			if (pair.second == layer)
			{
				m_Window->draw(*pair.first);
				if (layer == LAYER_ANIMATIONS)
				{
					// Change animations here
				}
			}
		}
	}
	
	m_Window->display();
}

void Window::addDrawable(sf::Drawable* drawable, int layer)
{
	m_listToRender.insert(std::pair<sf::Drawable*, int>(drawable, layer));
}

void Window::remDrawable(sf::Drawable* drawable)
{
	m_listToRender.erase(drawable);
}
