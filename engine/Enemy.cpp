// Enemy_cpp

#include "Enemy.hpp"

void Enemy::update()
{
  this->setPosition(this->position.x, this->position.y + this->speed);
}
