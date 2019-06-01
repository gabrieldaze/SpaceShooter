// Animation_cpp

#include "Animation.hpp"

Animation::Animation(std::string name, std::vector<std::string> images)
{
  this->name = name;
  for (auto image : images)
  {
    SpriteFrame frame(image, 120);
    this->frames.push_back(frame);
  }
}