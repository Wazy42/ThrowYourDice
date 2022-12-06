#include "headers/graphics/ui/WidgetButton.h"


WidgetButton::WidgetButton()
	: m_callback( 0 ), m_callbackParam( 0 )
{

}

void WidgetButton::draw(sf::RenderTarget& rt, sf::RenderStates states) const
{

}

void WidgetButton::setCallback( void(*c)(int), int param )
{
	m_callback = c;
	m_callbackParam = param;
}
