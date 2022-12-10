#include "Fighter.hpp"

/// <summary>
/// Round a float to the nearest integer.
/// </summary>
/// <param name="r">The number</param>
/// <returns>An rounded integer</returns>
int round_int(double r) {
	return (r > 0.0) ? static_cast<int>(r + 0.5) : static_cast<int>(r - 0.5);
}

Fighter::Fighter(const sf::Texture& texture, sf::Vector2f frameSize, int framesPerAnimation, int delayBetweenFrames, int health, int attack, int defense, int abilityPoints, int movementPoints, int initiative)
	: AnimatedEntity(texture, frameSize, framesPerAnimation, delayBetweenFrames)
{
	this->m_maxHealth = health;
	this->m_currentHealth = health;
	this->m_baseAttack = attack;
	this->m_currentAttack = attack;
	this->m_baseDefense = defense;
	this->m_currentDefense = defense;
	this->m_maxAbilityPoints = abilityPoints;
	this->m_currentAbilityPoints = abilityPoints;
	this->m_maxMovementPoints = movementPoints;
	this->m_currentMovementPoints = movementPoints;
	this->m_initiative = initiative;
}

Fighter::~Fighter()
{
	for (Ability* ability : this->m_abilities) {
		delete ability;
	}
}

int Fighter::getHealth(bool max) const
{
	return max ? this->m_maxHealth : this->m_currentHealth;
}

int Fighter::getAttack(bool base) const
{
	return base ? this->m_baseAttack : this->m_currentAttack;
}

int Fighter::getDefense(bool base) const
{
	return base ? this->m_baseDefense : this->m_currentDefense;
}

int Fighter::getAbiliyPoint(bool max) const
{
	return max ? this->m_maxAbilityPoints : this->m_currentAbilityPoints;
}

int Fighter::getMovementPoints(bool max) const
{
	return max ? this->m_maxMovementPoints : this->m_currentMovementPoints;
}

int Fighter::getInitiative() const
{
	return this->m_initiative;
}

void Fighter::setCurrentHealth(float health, SetMethod setMethod)
{
	switch (setMethod)
	{
	case SetMethod::Set:
		this->m_currentHealth = round_int(health);
		break;
	case SetMethod::Add:
		this->m_currentHealth = round_int(this->m_currentHealth + health);
		break;
	case SetMethod::Multiply:
		this->m_currentHealth = round_int(this->m_currentMovementPoints * health);
		break;
	}
}

void Fighter::setCurrentAttack(float attack, SetMethod setMethod)
{
	switch (setMethod)
	{
	case SetMethod::Set:
		this->m_currentAttack = round_int(attack);
		break;
	case SetMethod::Add:
		this->m_currentAttack = round_int(this->m_currentAttack + attack);
		break;
	case SetMethod::Multiply:
		this->m_currentAttack = round_int(this->m_currentAttack * attack);
		break;
	}
}

void Fighter::setCurrentDefense(float defense, SetMethod setMethod)
{
	switch (setMethod)
	{
	case SetMethod::Set:
		this->m_currentDefense = round_int(defense);
		break;
	case SetMethod::Add:
		this->m_currentDefense = round_int(this->m_currentDefense + defense);
		break;
	case SetMethod::Multiply:
		this->m_currentDefense = round_int(this->m_currentDefense * defense);
		break;
	}
}

void Fighter::setCurrentAbilityPoints(float abilityPoints, SetMethod setMethod)
{
	switch (setMethod)
	{
	case SetMethod::Set:
		this->m_currentAbilityPoints = round_int(abilityPoints);
		break;
	case SetMethod::Add:
		this->m_currentAbilityPoints = round_int(this->m_currentAbilityPoints + abilityPoints);
		break;
	case SetMethod::Multiply:
		this->m_currentAbilityPoints = round_int(this->m_currentAbilityPoints * abilityPoints);
		break;
	}
}

void Fighter::setCurrentMovementPoints(float movementPoints, SetMethod setMethod)
{
	switch (setMethod)
	{
	case SetMethod::Set:
		this->m_currentMovementPoints = round_int(movementPoints);
		break;
	case SetMethod::Add:
		this->m_currentMovementPoints = round_int(this->m_currentMovementPoints + movementPoints);
		break;
	case SetMethod::Multiply:
		this->m_currentMovementPoints = round_int(this->m_currentMovementPoints * movementPoints);
		break;
	}
}

void Fighter::setInitiative(float initiative, SetMethod setMethod)
{
	switch (setMethod)
	{
	case SetMethod::Set:
		this->m_initiative = initiative;
		break;
	case SetMethod::Add:
		this->m_initiative += initiative;
		break;
	case SetMethod::Multiply:
		this->m_initiative *= initiative;
		break;
	}
}

void Fighter::resetStats()
{
	this->m_currentHealth = this->m_maxHealth;
	this->m_currentAttack = this->m_baseAttack;
	this->m_currentDefense = this->m_baseDefense;
	this->m_currentAbilityPoints = this->m_maxAbilityPoints;
	this->m_currentMovementPoints = this->m_maxMovementPoints;
}
