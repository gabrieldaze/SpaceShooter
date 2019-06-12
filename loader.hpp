// loader_hpp

#ifndef loader_hpp
#define loader_hpp

#include <SFML/Graphics.hpp>

#include "engine/SpriteFrame.hpp"
#include "engine/Projectile.hpp"
#include "engine/Enemy.hpp"
#include "engine/TemporaryEntity.hpp"

#ifdef WINDOWS
 #include <direct.h>
 #define GetCurrentDir _getcwd
#else
 #include <unistd.h>
 #define GetCurrentDir getcwd
#endif

#include <vector>

char currentPath[FILENAME_MAX];
std::string CURRENT_DIR;

std::vector<SpriteFrame> playerSpriteList;
std::vector<SpriteFrame> enemySmallSpriteList;
std::vector<SpriteFrame> enemyMediumSpriteList;
std::vector<SpriteFrame> enemyBigSpriteList;
std::vector<SpriteFrame> regularProjectileSpriteList;
std::vector<SpriteFrame> roundedProjectileSpriteList;
std::vector<SpriteFrame> explosionSpriteList;

Projectile* createProjectile(std::vector<SpriteFrame> spriteList, int x, int y, double speed, float spriteScale)
{
  Projectile* p = new Projectile(spriteList, x, y, speed, spriteScale);
  return p;
}

Enemy* createEnemy(int randomSprite, int x, int y, double speed, float spriteScale)
{
  Enemy* e;
  switch (randomSprite) {
    case 1:
      e = new Enemy(enemySmallSpriteList, x, y, speed, spriteScale);
      break;
    case 2:
      e = new Enemy(enemyMediumSpriteList, x, y, speed, spriteScale);
      break;
    case 3:
      e = new Enemy(enemyBigSpriteList, x, y, speed, spriteScale);
      break;
    default:
      e = new Enemy(enemySmallSpriteList, x, y, speed, spriteScale);
  }
  return e;
}

// TemporaryEntity* createExplosion(std::vector<SpriteFrame> spriteList, int x, int y, float spriteScale)
// {
//   TemporaryEntity* e = new TemporaryEntity(spriteList, x, y, spriteScale);
//   return e;
// }

void createExplosion(std::vector<TemporaryEntity*>& explosions, std::vector<SpriteFrame> &spriteList, double x, double y, float spriteScale)
{
  TemporaryEntity* e = new TemporaryEntity(spriteList, x, y, spriteScale);
  explosions.push_back(e);
}

int initialize()
{
  GetCurrentDir(currentPath, sizeof(currentPath));
  CURRENT_DIR = currentPath;

  // playerSpriteList.push_back(SpriteFrame("./assets/sprite/player/player_ship01.png", 5));
  // playerSpriteList.push_back(SpriteFrame("./assets/sprite/player/player_ship02.png", 5));
  // playerSpriteList.push_back(SpriteFrame("./assets/sprite/player/player_ship03.png", 5));
  // playerSpriteList.push_back(SpriteFrame("./assets/sprite/player/player_ship04.png", 5));
  // playerSpriteList.push_back(SpriteFrame("./assets/sprite/player/player_ship05.png", 5));
  playerSpriteList.push_back(SpriteFrame("./assets/sprite/player/player_ship_alt2_01.png", 5));
  playerSpriteList.push_back(SpriteFrame("./assets/sprite/player/player_ship_alt2_02.png", 5));
  playerSpriteList.push_back(SpriteFrame("./assets/sprite/player/player_ship_alt2_03.png", 5));
  playerSpriteList.push_back(SpriteFrame("./assets/sprite/player/player_ship_alt2_04.png", 5));

  enemySmallSpriteList.push_back(SpriteFrame("./assets/sprite/enemy/enemy_big01.png", 5));
  enemySmallSpriteList.push_back(SpriteFrame("./assets/sprite/enemy/enemy_big02.png", 5));
  enemySmallSpriteList.push_back(SpriteFrame("./assets/sprite/enemy/enemy_big03.png", 5));
  enemySmallSpriteList.push_back(SpriteFrame("./assets/sprite/enemy/enemy_big04.png", 5));

  enemyMediumSpriteList.push_back(SpriteFrame("./assets/sprite/enemy/enemy_big01.png", 5));
  enemyMediumSpriteList.push_back(SpriteFrame("./assets/sprite/enemy/enemy_big02.png", 5));
  enemyMediumSpriteList.push_back(SpriteFrame("./assets/sprite/enemy/enemy_big03.png", 5));
  enemyMediumSpriteList.push_back(SpriteFrame("./assets/sprite/enemy/enemy_big04.png", 5));

  enemyBigSpriteList.push_back(SpriteFrame("./assets/sprite/enemy/enemy_big01.png", 5));
  enemyBigSpriteList.push_back(SpriteFrame("./assets/sprite/enemy/enemy_big02.png", 5));
  enemyBigSpriteList.push_back(SpriteFrame("./assets/sprite/enemy/enemy_big03.png", 5));
  enemyBigSpriteList.push_back(SpriteFrame("./assets/sprite/enemy/enemy_big04.png", 5));

  regularProjectileSpriteList.push_back(SpriteFrame("./assets/sprite/projectile/regular00.png", 5));
  regularProjectileSpriteList.push_back(SpriteFrame("./assets/sprite/projectile/regular01.png", 5));

  roundedProjectileSpriteList.push_back(SpriteFrame("./assets/sprite/projectile/rounded00.png", 5));
  roundedProjectileSpriteList.push_back(SpriteFrame("./assets/sprite/projectile/rounded01.png", 5));

  explosionSpriteList.push_back(SpriteFrame("./assets/sprite/explosion/explosion00.png", 3));
  explosionSpriteList.push_back(SpriteFrame("./assets/sprite/explosion/explosion01.png", 3));
  explosionSpriteList.push_back(SpriteFrame("./assets/sprite/explosion/explosion02.png", 3));
  explosionSpriteList.push_back(SpriteFrame("./assets/sprite/explosion/explosion03.png", 3));
  explosionSpriteList.push_back(SpriteFrame("./assets/sprite/explosion/explosion04.png", 3));

  return 0;
}
#endif