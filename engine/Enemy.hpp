// Enemy_hpp

#ifndef enemy_hpp
#define enemy_hpp

#include "Entity.hpp"

class Enemy : public Entity
{

public:
  Enemy(std::string imageFile, int xPos, int yPos) : Entity(imageFile, xPos, yPos), alive(true), speed(0) {}

  Enemy(std::string imageFile, int xPos, int yPos, double s) : Entity(imageFile, xPos, yPos), alive(true), speed(s) {}

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
