#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Window;
class WidgetButton;


class UI
{
public:

	UI( Window* w );
	~UI();

	void addWidget(sf::Drawable& d);
	void addButton(WidgetButton* b);

	/// <summary>
	/// Handles mouse events for user interaction.
	/// </summary>
	/// <param name="e">The SFML event structure fetched using pollEvent().</param>
	void handleEvent(const sf::Event& e);

private:

	WidgetButton* getHoveredButton() const;



private:

	Window* m_window;

	std::vector<sf::Drawable*> m_widgets;
	std::vector<WidgetButton*> m_buttons;
};
