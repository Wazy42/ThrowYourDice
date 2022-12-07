#include "Const.hpp"
#include "src/graphics/Window.hpp"
#include "src/graphics/AnimatedEntity.hpp"

Window::Window(const char* title, int width, int height, int style)
{
	m_Window = new sf::RenderWindow(sf::VideoMode(width, height), title, style);
    m_Window->setFramerateLimit(FPS);
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
		auto it = m_listToRender.find(layer);
		if (it != m_listToRender.end()) {

			for (sf::Drawable* d : it->second) {

				// Update animations
				if (layer == LAYER_ANIMATIONS_DOWN || layer == LAYER_BEINGS || layer == LAYER_ANIMATIONS_UP) {
					((AnimatedEntity*) d)->update();
				}

				m_Window->draw(*d);
			}
		}
	}
	
	m_Window->display();
}

void Window::addDrawable(sf::Drawable* drawable, int layer)
{
	// Find layer.
	auto it = m_listToRender.find(layer);

	if (it == m_listToRender.end()) {

		// Create new layer.
		auto n = m_listToRender.insert(std::pair<int, std::vector<sf::Drawable*>>(layer, std::vector<sf::Drawable*>()));
		n.first->second.push_back(drawable);
	}
	else {

		it->second.push_back( drawable );
	}
}

void Window::remDrawable(sf::Drawable* drawable)
{
	for (int layer = LAYER_DOWN; layer < LAYER_UP; ++layer) {

		auto it = m_listToRender.find(layer);
		std::vector<sf::Drawable*>& d = it->second;

		auto elemit = std::find(d.begin(), d.end(), drawable);
		if (elemit != d.end()) {
			d.erase(elemit);
		}
	}
}