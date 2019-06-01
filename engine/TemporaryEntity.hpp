// TemporaryEntity_hpp

#ifndef TemporaryEntity_hpp
#define TemporaryEntity_hpp

#include "Entity.hpp"

class TemporaryEntity : public Entity
{
public:
  TemporaryEntity(std::string imageFile, int x, int y, float spriteScale = 1) : Entity(imageFile, x, y, spriteScale), alive(true) {}
  TemporaryEntity(std::vector<SpriteFrame> spriteList, int x, int y, float spriteScale = 1): Entity(spriteList, x, y, spriteScale), alive(true) {}

  // Gets the temporary entity current status
  bool isAlive() { return this->alive; }

  // Sets the temporary entity current status
  void setAlive(bool alive) { this->alive = alive; }

  // Update the temporary entity
  void update();

private:
  bool alive;
};

#endif