// SpriteFrame_hpp

#ifndef SpriteFrame_hpp
#define SpriteFrame_hpp

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

class SpriteFrame
{
public:
  SpriteFrame(std::string imageFile, int frameCount);

  // Gets the image for the sprite texture
  std::string getImage() { return this->imageFile; }

  // Gets the reference for the texture
  sf::Texture &getTexture() { return this->texture; }

  // Gets the number of times that the image will persist
  int getFrameCount() { return this->frameCount; }

private:
  std::string imageFile;
  sf::Texture texture;
  int frameCount;
};

#endif