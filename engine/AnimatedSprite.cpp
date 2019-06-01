// AnimatedSprite_cpp

#include "AnimatedSprite.hpp"

sf::Sprite &AnimatedSprite::nextSprite()
{
  if (this->animation.size() > 1)
  {
    if (this->currentSpriteFrame >= this->animation.getFrames()[currentSpriteIndex].getFrameCount() - 1)
    {
      this->sprite.setTexture(this->animation.getFrames()[currentSpriteIndex].getTexture());

      this->currentSpriteFrame = 0;
      this->currentSpriteIndex += 1;


      if (this->currentSpriteIndex > this->animation.size() - 1)
        this->currentSpriteIndex = 0;
    }
    else
    {
      this->currentSpriteFrame += 1;
    }
  }

  return this->sprite;
}