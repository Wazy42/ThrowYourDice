#include "BText.hpp"

BText::BText(sf::String string, sf::Font& font, int size, sf::Color color)
	: sf::Text(string, font, size)
{
	this->m_background.setSize(sf::Vector2f(sf::Text::getLocalBounds().width, sf::Text::getLocalBounds().height));
	sf::Text::setFillColor(color);
}

BText::BText(sf::String string, BText* model)
{
	this->copySettings(model);
	this->setString(string);
}

BText::~BText()
{
}

void BText::copySettings(BText* model)
{
	sf::Text::setFont(*model->getFont());
	sf::Text::setCharacterSize(model->getCharacterSize());
	sf::Text::setFillColor(model->getFillColor());
	sf::Text::setOutlineColor(model->getOutlineColor());
	sf::Text::setOutlineThickness(model->getOutlineThickness());
	this->m_background.setFillColor(model->m_background.getFillColor());
	this->m_background.setOutlineColor(model->m_background.getFillColor());
	this->m_background.setOutlineThickness(model->m_background.getOutlineThickness());
}

void BText::setString(sf::String string)
{
	sf::Text::setString(string);
	this->m_background.setSize(sf::Vector2f(sf::Text::getLocalBounds().width, sf::Text::getLocalBounds().height));
}

void BText::setFont(sf::Font& font)
{
	sf::Text::setFont(font);
	this->m_background.setSize(sf::Vector2f(sf::Text::getLocalBounds().width, sf::Text::getLocalBounds().height));
}

void BText::setCharacterSize(int size)
{
	sf::Text::setCharacterSize(size);
	this->m_background.setSize(sf::Vector2f(sf::Text::getLocalBounds().width, sf::Text::getLocalBounds().height));
}

void BText::move(float x, float y)
{
	sf::Text::move(x, y);
	this->m_background.move(x, y);
}

void BText::move(const sf::Vector2f& movement)
{
	sf::Text::setPosition(movement);
	this->m_background.move(movement);
}

void BText::setPosition(float x, float y)
{
	sf::Text::setPosition(x, y);
	this->m_background.setPosition(x, y);
}

void BText::setPosition(const sf::Vector2f& position)
{
	sf::Text::setPosition(position);
	this->m_background.setPosition(position);
}

void BText::setBackgroundColor(const sf::Color& color)
{
	this->m_background.setFillColor(color);
	this->m_background.setOutlineColor(color);
}

sf::Color BText::getBackgroundColor() const
{
	return this->m_background.getFillColor();
}

void BText::setBackgroundMargin(float margin)
{
	this->m_background.setOutlineThickness(margin);
}

float BText::getBackgroundMargin() const
{
	return this->m_background.getOutlineThickness();
}

void BText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->m_background, states);
	target.draw((sf::Text)*this, states);
}