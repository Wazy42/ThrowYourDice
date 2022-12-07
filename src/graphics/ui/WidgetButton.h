#pragma once

#include <sfml/Graphics.hpp>


class WidgetButton : public sf::Drawable
{
	friend class UI;

public:

	WidgetButton();

	const sf::Vector2f& getPosition() const;
	void setPosition( float x, float y );

	sf::Vector2f getSize() const;
	void setSize( float sizeX, float sizeY );

	void setBackgroundTexture(sf::Texture& t);

	void setLabelText(const char* text);

	/// <summary>
	/// Sets the action of this button upon clicking.
	/// </summary>
	/// <param name="c">The function to call</param>
	/// <param name="param">Optional user-defined parameter to pass to the function.</param>
	void setCallback( void(*c)(int), int param );

protected:

	virtual void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;



private:

	sf::Sprite m_sprite;
	sf::Text m_label;

	void (*m_callback)(int param);
	int m_callbackParam;
};
