#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity(const sf::Texture& texture);

	// Sprite management
	sf::Sprite& getSprite();
	sf::Vector2f getSpritePosition();
	void moveSprite(float x, float y);
	void moveSprite(sf::Vector2f);
	void setSpritePosition(float x, float y);
	void setSpritePosition(sf::Vector2f);

	// Texture managment
	sf::Texture& getTexture();
	void setTexture(const sf::Texture& texture);
	void setTextureRect(sf::IntRect rect);

protected:
	sf::Sprite sprite;
	sf::Texture texture;
};

