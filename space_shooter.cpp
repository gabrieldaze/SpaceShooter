/* Space Shooter C++ Game */

#include <iostream> // for std::cout
#include <vector>   // for std::vector
#include <ctime>    // for time()
#include <cstdlib>  // for srand() and rand()
#include <stdio.h>  // for FILENAME_MAX

#include <SFML/Graphics.hpp>

#include "engine/Entity.cpp"
#include "engine/Player.cpp"
#include "engine/Projectile.cpp"
#include "engine/Enemy.cpp"
#include "engine/TemporaryEntity.cpp"
#include "engine/Mixer.cpp"
#include "engine/AnimatedSprite.cpp"
#include "engine/Animation.cpp"
#include "engine/SpriteFrame.cpp"
#include "loader.hpp"
#include "input.hpp"

int main()
{
  // Initializes the sprite animations
  initialize();

  // Window width and height
  const int WIDTH = 800;
  const int HEIGHT = 600;

  // Enemy spawn delay
  const int ENEMY_DELAY = 120;
  int FRAME_COUNTER = 0;

  // Projectile spawn delay
  const int PROJECTILE_DELAY = 10;
  int PROJECTILE_FRAME_COUNTER = 0;

  // List of projectiles
  std::vector <Projectile*> projectiles;

  // List of enemies
  std::vector <Enemy*> enemies;

  // List of explosions
  std::vector <TemporaryEntity*> explosions;

  // Background texture and shape
  sf::Texture backgroundTexture;
  sf::Sprite background;
  if (backgroundTexture.loadFromFile("assets/sprite/background/space-background.png")) {
    background.setTexture(backgroundTexture);
    // background.setSize(sf::Vector2f(WIDTH, HEIGHT));
    background.setTextureRect(sf::IntRect(0, 0, WIDTH, HEIGHT));
    backgroundTexture.setRepeated(true);
    const double xScale = (WIDTH + WIDTH * 0.01f) / backgroundTexture.getSize().x;
    const double yScale = (HEIGHT + HEIGHT * 0.01f) / backgroundTexture.getSize().y;
    background.setScale(sf::Vector2f(xScale, yScale));

  }

  // Creates the main window
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Space Shooter");

  // Sets framerate limit to 60 frames per second
  window.setFramerateLimit(60);

  // Initializing the mixer class
  Mixer mixer;

  // Setting the fire sound effect
  if (!mixer.setFireSfx("assets/sfx/Laser_Shoot.wav", 50.0f)) window.close();

  // Setting the explosion sound effect
  if (!mixer.setExplosionSfx("assets/sfx/Explosion.wav", 50.0f)) window.close();

  // Setting the background music
  // if (!mixer.setBGM("assets/bgm/astrobdsm.ogg", 30.0f)) window.close();

  // Starts playing the background music
  // mixer.getBGMusic().play();

  // Creates new player object
  Player player(playerSpriteList, 0, 0, 1.5f);

  // Sets the player's window reference
  player.setWindow(&window);

  // Sets player position to the initial position
  player.reset();

  // Sets the player's mixer reference
  player.setMixer(&mixer);

  player.setProjectileList(&projectiles);

  // Starts the randomizer
  srand(time(0));

  // Starting game loop
  while (window.isOpen()) {

    // Process events
    handleInput(window);

    // Update the player status and position
    player.update(UP_KEY, DOWN_KEY, LEFT_KEY, RIGHT_KEY, SPACE_BAR_KEY);

    // Clear screen
    window.clear();

    // Draw the background
    window.draw(background);

    // Draw the player
    if (player.isAlive()) player.draw(window);

    // Check if the frame counter has reached the enemy delay
    // before spawning an enemy
    if (FRAME_COUNTER >= ENEMY_DELAY) {
      FRAME_COUNTER = 0;
      double xPos = (rand() % (WIDTH - 100)) + 50; int yPos = 10;
      int randomSprite = (rand() % 3) + 1;
      // double randomScale = (rand() % 2) + 1;
      enemies.push_back(createEnemy(randomSprite, xPos, yPos, 1, 1.5f));
    } else {
      FRAME_COUNTER += 1;
    }

    // Iterate through the projectile vector and draw each projectile
    for (int i = 0; i < projectiles.size(); i++) {
      projectiles[i]->update();
      for (int j = 0; j < enemies.size(); j++) {
        if (projectiles[i]->isColliding(*enemies[j])) {
          projectiles[i]->setAlive(false);
          enemies[j]->setAlive(false);
          const double xPos = enemies[j]->getCenter().x - explosionSpriteList[0].getTexture().getSize().x / 2;
          const double yPos = enemies[j]->getCenter().y - explosionSpriteList[0].getTexture().getSize().y / 2;
          createExplosion(explosions, explosionSpriteList, xPos, yPos, 2.0f);
          mixer.getExplosionSfx().play();
        }
      }
      if (projectiles[i]->isAlive()) {
        projectiles[i]->draw(window);
      } else {
        projectiles[i] = nullptr;
        projectiles.erase(projectiles.begin() + i);
      }
    }

    // Iterate through the enemy vector and draw each enemy
    for (int i = 0; i < enemies.size(); i++) {
      enemies[i]->update();
      if (enemies[i]->position.y >= HEIGHT - enemies[i]->getSize().height) enemies[i]->setAlive(false);
      if (enemies[i]->isAlive()) {
        enemies[i]->draw(window);
        if (enemies[i]->isColliding(player) && player.isAlive()) {
          player.setAlive(false);
          const double xPos = player.getCenter().x - explosionSpriteList[0].getTexture().getSize().x / 2;
          const double yPos = player.getCenter().y - explosionSpriteList[0].getTexture().getSize().y / 2;
          createExplosion(explosions, explosionSpriteList, xPos, yPos, 3.0f);
          mixer.getExplosionSfx().play();
        }
      } else {
        enemies[i] = nullptr;
        enemies.erase(enemies.begin() + i);
      }
    }

    // Iterate through the explosion vector and draw
    for (int i = 0; i < explosions.size(); i++) {
      explosions[i]->update();
      if (explosions[i]->isAlive()) {
        explosions[i]->draw(window);
      } else {
        explosions[i] = nullptr;
        explosions.erase(explosions.begin() + i);
      }
    }

    // Update the window
    window.display();

  }

  return 0;
}
