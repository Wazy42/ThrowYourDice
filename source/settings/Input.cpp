#include "../../headers/settings/Input.hpp"

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