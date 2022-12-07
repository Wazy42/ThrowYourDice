#include "WidgetButton.h"


WidgetButton::WidgetButton()
	: m_callback( 0 ), m_callbackParam( 0 )
{

}

const sf::Vector2f& WidgetButton::getPosition() const
{
	return m_sprite.getPosition();
}

void WidgetButton::setPosition(float x, float y)
{
	m_sprite.setPosition(x, y);
}

sf::Vector2f WidgetButton::getSize() const
{
	return sf::Vector2f( m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height );
}

void WidgetButton::setSize(float sizeX, float sizeY)
{
	sf::Vector2u ts = m_sprite.getTexture()->getSize();
	m_sprite.setScale(sizeX / ts.x, sizeY / ts.y);
}

void WidgetButton::setBackgroundTexture(sf::Texture& t)
{
	m_sprite.setTexture(t);
}

void WidgetButton::setLabelText(const char* text)
{
	this->m_label.setString(text);
}

void WidgetButton::setCallback( void(*c)(int), int param )
{
	m_callback = c;
	m_callbackParam = param;
}

void WidgetButton::draw(sf::RenderTarget& rt, sf::RenderStates states) const
{
	rt.draw(this->m_sprite, states);
	rt.draw(this->m_label, states);
}
