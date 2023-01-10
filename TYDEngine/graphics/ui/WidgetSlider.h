#pragma once

#include <SFML/Graphics.hpp>


class WidgetSlider : public sf::Drawable
{
	friend class UI;

public:

	WidgetSlider(const sf::Vector2f& pos, const sf::Vector2f& size, float initialPercentage);

	void setPosition(const sf::Vector2f& v);

	float getPercentage() const { return m_percentage; }
	void setPercentage(float f);

protected:

public:void handleEvent(const sf::Event& e, const sf::Window& w);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;



private:

		/// Background sprite.
	sf::RectangleShape m_background;

		/// Draggable part of the slider.
	sf::RectangleShape m_thumb;

		/// Value between 0.0 and 1.0 determined by the thumb's position.
	float m_percentage;

	bool m_dragged;
};
