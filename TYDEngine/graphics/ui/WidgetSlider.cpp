#include "WidgetSlider.h"



WidgetSlider::WidgetSlider(const sf::Vector2f& pos, const sf::Vector2f& size, float initialPercentage)
	: m_dragged(false)
{
	m_background.setSize(size);
	m_thumb.setSize(sf::Vector2f(10, size.y));
	this->setPercentage(initialPercentage);

	m_thumb.setFillColor(sf::Color(0, 255, 0));
	m_background.setFillColor(sf::Color::White);

	this->setPosition(pos);
}

void WidgetSlider::setPosition(const sf::Vector2f& v)
{
	m_background.setPosition(v);

	// Update thumb position.
	this->setPercentage(m_percentage);
}

void WidgetSlider::setPercentage(float f)
{
	// Clamp percentage value.
	if (f < 0) f = 0;
	if (f > 1) f = 1;

	m_percentage = f;

	float posX = m_background.getPosition().x + m_percentage * m_background.getLocalBounds().width;
	m_thumb.setPosition(posX, m_background.getPosition().y);
}

void WidgetSlider::handleEvent(const sf::Event& e, const sf::Window& w)
{
	switch (e.type)
	{
	case sf::Event::MouseButtonPressed:
		{
			// If mouse hovering the slider's thumb, set as dragged.
			sf::Vector2i mousePos = sf::Mouse::getPosition(w);
			if (m_thumb.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				m_dragged = true;
			}
		}
		break;

	case sf::Event::MouseButtonReleased:
		{
			m_dragged = false;
		}
		break;

	case sf::Event::MouseMoved:
		{
			if (m_dragged) {
				float p = (e.mouseMove.x - m_background.getPosition().x) / m_background.getGlobalBounds().width;
				this->setPercentage(p);
			}
		}
		break;
	}
}

void WidgetSlider::draw(sf::RenderTarget& rt, sf::RenderStates s) const
{
	rt.draw(m_background, s);
	rt.draw(m_thumb, s);
}
