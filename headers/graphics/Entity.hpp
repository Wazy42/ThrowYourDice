#pragma once
#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable
{
public:
	Entity(const sf::Texture&);
	~Entity();
	void draw(sf::RenderTarget&, sf::RenderStates) const;
	
	// Position
	sf::Vector2f getPosition();
	void move(float x, float y);
	void move(sf::Vector2f);
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f);

	// Texture and scale
	void setTexture(const sf::Texture&);
	void setTextureRect(sf::IntRect);
	void setScale(float, float = 0);

	// Animation
	// TODO
	
protected:
	sf::Sprite sprite;
	sf::Texture texture;
};

