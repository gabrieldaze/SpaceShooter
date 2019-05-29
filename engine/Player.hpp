#ifndef player_hpp
#define player_hpp

#include "Entity.hpp"

class Player: public Entity
{
 public:
  // Expects a path to an image and both x and y positions
  Player(std::string imageFile, int x, int y): Entity(imageFile, x, y) {}

  // Gets the current player status
  bool isAlive();

  // Sets the current player status
  void setAlive(bool alive);

 private:
  // Player alive status
  bool alive;
};

#endif
