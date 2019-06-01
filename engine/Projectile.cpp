// projectile_cpp

#include "Projectile.hpp"

bool Projectile::isAlive()
{
  return this->alive;
}

void Projectile::setAlive(bool alive)
{
  this->alive = alive;
}

void Projectile::update()
{
  this->setPosition(this->position.x, this->position.y - this->speed);
  if (this->position.y <= 0)
    this->setAlive(false);
}
