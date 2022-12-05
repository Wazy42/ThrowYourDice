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
	
	for (sf::Drawable* d : listToRender)
	{
		m_Window->draw(*d);
	}
	
	m_Window->display();
}

void Window::addDrawable(sf::Drawable* drawable)
{
	listToRender.push_back(drawable);
}

void Window::remDrawable(sf::Drawable* drawable)
{
	listToRender.erase(std::remove(listToRender.begin(), listToRender.end(), drawable), listToRender.end());
}
