// entity_cpp

#include "Entity.hpp"
#include <iostream>

Entity::Entity(Animation animation, double xPos, double yPos, float scale)
{
  this->animatedSprite = AnimatedSprite(animation, scale);
  sf::FloatRect rect = this->animatedSprite.currentSprite().getLocalBounds();
  this->setSize(rect.width * scale, rect.height * scale);
  this->setPosition(xPos, yPos);

  collisionArea.setSize(sf::Vector2f(this->width, this->height));
  collisionArea.setPosition(this->position.x, this->position.y);
  collisionArea.setOutlineThickness(5.0f);
  collisionArea.setOutlineColor(sf::Color(255, 0, 0));
};

Entity::Entity(std::string imageFile, double xPos, double yPos, float scale)
{
  std::vector<std::string> imageFiles;
  imageFiles.push_back(imageFile);
  Animation animation("default", imageFiles);
  this->animatedSprite = AnimatedSprite(animation, scale);
  sf::FloatRect rect = this->animatedSprite.currentSprite().getLocalBounds();
  this->setSize(rect.width * scale, rect.height * scale);
  this->setPosition(xPos, yPos);

  collisionArea.setSize(sf::Vector2f(this->width, this->height));
  collisionArea.setPosition(this->position.x, this->position.y);
  collisionArea.setOutlineThickness(5.0f);
  collisionArea.setOutlineColor(sf::Color(255, 0, 0));
}

Entity::Entity(std::vector<std::string> imageFiles, double xPos, double yPos, float scale)
{
  Animation animation("default", imageFiles);
  this->animatedSprite = AnimatedSprite(animation, scale);
  sf::FloatRect rect = this->animatedSprite.currentSprite().getLocalBounds();
  this->setSize(rect.width * scale, rect.height * scale);
  this->setPosition(xPos, yPos);

  collisionArea.setSize(sf::Vector2f(this->width, this->height));
  collisionArea.setPosition(this->position.x, this->position.y);
  collisionArea.setOutlineThickness(5.0f);
  collisionArea.setOutlineColor(sf::Color(255, 0, 0));
}

Entity::Entity(std::vector<SpriteFrame> spriteList, double xPos, double yPos, float scale)
{
  Animation animation("default", spriteList);
  this->animatedSprite = AnimatedSprite(animation, scale);
  sf::FloatRect rect = this->animatedSprite.currentSprite().getLocalBounds();
  this->setSize(rect.width * scale, rect.height * scale);
  this->setPosition(xPos, yPos);

  collisionArea.setSize(sf::Vector2f(this->width, this->height));
  collisionArea.setPosition(this->position.x, this->position.y);
  collisionArea.setOutlineThickness(1.0f);
  collisionArea.setOutlineColor(sf::Color(255, 0, 0));
}

void Entity::setPosition(double x, double y)
{
  this->position.x = x;
  this->position.y = y;
  this->animatedSprite.currentSprite().setPosition(x, y);
  this->collisionArea.setPosition(x, y);
};

void Entity::setPosition(Position p)
{
  this->position.x = p.x;
  this->position.y = p.y;
  this->animatedSprite.currentSprite().setPosition(p.x, p.y);
  this->collisionArea.setPosition(p.x, p.y);
}

Position Entity::getCenter()
{
  Position p;
  p.x = this->position.x + this->width / 2;
  p.y = this->position.y + this->height / 2;
  return p;
}

void Entity::setSize(double width, double height)
{
  this->width = width;
  this->height = height;
};

void Entity::draw(sf::RenderWindow &window)
{
  window.draw(this->collisionArea);
  window.draw(this->animatedSprite.nextSprite());
}

bool Entity::isColiding(Entity &e)
{
  const double sourceMinX = this->position.x;
  const double sourceMaxX = this->position.x + this->width;
  const double sourceMinY = this->position.y;
  const double sourceMaxY = this->position.y + this->height;

  const double targetMinX = e.position.x;
  const double targetMaxX = e.position.x + e.width;
  const double targetMinY = e.position.y;
  const double targetMaxY = e.position.y + e.height;

  const bool xCollision = (sourceMinX >= targetMinX && sourceMinX <= targetMaxX)
                          || (sourceMaxX >= targetMinX && sourceMaxX <= targetMaxX);
  const bool yCollision = (sourceMinY >= targetMinY && sourceMinY <= targetMaxY)
                          || (sourceMaxY >= targetMinY && sourceMaxY <= targetMaxY);

  return xCollision && yCollision;
}
