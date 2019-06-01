// Animation_hpp

#ifndef Animation_hpp
#define Animation_hpp

#include <SFML/Graphics.hpp>
#include "SpriteFrame.hpp"

#include <string>
#include <vector>

class Animation
{
public:
  Animation() {}
  Animation(std::string n) : name(n) {}
  Animation(std::string n, std::vector<SpriteFrame> f) : name(n), frames(f) {}
  Animation(std::string n, std::vector<std::string> images);

  std::string name;

  // Return the vector size
  int size() { return (int)this->frames.size(); }

  // Gets a reference of the animation frames
  std::vector<SpriteFrame> &getFrames() { return this->frames; }

private:
  std::vector<SpriteFrame> frames;
};

#endif