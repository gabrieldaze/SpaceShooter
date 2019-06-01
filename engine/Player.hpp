#ifndef player_hpp
#define player_hpp

#include "Entity.hpp"
#include "Projectile.hpp"
#include "Mixer.hpp"
#include "../loader.hpp"

class Player : public Entity
{
public:
  Player(std::string imageFile, int x, int y, float spriteScale = 1) : Entity(imageFile, x, y, spriteScale), alive(true), xSpeed(0), ySpeed(0) {}
  Player(std::vector<std::string> imageFiles, int x, int y, float spriteScale = 1) : Entity(imageFiles, x, y, spriteScale), alive(true), xSpeed(0), ySpeed(0) {}
  Player(std::vector<SpriteFrame> spriteList, int x, int y, float spriteScale = 1) : Entity(spriteList, x, y, spriteScale), alive(true), xSpeed(0), ySpeed(0) {}

  // Player acceleration factor
  const double acceleration = 0.25f;

  // Player max speed
  const double maxSpeed = 10.0f;

  // Gets the current player status
  bool isAlive();

  // Sets the current player status
  void setAlive(bool alive);

  // Updates the player status
  void update();

  // Updates the player status and movement
  void update(bool UP_KEY, bool DOWN_KEY, bool LEFT_KEY, bool RIGHT_KEY, bool SPACE_BAR_KEY);

  // Spawns projectile
  void spawnProjectile(double projectileSpeed, double projectileScale);

  // Sets the player's window reference
  void setWindow(sf::RenderWindow* window);

  // Sets the player's mixer reference
  void setMixer(Mixer* mixer);

  // Set's the player's projectile list reference
  void setProjectileList(std::vector<Projectile*> *projectileList);

  // Reset the player
  void reset();

private:
  // Player alive status
  bool alive;

  // Player speed on X axis
  double xSpeed;

  // Player speed on Y axis
  double ySpeed;

  // Player movement control variables
  bool moveUp, moveDown, moveLeft, moveRight;

  // Player's window reference
  sf::RenderWindow* window;

  // Player's mixer reference
  Mixer* mixer;

  // Player's pointer to projectile list
  std::vector<Projectile*> *projectileList;

  // Projectile spawn fire rate
  const int fireRate = 10;

  // Projectile spawn cooldown
  int fireCooldown = 0;

};

#endif
