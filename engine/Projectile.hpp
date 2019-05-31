// projectile_hpp

#ifndef projectile_hpp
#define projectile_hpp

#include "Entity.hpp"

class Projectile: public Entity
{
 public:
  // Expects a string containing the file name
  Projectile(std::string imageFile, int x, int y): Entity(imageFile, x, y), alive(true), speed(0) {}
  Projectile(std::string imageFile, int x, int y, double s): Entity(imageFile, x, y), alive(true), speed(s) {}

  // Gets the current projectile status
  bool isAlive();

  // Sets the current projectile status
  void setAlive(bool alive);

  // Overrides the draw method
  void draw(sf::RenderWindow& window);

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
