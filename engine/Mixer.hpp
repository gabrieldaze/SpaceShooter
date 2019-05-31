// Mixer_hpp

#ifndef mixer_hpp
#define mixer_hpp

#include <SFML/Audio.hpp>
#include <iostream>

class Mixer
{
 public:
  bool setBGM(std::string fileName);
  bool setBGM(std::string fileName, float volume);
  bool setFireSfx(std::string fileName);
  bool setFireSfx(std::string fileName, float volume);
  bool setExplosionSfx(std::string fileName);
  bool setExplosionSfx(std::string fileName, float volume);

  sf::Music& getBGMusic() { return bgMusic; }
  sf::Sound& getFireSfx() { return fireSfx; }
  sf::Sound& getExplosionSfx() { return explosionSfx; }
 private:
  sf::Music bgMusic;
  sf::Sound fireSfx;
  sf::SoundBuffer fireSfxBuffer;
  sf::Sound explosionSfx;
  sf::SoundBuffer explosionSfxBuffer;
};

#endif
