// SpriteFrame_cpp

#include "SpriteFrame.hpp"
#include <stdexcept>

SpriteFrame::SpriteFrame(std::string imageFile, int frameCount)
{
  if (this->texture.loadFromFile(imageFile))
  {
    this->imageFile = imageFile;
    this->frameCount = frameCount;
  }
  else
  {
    throw std::runtime_error(imageFile);
  }
}