// Entity_hpp

#ifndef entity_hpp
#define entity_hpp

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"

#include <string>

class Position
{
public:
  double x, y;
  bool operator==(Position &p) { return x == p.x && y == p.y; }
};

class Entity
{
public:
  Entity(Animation animation, double xPos, double yPos, float scale);
  Entity(std::string imageFile, double xPos, double yPos, float scale);
  Entity(std::vector<std::string> imageFiles, double xPos, double yPos, float scale);
  Entity(std::vector<SpriteFrame> spriteList, double xPos, double yPos, float scale);

  // Holds the entity position
  Position position;

  // Holds the entity width and height
  double width, height;

  // Sets the entity position using X and Y
  void setPosition(double x, double y);

  // Sets the entity position using the Position class
  void setPosition(Position p);

  // Gets the entity position
  Position getPosition() { return this->position; }

  // Gets the entity center position
  Position getCenter();

  // Gets the center of xPos
  double getXCenter() { return this->position.x + this->width / 2; }

  // Gets the center of yPos
  double getYCenter() { return this->position.y + this->height / 2; }

  // Sets the entity local bound
  void setSize(double width, double height);

  // Gets the entity local bound
  sf::FloatRect getSize() { return this->animatedSprite.currentSprite().getLocalBounds(); }

  // Gets a reference for the entity sprite
  sf::Sprite getCurrentSprite() { return this->animatedSprite.currentSprite(); }

  // Draw the entity through a window reference
  void draw(sf::RenderWindow &window);

  // Checks if the entity is colliding with other entity
  bool isColiding(Entity &e);

protected:
  AnimatedSprite animatedSprite;
  float spriteScale;
  sf::RectangleShape collisionArea;
};

#endif
