// TemporaryEntity_cpp

#include "TemporaryEntity.hpp"

void TemporaryEntity::update()
{
  if (this->animatedSprite.getCurrentSpriteIndex() == this->animatedSprite.getAnimation().size() - 1) {
    this->setAlive(false);
  }
}