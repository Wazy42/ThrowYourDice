#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

#define SPRITE_SIZE 32;

class AnimatedEntity : public Entity
{
public:
    /// <summary>
    /// Create an entity, with a texture to render.
    /// </summary>
    /// <param name="texture">The texture that represent the Entity</param>
    AnimatedEntity(const sf::Texture &, std::vector<sf::IntRect>);
    ~AnimatedEntity();

    /// <summary>
    /// Animate the entity with its sprite texture.
    void Animate(std::string fileName, int posT);

    // Animation

    /// <summary>
    /// Change the animation to the next one.
    /// </summary>
    void nextAnimation(void);

private:
    sf::IntRect m_textureRect;
    sf::Clock m_clock;
    sf::Time m_time;
    float m_frameTime;
    int m_frameCount;
    int m_currentFrame;

protected:
    size_t m_count;
    size_t m_iter;
    std::vector<sf::IntRect> m_animationIndex;
};