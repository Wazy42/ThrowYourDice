#include "../../headers/graphics/BText.hpp"

/// <summary>
/// Create a new BText object.
/// </summary>
/// <param name="string">The string that will be displayed</param>
/// <param name="font">Font used to display the text</param>
/// <param name="size">Size of the text</param>
/// <param name="color">Color of the text</param>
BText::BText(sf::String string, sf::Font& font, int size, sf::Color color)
	: sf::Text(string, font, size)
{
	this->background.setSize(sf::Vector2f(sf::Text::getLocalBounds().width, sf::Text::getLocalBounds().height));
	sf::Text::setFillColor(color);
}

/// <summary>
/// Create a new BText object.
/// </summary>
/// <param name="string">The string that will be displayed</param>
/// <param name="model">The model from where all settings will be copied (except from the x and y position)</param>
BText::BText(sf::String string, BText* model)
{
	this->copySettings(model);
	this->setString(string);
}

BText::~BText()
{
}

/// <summary>
/// Copy all settings from another BText.
/// </summary>
/// <param name="model">Model for the settings</param>
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


/// <summary>
/// Change the string displayed and update the background size.
/// </summary>
/// <param name="string">New string</param>
void BText::setString(sf::String string)
{
	sf::Text::setString(string);
	this->background.setSize(sf::Vector2f(sf::Text::getLocalBounds().width, sf::Text::getLocalBounds().height));
}

/// <summary>
/// Change the font used to display the text and update the background size.
/// </summary>
/// <param name="font">New font</param>
void BText::setFont(sf::Font& font)
{
	sf::Text::setFont(font);
	this->background.setSize(sf::Vector2f(sf::Text::getLocalBounds().width, sf::Text::getLocalBounds().height));
}


/// <summary>
/// Change the size of the text and update the background size.
/// </summary>
/// <param name="size">New size</param>
void BText::setCharacterSize(int size)
{
	sf::Text::setCharacterSize(size);
	this->background.setSize(sf::Vector2f(sf::Text::getLocalBounds().width, sf::Text::getLocalBounds().height));
}

/// <summary>
/// Move the object by x and y pixels.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void BText::move(float x, float y)
{
	sf::Text::move(x, y);
	this->background.move(x, y);
}

/// <summary>
/// Move the object by x and y pixels.
/// </summary>
/// <param name="movement"></param>
void BText::move(const sf::Vector2f& movement)
{
	sf::Text::setPosition(movement);
	this->background.move(movement);
}

/// <summary>
/// Set the position of the object to x and y pixels.
/// </summary>
/// <param name="x">New x position of the BText</param>
/// <param name="y">New x position of the BText</param>
void BText::setPosition(float x, float y)
{
	sf::Text::setPosition(x, y);
	this->background.setPosition(x, y);
}

/// <summary>
/// Set the position of the object to x and y pixels.
/// </summary>
/// <param name="position">New position of the BText</param>
void BText::setPosition(const sf::Vector2f& position)
{
	sf::Text::setPosition(position);
	this->background.setPosition(position);
}


/// <summary>
/// Set the background color.
/// </summary>
/// <param name="color">New color of the background</param>
void BText::setBackgroundColor(const sf::Color& color)
{
	this->background.setFillColor(color);
	this->background.setOutlineColor(color);
}

/// <summary>
/// Get the background color.
/// </summary>
/// <returns>The background color</returns>
sf::Color BText::getBackgroundColor() const
{
	return this->background.getFillColor();
}

/// <summary>
/// Set the margin of the background around the text.
/// </summary>
/// <param name="margin">New margin</param>
void BText::setBackgroundMargin(float margin)
{
	this->background.setOutlineThickness(margin);
}

/// <summary>
/// Get the margin of the background around the text.
/// </summary>
/// <returns></returns>
float BText::getBackgroundMargin() const
{
	return this->background.getOutlineThickness();
}

// Draw the object onto the target.
void BText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->background, states);
	target.draw((sf::Text)*this, states);
}