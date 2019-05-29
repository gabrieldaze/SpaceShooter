// projectile_hpp

#ifndef projectile_hpp
#define projectile_hpp

#include "Entity.hpp"

class Projectile: public Entity
{
 public:
  // Expects a string containing the file name
  Projectile(std::string imageFile, int x, int y): Entity(imageFile, x, y), alive(true) {}

  // Gets the current projectile status
  bool isAlive();

  // Sets the current projectile status
  void setAlive(bool alive);

  // Overriding the draw method
  void draw(sf::RenderWindow& window);

  // Update the projectile position
  void update(double speed);

 private:
  // Holds the projectile status
  bool alive;
};

#endif
