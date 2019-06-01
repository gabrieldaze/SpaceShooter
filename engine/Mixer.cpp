// Mixer_cpp

#include "Mixer.hpp"

bool Mixer::setBGM(std::string fileName)
{
  if (!this->bgMusic.openFromFile(fileName))
    return false;
  return true;
}

bool Mixer::setBGM(std::string fileName, float volume)
{
  if (!this->bgMusic.openFromFile(fileName))
    return false;
  this->bgMusic.setVolume(volume);
  return true;
}

bool Mixer::setFireSfx(std::string fileName)
{
  if (!this->fireSfxBuffer.loadFromFile(fileName))
    return false;
  this->fireSfx.setBuffer(fireSfxBuffer);
  return true;
}

bool Mixer::setFireSfx(std::string fileName, float volume)
{
  if (!this->fireSfxBuffer.loadFromFile(fileName))
    return false;
  this->fireSfx.setBuffer(fireSfxBuffer);
  this->fireSfx.setVolume(volume);
  return true;
}

bool Mixer::setExplosionSfx(std::string fileName)
{
  if (!this->explosionSfxBuffer.loadFromFile(fileName))
    return false;
  this->explosionSfx.setBuffer(explosionSfxBuffer);
  return true;
}

bool Mixer::setExplosionSfx(std::string fileName, float volume)
{
  if (!this->explosionSfxBuffer.loadFromFile(fileName))
    return false;
  this->explosionSfx.setBuffer(explosionSfxBuffer);
  this->explosionSfx.setVolume(volume);
  return true;
}
