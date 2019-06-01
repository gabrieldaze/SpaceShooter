// AnimatedSprite_hpp

#ifndef AnimatedSprite_hpp
#define AnimatedSprite_hpp

#include "Animation.hpp"

class AnimatedSprite
{
public:
  AnimatedSprite() : currentSpriteIndex(0), currentSpriteFrame(0) {}
  AnimatedSprite(Animation a) : animation(a), currentSpriteIndex(0), currentSpriteFrame(0)
  {
    this->sprite.setTexture(this->animation.getFrames()[0].getTexture());
    // this->sprite.setScale(sf::Vector2f(2.0f, 2.0f));
  }

  // Gets the reference for the animation
  Animation &getAnimation() { return this->animation; }

  // Gets the current sprite
  sf::Sprite &currentSprite() { return this->sprite; };

  // Gets the next sprite
  sf::Sprite &nextSprite();

  // Gets the current sprite index
  int getCurrentSpriteIndex() { return this->currentSpriteIndex; }

  // Gets the current sprite frame
  int getCurrentSpriteFrame() { return this->currentSpriteFrame; }

private:
  Animation animation;
  sf::Sprite sprite;
  int currentSpriteIndex;
  int currentSpriteFrame;
};

#endif