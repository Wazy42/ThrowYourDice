#pragma once

#include <SFML/Graphics.hpp>

class BText : public sf::Text
{
public:
	/// <summary>
	/// Create a new BText object.
	/// </summary>
	/// <param name="string">The string that will be displayed</param>
	/// <param name="font">Font used to display the text</param>
	/// <param name="size">Size of the text</param>
	/// <param name="color">Color of the text</param>
	BText(sf::String string, sf::Font& font, int size = 30, sf::Color = sf::Color::White);
	
	/// <summary>
	/// Create a new BText object.
	/// </summary>
	/// <param name="string">The string that will be displayed</param>
	/// <param name="model">The model from where all settings will be copied (except from the x and y position)</param>
	BText(sf::String string, BText* model);
	~BText();

	/// <summary>
	/// Copy all settings from another BText.
	/// </summary>
	/// <param name="model">Model for the settings</param>
	void copySettings(BText*);

	// Text
	
	/// <summary>
	/// Change the string displayed and update the background size.
	/// </summary>
	/// <param name="string">New string</param>
	void setString(sf::String);

	/// <summary>
	/// Change the font used to display the text and update the background size.
	/// </summary>
	/// <param name="font">New font</param>
	void setFont(sf::Font&);

	/// <summary>
	/// Change the size of the text and update the background size.
	/// </summary>
	/// <param name="size">New size</param>
	void setCharacterSize(int);

	// Position
	
	/// <summary>
	/// Move the object by x and y pixels.
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void move(float x, float y);

	/// <summary>
	/// Move the object by x and y pixels.
	/// </summary>
	/// <param name="movement"></param>
	void move(const sf::Vector2f&);
	
	/// <summary>
	/// Set the position of the object to x and y pixels.
	/// </summary>
	/// <param name="x">New x position of the BText</param>
	/// <param name="y">New x position of the BText</param>
	void setPosition(float x, float y);

	/// <summary>
	/// Set the position of the object to x and y pixels.
	/// </summary>
	/// <param name="position">New position of the BText</param>
	void setPosition(const sf::Vector2f&);
	
	// Background

	/// <summary>
	/// Set the background color.
	/// </summary>
	/// <param name="color">New color of the background</param>
	void setBackgroundColor(const sf::Color&);

	/// <summary>
	/// Get the background color.
	/// </summary>
	/// <returns>The background color</returns>
	sf::Color getBackgroundColor() const;

	/// <summary>
	/// Set the margin of the background around the text.
	/// </summary>
	/// <param name="margin">New margin</param>
	void setBackgroundMargin(float);

	/// <summary>
	/// Get the margin of the background around the text.
	/// </summary>
	/// <returns></returns>
	float getBackgroundMargin() const;

protected:
	sf::RectangleShape m_background; // Rectangle behind the text
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};