// projectile_hpp

#ifndef projectile_hpp
#define projectile_hpp

#include "Entity.hpp"

class Projectile : public Entity
{
public:
  Projectile(std::string imageFile, int x, int y, float spriteScale = 1) : Entity(imageFile, x, y, spriteScale), alive(true), speed(0) {}
  Projectile(std::string imageFile, int x, int y, double s, float spriteScale = 1) : Entity(imageFile, x, y, spriteScale), alive(true), speed(s) {}
  Projectile(std::vector<SpriteFrame> spriteList, int x, int y, float spriteScale = 1) : Entity(spriteList, x, y, spriteScale), alive(true), speed(0) {}
  Projectile(std::vector<SpriteFrame> spriteList, int x, int y, double s, float spriteScale = 1) : Entity(spriteList, x, y, spriteScale), alive(true), speed(s) {}

  // Gets the current projectile status
  bool isAlive();

  // Sets the current projectile status
  void setAlive(bool alive);

  // Update the projectile position
  void update();

  // Gets the projectile moving speed
  double getSpeed() { return this->speed; }

  // Sets the projectile moving speed
  void setSpeed(double speed) { this->speed = speed; }

private:
  // Holds the projectile status
  bool alive;

  // Holds the projectile moving speed
  double speed;
};

#endif
