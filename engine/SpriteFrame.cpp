// SpriteFrame_cpp

#include "SpriteFrame.hpp"

SpriteFrame::SpriteFrame(std::string imageFile, int frameCount)
{
  if (this->texture.loadFromFile(imageFile))
  {
    this->imageFile = imageFile;
    this->frameCount = frameCount;
  }
  else
  {
    throw "Failed to load texture";
  }
}