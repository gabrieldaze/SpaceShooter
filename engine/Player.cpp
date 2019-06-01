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

void Player::update(bool UP_KEY, bool DOWN_KEY, bool LEFT_KEY, bool RIGHT_KEY, bool SPACE_BAR_KEY)
{
  if (!this->isAlive()) this->reset();
  // Calculate both X and Y speed
  if (UP_KEY) { ySpeed = ySpeed <= -maxSpeed ? ySpeed : ySpeed - acceleration;  }
  if (DOWN_KEY) { ySpeed = ySpeed >= maxSpeed ? ySpeed : ySpeed + acceleration; }
  if (LEFT_KEY) { xSpeed = xSpeed <= -maxSpeed ? xSpeed : xSpeed - acceleration; }
  if (RIGHT_KEY) { xSpeed = xSpeed >= maxSpeed ? xSpeed : xSpeed + acceleration; }

  // Add friction to movement on Y axis
  if (!UP_KEY && !DOWN_KEY) {
    if (ySpeed != 0) {
      if (ySpeed < 0) ySpeed += acceleration;
      if (ySpeed > 0) ySpeed -= acceleration;
    }
  }

  // Add friction to movement on X axis
  if (!LEFT_KEY && !RIGHT_KEY) {
    if (xSpeed != 0) {
      if (xSpeed < 0) xSpeed += acceleration;
      if (xSpeed > 0) xSpeed -= acceleration;
    }
  }

  if (SPACE_BAR_KEY) {
      if (fireCooldown >= fireRate) {
        fireCooldown = 0;
        this->spawnProjectile(3.0f, 1.5f);
      } else {
        fireCooldown += 1;
      }
    } else {
      fireCooldown = fireRate;
    }

  const double xPos = this->position.x + this->xSpeed;
  const double yPos = this->position.y + this->ySpeed;
  this->setPosition(xPos, yPos);
}

void Player::spawnProjectile(double projectileSpeed, double projectileScale)
{
  this->projectileList->push_back(createProjectile(
    regularProjectileSpriteList,
    this->getCenter().x - regularProjectileSpriteList[0].getTexture().getSize().x * projectileScale / 2,
    this->getCenter().y - regularProjectileSpriteList[0].getTexture().getSize().y * projectileScale,
    projectileSpeed,
    projectileScale));
  this->mixer->getFireSfx().play();
}

void Player::setWindow(sf::RenderWindow* window)
{
  this->window = window;
}

void Player::setMixer(Mixer* mixer)
{
  this->mixer = mixer;
}

void Player::setProjectileList(std::vector<Projectile*> *projectileList)
{
  this->projectileList = projectileList;
}

void Player::reset()
{
  this->setAlive(true);
  if (this->window != nullptr) {
    const double xPos = this->window->getSize().x / 2 - this->width / 2;
    const double yPos = this->window->getSize().y / 2 + this->height * 4;
    this->setPosition(xPos, yPos);
    this->xSpeed = 0;
    this->ySpeed = 0;
  }
}