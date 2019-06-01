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

TemporaryEntity* createExplosion(std::vector<SpriteFrame> spriteList, int x, int y, float spriteScale)
{
  TemporaryEntity* e = new TemporaryEntity(spriteList, x, y, spriteScale);
  return e;
}

int initialize()
{
  GetCurrentDir(currentPath, sizeof(currentPath));
  CURRENT_DIR = currentPath;

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

  enemySmallSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/enemy/enemySmall00.png", 5));
  enemySmallSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/enemy/enemySmall01.png", 5));

  enemyMediumSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/enemy/enemyMedium00.png", 5));
  enemyMediumSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/enemy/enemyMedium01.png", 5));

  enemyBigSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/enemy/enemyBig00.png", 5));
  enemyBigSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/enemy/enemyBig01.png", 5));

  regularProjectileSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/projectile/regular00.png", 5));
  regularProjectileSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/projectile/regular01.png", 5));

  roundedProjectileSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/projectile/rounded00.png", 5));
  roundedProjectileSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/projectile/rounded01.png", 5));

  explosionSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/explosion/explosion00.png", 3));
  explosionSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/explosion/explosion01.png", 3));
  explosionSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/explosion/explosion02.png", 3));
  explosionSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/explosion/explosion03.png", 3));
  explosionSpriteList.push_back(SpriteFrame(CURRENT_DIR + "/assets/sprite/explosion/explosion04.png", 3));

  return 0;
}
#endif