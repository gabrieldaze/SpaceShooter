// Enemy_hpp

#ifndef enemy_hpp
#define enemy_hpp

#include "Entity.hpp"

class Enemy : public Entity
{

public:
  Enemy(std::string imageFile, int x, int y) : Entity(imageFile, x, y), alive(true), speed(0) {}
  Enemy(std::string imageFile, int x, int y, double s) : Entity(imageFile, x, y), alive(true), speed(s) {}
  Enemy(std::vector<SpriteFrame> spriteList, int x, int y): Entity(spriteList, x, y), alive(true), speed(0) {}
  Enemy(std::vector<SpriteFrame> spriteList, int x, int y, double s): Entity(spriteList, x, y), alive(true), speed(s) {}

  // Gets the enemy current status
  bool isAlive() { return this->alive; }

  // Sets the enemy current status
  void setAlive(bool alive) { this->alive = alive; }

  // Update the enemy position
  void update();

private:
  bool alive;
  double speed;
};

#endif
