#include "../../headers/graphics/AnimatedEntity.hpp"

AnimatedEntity::AnimatedEntity(const sf::Texture &texture, std::vector<sf::IntRect> animationIndex) 
: Entity(texture)
{
    this->m_count = 0;
    this->m_animationIndex = animationIndex;

    if (animationIndex.size() <= 0)
        throw;

    this->setTextureRect(this->m_animationIndex[this->m_count]);
}

AnimatedEntity::~AnimatedEntity() {}

void AnimatedEntity::nextAnimation(void)
{
    this->m_count++;
    if (this->m_count >= this->m_animationIndex.size())
        this->m_count = 0;
    this->setTextureRect(this->m_animationIndex[this->m_count]);
}

void AnimatedEntity::Animate(std::string fileName, int posT)
{
    if (!this->m_texture.loadFromFile(fileName))
    {
        throw "ANIMATED_ENTITY::ANIMATE::ERROR::LOADING_TEXTURE";
    }
    this->setTexture(this->m_texture);
    // this->setTextureRect(this->m_animationIndex[posT]);


    
        if (this->m_count % 30 == 0)
        {
            this->m_iter = (this->m_iter + 16) % (16*5);
            // 16 = Size
            // 64 = Size * 5 (5 animations)
            this->setTextureRect(sf::IntRect(this->m_iter, posT, 16, 16)); 
            this->m_count = 0;
        }
        this->m_count++;
    
}
