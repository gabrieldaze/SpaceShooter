// player_cpp

#include "Player.hpp"

bool Player::isAlive()
{
  return this->alive;
}

void Player::setAlive(bool alive)
{
  this->alive = alive;
}
