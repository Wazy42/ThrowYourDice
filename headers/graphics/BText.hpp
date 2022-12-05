#pragma once

#include <SFML/Graphics.hpp>

class BText : public sf::Text
{
public:
	BText(sf::String string, sf::Font& font, int size = 30, sf::Color = sf::Color::White);
	BText(sf::String string, BText* model);
	~BText();
	
	void copySettings(BText*);

	// Text
	void setString(sf::String);
	void setFont(sf::Font&);
	void setCharacterSize(int);

	// Position
	void move(float x, float y);
	void move(const sf::Vector2f&);
	void setPosition(float x, float y);
	void setPosition(const sf::Vector2f&);
	
	// Background
	void setBackgroundColor(const sf::Color&);
	sf::Color getBackgroundColor() const;
	void setBackgroundMargin(float);
	float getBackgroundMargin() const;

protected:
	sf::RectangleShape background; // Rectangle behind the text
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};