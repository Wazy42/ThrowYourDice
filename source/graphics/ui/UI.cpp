#include "headers/graphics/ui/UI.h"

#include "headers/graphics/Window.hpp"
#include "headers/graphics/ui/WidgetButton.h"


UI::UI( Window* w )
	: m_window( w )
{

}

UI::~UI()
{
	
}

void UI::addWidget(sf::Drawable& d)
{

}

void UI::addButton(WidgetButton* b)
{
	m_buttons.push_back(b);
}

void UI::handleEvent(const sf::Event& e)
{
	switch (e.type) {
	case sf::Event::MouseButtonPressed:
		{
			WidgetButton* btn = this->getHoveredButton();
			if (btn && btn->m_callback) {
				(btn->m_callback)(btn->m_callbackParam);
			}
		}
		break;
	}
}

WidgetButton* UI::getHoveredButton() const
{
	sf::Vector2i mousePos = sf::Mouse::getPosition() - m_window->getWindow()->getPosition();

	for (WidgetButton* btn : m_buttons) {
		const sf::Vector2f& b = btn->getPosition();
		sf::Vector2f e = b + btn->getSize();

		if (mousePos.x >= b.x && mousePos.x <= e.x && mousePos.y >= b.y && mousePos.y <= e.y) {
			return btn;
		}
	}
	return 0;
}
