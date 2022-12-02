#include "../ThrowYourDice/headers/"

Entity::Entity(const sf::Texture& texture)
{
	this->texture = texture;
	this->sprite.setTexture(this->texture);
}

void Entity::moveSprite(float x, float y)
{
	this->sprite.move(x, y);
}

void Entity::moveSprite(sf::Vector2f movement)
{
	this->sprite.move(movement);
}

void Entity::setSpritePosition(float x, float y)
{
	this->sprite.setPosition(x, y);
}

void Entity::setSpritePosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

sf::Vector2f Entity::getSpritePosition()
{
	return this->sprite.getPosition();
}

sf::Sprite& Entity::getSprite()
{
	return this->sprite;
}

void Entity::setTexture(const sf::Texture& texture)
{
	this->texture = texture;
	this->sprite.setTexture(this->texture);
}

sf::Texture& Entity::getTexture()
{
	return this->texture;
}