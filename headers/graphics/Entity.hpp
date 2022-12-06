#pragma once
#include <SFML/Graphics.hpp>

#define SPRITE_SIZE 32;

class Entity : public sf::Drawable
{
public:
	/// <summary>
	/// Create an entity, with a texture to render.
	/// </summary>
	/// <param name="texture">The texture that represent the Entity</param>
	Entity(const sf::Texture&);
	~Entity();
	
	// Position

	/// <summary>
	/// Get the position of the entity.
	/// </summary>
	/// <returns></returns>
	sf::Vector2f getPosition();

	/// <summary>
	/// Move the sprite by the given x and y pixels.
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void move(float x, float y);

	/// <summary>
	/// Move the sprite by the given vector.
	/// </summary>
	/// <param name="movement"></param>
	void move(sf::Vector2f);

	/// <summary>
	/// Set the sprite's position to the given x and y pixels.
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f);

	// Texture and scale

	/// <summary>
	/// Set the entity texture.
	/// </summary>
	/// <param name="texture">New texture</param>
	void setTexture(const sf::Texture&);

	/// <summary>
	/// Sets the texture rect.
	/// </summary>
	/// <param name="rect">New texture rect</param>
	void setTextureRect(sf::IntRect);

	/// <summary>
	/// Set the sprite's scale.
	/// </summary>
	/// <param name="x">New x scale</param>
	/// <param name="y">New y scale</param>
	void setScale(float, float = 0);

    // Sprite
    /// <summary>
    /// Get the sprite of the entity.
    /// </summary>
    /// <returns></returns>
    const sf::Sprite& getSprite(void) const;


	// Animation

	
    
protected:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};

