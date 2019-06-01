// entity_cpp

#include "Entity.hpp"
#include <iostream>

Entity::Entity(Animation animation, int xPos, int yPos)
{
  this->animatedSprite = AnimatedSprite(animation);
  sf::FloatRect rect = this->animatedSprite.currentSprite().getLocalBounds();
  this->setSize((int)rect.width, (int)rect.height);
  this->setPosition(xPos, yPos);
};

Entity::Entity(std::string imageFile, int xPos, int yPos)
{
  std::vector<std::string> imageFiles;
  imageFiles.push_back(imageFile);
  Animation animation("default", imageFiles);
  this->animatedSprite = AnimatedSprite(animation);
  sf::FloatRect rect = this->animatedSprite.currentSprite().getLocalBounds();
  this->setSize((int)rect.width, (int)rect.height);
  this->setPosition(xPos, yPos);
}

Entity::Entity(std::vector<std::string> imageFiles, int xPos, int yPos)
{
  Animation animation("default", imageFiles);
  this->animatedSprite = AnimatedSprite(animation);
  sf::FloatRect rect = this->animatedSprite.currentSprite().getLocalBounds();
  this->setSize((int)rect.width, (int)rect.height);
  this->setPosition(xPos, yPos);
}

Entity::Entity(std::vector<SpriteFrame> spriteList, int xPos, int yPos)
{
  Animation animation("default", spriteList);
  this->animatedSprite = AnimatedSprite(animation);
  sf::FloatRect rect = this->animatedSprite.currentSprite().getLocalBounds();
  this->setSize((int)rect.width, (int)rect.height);
  this->setPosition(xPos, yPos);
}

void Entity::setPosition(int x, int y)
{
  this->position.x = x;
  this->position.y = y;
  this->animatedSprite.currentSprite().setPosition(x, y);
};

void Entity::setPosition(Position p)
{
  this->position.x = p.x;
  this->position.y = p.y;
  this->animatedSprite.currentSprite().setPosition(p.x, p.y);
}

void Entity::setSize(int width, int height)
{
  this->width = width;
  this->height = height;
};

void Entity::draw(sf::RenderWindow &window)
{
  // std::cout << "Drawing sprite " << this->animatedSprite.getCurrentSpriteIndex() << std::endl;
  window.draw(this->animatedSprite.nextSprite());
}

bool Entity::isColiding(Entity &e)
{
  if (this->position.x >= e.position.x &&
      this->position.x <= e.position.x + e.getSize().width &&
      this->position.y >= e.position.y &&
      this->position.y <= e.position.y + e.getSize().height)
  {
    return true;
  }
  else
  {
    return false;
  }
}
