#include "../../headers/graphics/Window.hpp"

Window::Window(const char* title, int width, int height)
{
	m_Window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
}

Window::~Window()
{
	delete m_Window;
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
	this->m_Window->close();
}

void Window::render()
{
	m_Window->clear();
	
	for (int i = 0; i < this->listToRender.size(); i++)
	{
		m_Window->draw(this->listToRender[i]->getSprite());
	}
	
	m_Window->display();
}

void Window::addRenderEntity(Entity* entity)
{
	listToRender.push_back(entity);
}

void Window::remRenderEntity(Entity* entity)
{
	for (int i = 0; i < listToRender.size(); i++)
	{
		if (listToRender[i] == entity)
		{
			listToRender.erase(listToRender.begin() + i);
		}
	}
}
