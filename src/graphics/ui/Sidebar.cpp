#include "src/graphics/ui/Sidebar.hpp"

Sidebar::Sidebar(const sf::Vector2f& pos, const sf::Vector2f& size)
{
	m_background.setSize(size);
	m_background.setFillColor(sf::Color::Red);
    
	this->setPosition(pos);
}

const sf::Vector2f& Sidebar::getPosition() const
{
	return m_background.getPosition();
}

void Sidebar::setPosition(sf::Vector2f pos)
{
	m_background.setPosition(pos);
}

sf::Vector2f Sidebar::getSize() const
{
	return sf::Vector2f(m_background.getGlobalBounds().width, m_background.getGlobalBounds().height);
}

void Sidebar::setSize(float sizeX, float sizeY)
{
	sf::Vector2u ts = m_background.getTexture()->getSize();
	m_background.setScale(sizeX / ts.x, sizeY / ts.y);
}

//void Sidebar::setBackgroundTexture(sf::Texture& t)
//{
//	m_background.setTexture(t);
//}

void Sidebar::setLabelText(const char* text)
{
	this->m_label.setString(text);
}


void Sidebar::draw(sf::RenderTarget& rt, sf::RenderStates states) const
{
	rt.draw(this->m_background, states);
	rt.draw(this->m_label, states);
}