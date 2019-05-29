// Entity_hpp

#ifndef entity_hpp
#define entity_hpp

#include <SFML/Graphics.hpp>
#include <string>

struct Position
{
  int x, y;
};

class Entity
{
 public:
  // Creates an entity with an image and x and y position
  Entity(std::string imageFile, int xPos, int yPos);

  // Holds the entity position
  Position position;

  // Holds the entity width and height
  int width, height;

  // Sets the entity position
  void setPosition(int x, int y);
  void setPosition(Position p);

  // Gets the entity position
  Position getPosition() { return this->position; }

  // Sets the entity local bound
  void setSize(int width, int height);

  // Gets the entity local bound
  sf::FloatRect getSize() { return sprite.getLocalBounds(); }

  // Gets a reference for the entity texture
  sf::Texture& getTexture() { return texture; }

  // Gets a reference for the entity sprite
  sf::Sprite& getSprite() { return sprite; }

  // Draw the entity through a window reference
  void draw(sf::RenderWindow& window);

 protected:
  sf::Texture texture;
  sf::Sprite sprite;
};

#endif
