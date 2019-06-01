#ifndef player_hpp
#define player_hpp

#include "Entity.hpp"

class Player : public Entity
{
public:
  Player(std::string imageFile, int x, int y) : Entity(imageFile, x, y) {}
  Player(std::vector<std::string> imageFiles, int x, int y) : Entity(imageFiles, x, y) {}
  Player(std::vector<SpriteFrame> spriteList, int x, int y) : Entity(spriteList, x, y) {}

  // Gets the current player status
  bool isAlive();

  // Sets the current player status
  void setAlive(bool alive);

private:
  // Player alive status
  bool alive;
};

#endif
