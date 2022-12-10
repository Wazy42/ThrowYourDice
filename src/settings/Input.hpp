#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include "Const.hpp"

/// <summary>
/// Class that manages the inputs of a window (keyboard and mouse).
/// </summary>
class Input
{
public:
	/// <summary>
	/// Create a new Input object thaht will catches events from the given window.
	/// </summary>
	/// <param name="window">The window linked.</param>
	Input(sf::RenderWindow* w);
	~Input();
	
	/// <summary>
	/// Add or change a key binding.
	/// </summary>
	/// <param name="name">The binding's name</param>
	/// <param name="key">The key</param>
	/// <param name="swap">If the key is already used, swap with the replaced key ?</param>
	bool setKeyToBinding(sf::Keyboard::Key k, Bindings b, bool s = true);

	/// <summary>
	/// Get the binding of a key.
	/// </summary>
	/// <param name="key">The key</param>
	/// <returns>The binding</returns>
	Bindings getKeyBinding(sf::Keyboard::Key k);

	/// <summary>
	/// Get the mouse coordinates on the window.
	/// </summary>
	/// <returns>Mouse Coords</returns>
	sf::Vector2i getMouseCoordinates();

	
private:
	sf::RenderWindow* m_window;
	std::vector<sf::Keyboard::Key> m_keyBindings;
};

