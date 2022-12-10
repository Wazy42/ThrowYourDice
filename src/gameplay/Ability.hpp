#pragma once

#include <SFML/Graphics.hpp>
#include "Const.hpp"
#include "src/graphics/Entity.hpp"
#include "Fighter.hpp"

class Ability
{
public:
	/// <summary>
	/// Create a new ability.
	/// </summary>
	/// <param name="owner">Owner of the ability</param>
	/// <param name="visual"></param>
	Ability(Fighter* owner, Entity* visual);
	~Ability();
	
	Fighter* getOwner() const;
	virtual void useOn(Fighter* target) = 0;

private:
	Fighter* m_owner;
	Entity* m_visual;
};

