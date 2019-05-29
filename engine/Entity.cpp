// entity_cpp

#include "Entity.hpp"
#include <iostream>

Entity::Entity(std::string imageFile, int xPos, int yPos)
{
  if (texture.loadFromFile(imageFile) != 0) {
    this->sprite = sf::Sprite(texture);
    sf::FloatRect rect = sprite.getLocalBounds();
    this->setSize((int)rect.width, (int)rect.height);
    this->setPosition(xPos, yPos);
  }
};

void Entity::setPosition(int x, int y)
{
  this->position.x = x;
  this->position.y = y;
  this->sprite.setPosition(x, y);
};

void Entity::setPosition(Position p)
{
  this->position.x = p.x;
  this->position.y = p.y;
  this->sprite.setPosition(p.x, p.y);
}

void Entity::setSize(int width, int height)
{
  this->width = width;
  this->height = height;
};

void Entity::draw(sf::RenderWindow& window)
{
  window.draw(this->sprite);
}
