// Enemy_cpp

#include "Enemy.hpp"

void Enemy::draw(sf::RenderWindow& window)
{
  if (this->alive) window.draw(this->sprite);
}

void Enemy::update()
{
  this->setPosition(this->position.x, this->position.y + this->speed);
}
