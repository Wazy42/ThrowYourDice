#include "../../headers/settings/Input.hpp"

Input::Input(sf::RenderWindow* window)
{
	this->m_window = window;
	for (int i = 0; i < Bindings::DEBUG; i++)
	{
		this->m_keyBindings.push_back(sf::Keyboard::Unknown);
	}
}

Input::~Input()
{
}

bool Input::setKeyToBinding(sf::Keyboard::Key key, Bindings binding, bool swap)
{
	// if the key is already used
	if (this->getKeyBinding(key) != Bindings::DEBUG)
	{
		// if we can swap
		if (swap)
		{
			// swap
			this->m_keyBindings[this->getKeyBinding(key)] = this->m_keyBindings[binding];
			this->m_keyBindings[binding] = key;
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
		this->m_keyBindings[binding] = key;
		return true;
	}
}

Input::Bindings Input::getKeyBinding(sf::Keyboard::Key key)
{
	for (int i = 0; i < this->m_keyBindings.size(); i++)
	{
		if (this->m_keyBindings[i] == key)
		{
			return (Bindings)i;
		}
	}
	return Bindings::DEBUG;
}

sf::Vector2i Input::getMouseCoordinates()
{
	return sf::Mouse::getPosition(*this->m_window);
}