#include "Ability.hpp"

Ability::Ability(Fighter* owner, Entity* visual)
	: m_owner(owner), m_visual(visual)
{
}

Ability::~Ability()
{
}

Fighter* Ability::getOwner() const
{
	return this->m_owner;
}

// Implementation of Fighter methods needing Ability

void Fighter::addAbility(Ability* ability)
{
	this->m_abilities.push_back(ability);
}

void Fighter::removeAbility(int index)
{
	this->m_abilities.erase(this->m_abilities.begin() + index);
}

Ability* Fighter::getAbility(int index) const
{
	return this->m_abilities[index];
}