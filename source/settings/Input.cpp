#include "../../headers/settings/input.hpp"

/// <summary>
/// Create a new Input object thaht will catches events from the given window.
/// </summary>
/// <param name="window">The window linked.</param>
Input::Input(sf::RenderWindow* window)
{
	this->m_window = window;
	for (int i = 0; i < Bindings::DEBUG; i++)
	{
		this->keyBindings.push_back(sf::Keyboard::Unknown);
	}
}

Input::~Input()
{
}

/// <summary>
/// Add or change a key binding.
/// </summary>
/// <param name="name">The binding's name</param>
/// <param name="key">The key</param>
/// <param name="swap">If the key is already used, swap with the replaced key ?</param>
bool Input::setKeyToBinding(sf::Keyboard::Key key, Bindings binding, bool swap)
{
	// if the key is already used
	if (this->getKeyBinding(key) != Bindings::DEBUG)
	{
		// if we can swap
		if (swap)
		{
			// swap
			this->keyBindings[this->getKeyBinding(key)] = this->keyBindings[binding];
			this->keyBindings[binding] = key;
			return true;
		}
		else
		{
			// don't swap
			return false;
		}
	}
	else
	{
		// if the key is not used, just add it
		this->keyBindings[binding] = key;
		return true;
	}
}

/// <summary>
/// Get the binding of a key.
/// </summary>
/// <param name="key">The key</param>
/// <returns>The binding</returns>
Input::Bindings Input::getKeyBinding(sf::Keyboard::Key key)
{
	for (int i = 0; i < this->keyBindings.size(); i++)
	{
		if (this->keyBindings[i] == key)
		{
			return (Bindings)i;
		}
	}
	return Bindings::DEBUG;
}