#include "headers/graphics/BText.hpp"

BText::BText(sf::String string, sf::Font& font, int size, sf::Color color)
	: sf::Text(string, font, size)
{
	this->background.setSize(sf::Vector2f(sf::Text::getLocalBounds().width, sf::Text::getLocalBounds().height));
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
	this->background.setFillColor(model->background.getFillColor());
	this->background.setOutlineColor(model->background.getFillColor());
	this->background.setOutlineThickness(model->background.getOutlineThickness());
}

void BText::setString(sf::String string)
{
	sf::Text::setString(string);
	this->background.setSize(sf::Vector2f(sf::Text::getLocalBounds().width, sf::Text::getLocalBounds().height));
}

void BText::setFont(sf::Font& font)
{
	sf::Text::setFont(font);
	this->background.setSize(sf::Vector2f(sf::Text::getLocalBounds().width, sf::Text::getLocalBounds().height));
}

void BText::setCharacterSize(int size)
{
	sf::Text::setCharacterSize(size);
	this->background.setSize(sf::Vector2f(sf::Text::getLocalBounds().width, sf::Text::getLocalBounds().height));
}

void BText::move(float x, float y)
{
	sf::Text::move(x, y);
	this->background.move(x, y);
}

void BText::move(const sf::Vector2f& movement)
{
	sf::Text::setPosition(movement);
	this->background.move(movement);
}

void BText::setPosition(float x, float y)
{
	sf::Text::setPosition(x, y);
	this->background.setPosition(x, y);
}

void BText::setPosition(const sf::Vector2f& position)
{
	sf::Text::setPosition(position);
	this->background.setPosition(position);
}

void BText::setBackgroundColor(const sf::Color& color)
{
	this->background.setFillColor(color);
	this->background.setOutlineColor(color);
}

sf::Color BText::getBackgroundColor() const
{
	return this->background.getFillColor();
}

void BText::setBackgroundMargin(float margin)
{
	this->background.setOutlineThickness(margin);
}

float BText::getBackgroundMargin() const
{
	return this->background.getOutlineThickness();
}

void BText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->background, states);
	target.draw((sf::Text)*this, states);
}