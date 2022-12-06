#pragma once

#include <sfml/Graphics.hpp>


class WidgetButton : public sf::Sprite
{
	friend class UI;

public:

	WidgetButton();

	virtual void draw( sf::RenderTarget& rt, sf::RenderStates states) const override;

	sf::Text& getLabel() { return m_label; }

	void setCallback( void(*c)(int), int param );



private:

	sf::Text m_label;

	void (*m_callback)(int param);
	int m_callbackParam;
};
