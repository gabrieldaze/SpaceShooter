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

  // Player movement values
  double ySpeed = 0;
  double xSpeed = 0;
  double acceleration = 0.2f;
  double maxSpeed = 10;

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
  sf::RectangleShape background;
  if (backgroundTexture.loadFromFile(CURRENT_DIR + "/assets/sprite/background/desert-background.png")) {
    background.setTexture(&backgroundTexture);
    background.setSize(sf::Vector2f(WIDTH, HEIGHT));
    background.setTextureRect(sf::IntRect(0, 0, WIDTH, HEIGHT));
    backgroundTexture.setRepeated(true);
    const double xScale = (WIDTH + WIDTH * 0.01f) / backgroundTexture.getSize().x;
    const double yScale = HEIGHT / backgroundTexture.getSize().y;
    background.setScale(sf::Vector2f(xScale, yScale));
  }

  // Creates the main window
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Space Shooter");

  // Sets framerate limit to 60 frames per second
  window.setFramerateLimit(60);

  // Initializing the mixer class
  Mixer mixer;

  // Setting the fire sound effect
  if (!mixer.setFireSfx(CURRENT_DIR + "/assets/sfx/Laser_Shoot.wav", 50.0f)) window.close();

  // Setting the explosion sound effect
  if (!mixer.setExplosionSfx(CURRENT_DIR + "/assets/sfx/Explosion.wav", 50.0f)) window.close();

  // Setting the background music
  if (!mixer.setBGM(CURRENT_DIR + "/assets/bgm/astrobdsm.ogg", 30.0f)) window.close();

  // Starts playing the background music
  mixer.getBGMusic().play();

  // Creates new player object
  Player player(playerSpriteList, 0, 0, 1.5f);

  // Sets player position to center of the screen
  player.setPosition(WIDTH / 2 - player.width / 4,
                     HEIGHT / 2 + WIDTH / 4 - player.height / 4);

  // Starts the randomizer
  srand(time(0));

  // Starting game loop
  while (window.isOpen()) {

    // Process events
    handleInput(window);

    // Calculate both X and Y speed
    if (UP_KEY) { ySpeed = ySpeed <= -maxSpeed ? ySpeed : ySpeed - acceleration;  }
    if (DOWN_KEY) { ySpeed = ySpeed >= maxSpeed ? ySpeed : ySpeed + acceleration; }
    if (LEFT_KEY) { xSpeed = xSpeed <= -maxSpeed ? xSpeed : xSpeed - acceleration; }
    if (RIGHT_KEY) { xSpeed = xSpeed >= maxSpeed ? xSpeed : xSpeed + acceleration; }

    // Add friction to movement on Y axis
    if (!UP_KEY && !DOWN_KEY) {
      if (ySpeed != 0) {
        if (ySpeed < 0) ySpeed += acceleration;
        if (ySpeed > 0) ySpeed -= acceleration;
      }
    }

    // Add friction to movement on X axis
    if (!LEFT_KEY && !RIGHT_KEY) {
      if (xSpeed != 0) {
        if (xSpeed < 0) xSpeed += acceleration;
        if (xSpeed > 0) xSpeed -= acceleration;
      }
    }

    if (SPACE_BAR_KEY) {
      if (PROJECTILE_FRAME_COUNTER >= PROJECTILE_DELAY) {
        PROJECTILE_FRAME_COUNTER = 0;
        const double PROJECTILE_SPEED = 3.0f;
        const double PROJECTILE_SCALE = 1.5f;
        projectiles.push_back(createProjectile(
          regularProjectileSpriteList,
          player.getCenter().x - regularProjectileSpriteList[0].getTexture().getSize().x * PROJECTILE_SCALE / 2,
          player.getCenter().y - regularProjectileSpriteList[0].getTexture().getSize().y * PROJECTILE_SCALE,
          PROJECTILE_SPEED,
          PROJECTILE_SCALE));
        mixer.getFireSfx().play();
      } else {
        PROJECTILE_FRAME_COUNTER += 1;
      }
    } else {
      PROJECTILE_FRAME_COUNTER = PROJECTILE_DELAY;
    }

    // Move the player using both current x velocity and y velocity
    player.setPosition(player.position.x + xSpeed, player.position.y + ySpeed);

    // Clear screen
    window.clear();

    // Draw the background
    window.draw(background);

    // Draw the player
    player.draw(window);

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
        if (projectiles[i]->isColiding(*enemies[j])) {
          projectiles[i]->setAlive(false);
          enemies[j]->setAlive(false);
          explosions.push_back(createExplosion(
            explosionSpriteList,
            enemies[j]->getCenter().x - explosionSpriteList[0].getTexture().getSize().x / 2,
            enemies[j]->getCenter().y - explosionSpriteList[0].getTexture().getSize().y / 2,
            2.0f
          ));
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
