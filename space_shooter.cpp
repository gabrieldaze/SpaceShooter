/* Space Shooter C++ Game */

#include <iostream> // for std::cout
#include <vector>   // for std::vector
#include <ctime>    // for time()
#include <cstdlib>  // for srand() and rand()
#include <stdio.h>  // for FILENAME_MAX

#ifdef WINDOWS
 #include <direct.h>
 #define GetCurrentDir _getcwd
#else
 #include <unistd.h>
 #define GetCurrentDir getcwd
#endif

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

Projectile* createProjectile(std::vector<SpriteFrame> spriteList, int x, int y)
{
  Projectile* p = new Projectile(spriteList, x, y);
  return p;
}

Projectile* createProjectile(std::vector<SpriteFrame> spriteList, int x, int y, double speed)
{
  Projectile* p = new Projectile(spriteList, x, y, speed);
  return p;
}

Enemy* createEnemy(std::vector<SpriteFrame> spriteList, int x, int y)
{
  Enemy* e = new Enemy(spriteList, x, y);
  return e;
}

Enemy* createEnemy(std::vector<SpriteFrame> spriteList, int x, int y, double speed)
{
  Enemy* e = new Enemy(spriteList, x, y, speed, 2.0f);
  return e;
}

TemporaryEntity* createExplosion(std::vector<SpriteFrame> spriteList, int x, int y)
{
  TemporaryEntity* e = new TemporaryEntity(spriteList, x, y);
  return e;
}

TemporaryEntity* createExplosion(std::vector<SpriteFrame> spriteList, int x, int y, float spriteScale)
{
  TemporaryEntity* e = new TemporaryEntity(spriteList, x, y, spriteScale);
  return e;
}

int main()
{
  // Gets the current working directory
  char currentPath[FILENAME_MAX];
  GetCurrentDir(currentPath, sizeof(currentPath));
  const std::string CURRENT_DIR = currentPath;
  std::cout << "Current working directory: " << CURRENT_DIR << std::endl;

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

  // Movement key status
  bool UP_KEY    = false;
  bool DOWN_KEY  = false;
  bool LEFT_KEY  = false;
  bool RIGHT_KEY = false;

  // List of projectiles
  std::vector <Projectile*> projectiles;

  // List of enemies
  std::vector <Enemy*> enemies;

  // List of explosions
  std::vector <TemporaryEntity*> explosions;

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
  // mixer.getBGMusic().play();

  std::vector<SpriteFrame> playerSpriteList;
  playerSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/player/player00.png", 5));
  playerSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/player/player01.png", 5));
  playerSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/player/player02.png", 5));
  playerSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/player/player03.png", 5));
  playerSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/player/player04.png", 5));
  playerSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/player/player05.png", 5));
  playerSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/player/player06.png", 5));
  playerSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/player/player07.png", 5));
  playerSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/player/player08.png", 5));
  playerSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/player/player09.png", 5));

  std::vector<SpriteFrame> enemySmallSpriteList;
  enemySmallSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/enemy/enemySmall00.png", 5));
  enemySmallSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/enemy/enemySmall01.png", 5));

  std::vector<SpriteFrame> enemyMediumSpriteList;
  enemyMediumSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/enemy/enemyMedium00.png", 5));
  enemyMediumSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/enemy/enemyMedium01.png", 5));

  std::vector<SpriteFrame> enemyBigSpriteList;
  enemyBigSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/enemy/enemyBig00.png", 5));
  enemyBigSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/enemy/enemyBig01.png", 5));

  std::vector<SpriteFrame> regularProjectileSpriteList;
  regularProjectileSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/projectile/regular00.png", 5));
  regularProjectileSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/projectile/regular01.png", 5));

  std::vector<SpriteFrame> roundedProjectileSpriteList;
  roundedProjectileSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/projectile/rounded00.png", 5));
  roundedProjectileSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/projectile/rounded01.png", 5));

  std::vector<SpriteFrame> explosionSpriteList;
  explosionSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/explosion/explosion00.png", 3));
  explosionSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/explosion/explosion01.png", 3));
  explosionSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/explosion/explosion02.png", 3));
  explosionSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/explosion/explosion03.png", 3));
  explosionSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/explosion/explosion04.png", 3));

  // Creates new player object
  // Player player(CURRENT_DIR + "/assets/sprite/spaceship.png", 0, 0);
  Player player(playerSpriteList, 0, 0);

  // Sets sprite smoothness and scale
  // player.getTexture().setSmooth(false);
  // player.getSprite().setScale(sf::Vector2f(0.5f, 0.5f));

  // Sets player position to center of the screen
  player.setPosition(WIDTH / 2 - player.width / 4,
                     HEIGHT / 2 - player.height / 4);

  // Starts the randomizer
  srand(time(0));

  // Starting game loop
  while (window.isOpen()) {

    // Process events
    sf::Event event;
    while (window.pollEvent(event)) {
      // Close window when exit is clicked
      if (event.type == sf::Event::Closed) window.close();

      // Check if directional key is pressed
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) UP_KEY = true;
        if (event.key.code == sf::Keyboard::Down) DOWN_KEY = true;
        if (event.key.code == sf::Keyboard::Left) LEFT_KEY = true;
        if (event.key.code == sf::Keyboard::Right) RIGHT_KEY = true;
      }

      // Check if directional key is released
      if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) UP_KEY = false;
        if (event.key.code == sf::Keyboard::Down) DOWN_KEY = false;
        if (event.key.code == sf::Keyboard::Left) LEFT_KEY = false;
        if (event.key.code == sf::Keyboard::Right) RIGHT_KEY = false;
        if (event.key.code == sf::Keyboard::Space) {
          projectiles.push_back(createProjectile(
            regularProjectileSpriteList,
            player.getCenter().x - regularProjectileSpriteList[0].getTexture().getSize().x / 2,
            player.getCenter().y - regularProjectileSpriteList[0].getTexture().getSize().y, 3
          ));
          //fireSfx.play();
          mixer.getFireSfx().play();
        }
      }
    }

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

    // Move the player using both current x velocity and y velocity
    player.setPosition(player.position.x + xSpeed, player.position.y + ySpeed);

    // Clear screen
    window.clear();

    // Draw the player
    player.draw(window);

    // Check if the frame counter has reached the enemy delay
    // before spawning an enemy
    if (FRAME_COUNTER >= ENEMY_DELAY) {
      FRAME_COUNTER = 0;
      int xPos = (rand() % (WIDTH - 100)) + 50;
      int yPos = 20;
      // std::cout << "Spawning enemy at xPos: " << xPos << std::endl;
      // if (xPos < 50 || xPos > 750) std::cout << "Spawning off the limits at: " << xPos << std::endl;
      enemies.push_back(createEnemy(enemyBigSpriteList, xPos, yPos, 1));
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
          explosions.push_back(createExplosion(explosionSpriteList, projectiles[i]->position.x, projectiles[i]->position.y, 2.0f));
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
