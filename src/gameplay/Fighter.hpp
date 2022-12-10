#pragma once

#include <SFML/Graphics.hpp>
#include "Const.hpp"
#include "src/graphics/AnimatedEntity.hpp"

// Forward declaration for ability. This is needed because of the circular dependency between Ability and Fighter.
class Ability;

class Fighter : public AnimatedEntity
{
public:
	/// <summary>
	/// Create a new fighter.
	/// </summary>
	/// <param name="texture"></param>
	/// <param name="frameSize"></param>
	/// <param name="framesPerAnimation"></param>
	/// <param name="delayBetweenFrames"></param>
	/// <param name="health"></param>
	/// <param name="attack"></param>
	/// <param name="defense"></param>
	/// <param name="abilityPoints"></param>
	/// <param name="movementPoints"></param>
	/// <param name="initiative"></param>
	Fighter(const sf::Texture& texture, sf::Vector2f frameSize, int framesPerAnimation, int delayBetweenFrames, int health, int attack, int defense, int abilityPoints, int movementPoints, int initiative);
	~Fighter(); // Delete all abilities

	// Getters

	/// <summary>
	/// Get the current health of the fighter.
	/// </summary>
	/// <param name="max">Get the max value of this stat, instead of the current value</param>
	int getHealth(bool max = false) const;

	/// <summary>
	/// Get the current attack of the fighter.
	/// </summary>
	/// <param name="base">Get the base value of this stat, instead of the current value</param>
	int getAttack(bool base = false) const;

	/// <summary>
	/// Get the current defense of the fighter.
	/// </summary>
	/// <param name="base">Get the base value of this stat, instead of the current value</param>
	int getDefense(bool base = false) const;

	/// <summary>
	/// Get the current ability points of the fighter.
	/// </summary>
	/// <param name="max">Get the max value of this stat, instead of the current value</param>
	int getAbiliyPoint(bool max = false) const;

	/// <summary>
	/// Get the current movement poins of the fighter.
	/// </summary>
	/// <param name="max">Get the max value of this stat, instead of the current value</param>
	int getMovementPoints(bool max = false) const;

	/// <summary>
	/// Get the initiative of the fighter.
	/// </summary>
	int getInitiative() const;

	// Setters

	/// <summary>
	/// Set the current health of the fighter.
	/// </summary>
	/// <param name="health">New value</param>
	/// <param name="setMethod">Method to apply the value (Set, Add, Multiply)</param>
	void setCurrentHealth(float health, SetMethod setMethod);

	/// <summary>
	/// Set the current attack of the fighter.
	/// </summary>
	/// <param name="attack">New value</param>
	/// <param name="setMethod">Method to apply the value (Set, Add, Multiply)</param>
	void setCurrentAttack(float attack, SetMethod setMethod);

	/// <summary>
	/// Set the current defense of the fighter.
	/// </summary>
	/// <param name="defense">New value</param>
	/// <param name="setMethod">Method to apply the value (Set, Add, Multiply)</param>
	void setCurrentDefense(float defense, SetMethod setMethod);

	/// <summary>
	/// Set the current ability points of the fighter.
	/// </summary>
	/// <param name="abilityPoints">New value</param>
	/// <param name="setMethod">Method to apply the value (Set, Add, Multiply)</param>
	void setCurrentAbilityPoints(float abilityPoints, SetMethod setMethod);

	/// <summary>
	/// Set the current movement points of the fighter.
	/// </summary>
	/// <param name="movementPoints">New value</param>
	/// <param name="setMethod">Method to apply the value (Set, Add, Multiply)</param>
	void setCurrentMovementPoints(float movementPoints, SetMethod setMethod);

	/// <summary>
	/// Set the initiative of the fighter.
	/// </summary>
	/// <param name="health">New value</param>
	/// <param name="setMethod">Method to apply the value (Set, Add, Multiply)</param>
	void setInitiative(float initiative, SetMethod setMethod);

	/// <summary>
	/// Reset all stats to their max or base value.
	/// </summary>
	void resetStats();

	// Abilities
	// The implementation of these methods is in the Ability class.
	
	/// <summary>
	/// Add an ability to the fighter.
	/// </summary>
	/// <param name="ability">Ability to add</param>
	void addAbility(Ability* ability);
	
	/// <summary>
	/// Remove the ability at the given index.
	/// </summary>
	/// <param name="index">Index of the ability</param>
	void removeAbility(int index);
	
	/// <summary>
	/// Get the ability at the given index.
	/// </summary>
	/// <param name="index">Index of the ability</param>
	Ability* getAbility(int index) const;
	
private:
	int m_currentHealth;
	int m_maxHealth;	
	int m_currentAttack;
	int m_baseAttack;
	int m_currentDefense;
	int m_baseDefense;
	int m_currentAbilityPoints;
	int m_maxAbilityPoints;
	int m_currentMovementPoints;
	int m_maxMovementPoints;
	int m_initiative;
	std::vector<Ability*> m_abilities;
	
	// TODO: Add a vector of status effects
};

