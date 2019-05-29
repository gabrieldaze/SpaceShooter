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

void Projectile::draw(sf::RenderWindow& window)
{
  if (this->alive) window.draw(this->sprite);
}

void Projectile::update(double speed)
{
  this->setPosition(this->position.x, this->position.y - speed);
}
