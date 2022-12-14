#pragma once

#include <SFML/Graphics.hpp>
#include "../Window.hpp"


#define BORDER_RIGHT sf::Vector2f(window->getSize().x - m_background.getGlobalBounds().width, 0)
#define BORDER_BOTTOM sf::Vector2f(0, window->getSize().y - m_background.getGlobalBounds().height)
#define BORDER_TOP sf::Vector2f(0, 0)
#define BORDER_LEFT sf::Vector2f(0, 0)
class Sidebar : public sf::Drawable
{
	friend class UI;
public:



    // position right border  = window width - sidebar width, 0
    // position bottom border = 0, window height - sidebar height
    // position top border = 0, 0
    // position left border = 0, 0
	Sidebar(const sf::Vector2f& pos, const sf::Vector2f& size);

	const::sf::Vector2f& getPosition() const;
	void setPosition(sf::Vector2f pos);
	
	sf::Vector2f getSize() const;
	void setSize(float sizeX, float sizeY);

	//void setBackgroundTexture(sf::Texture& t);

	void setLabelText(const char* text);
	
protected:
	virtual void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;

	
private:
	//sf::Sprite m_sprite;
	sf::Text m_label;

	Window* window;
	/// Background sprite.
	sf::RectangleShape m_background;

	void(*m_callback)(int param);
	int m_callbackParam;

};