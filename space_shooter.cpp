/* Space Shooter C++ Game */

#include <SFML/Graphics.hpp>
#include <iostream> // for std::cout
#include <vector>   // for std::vector

#include "engine/Entity.cpp"
#include "engine/Player.cpp"
#include "engine/Projectile.cpp"

Projectile* createProjectile(std::string imageFile, int x, int y)
{
  Projectile* p = new Projectile(imageFile, x, y);
  p->getTexture().setSmooth(false);
  return p;
}

int main()
{
  // Window width and height
  const int WIDTH = 800;
  const int HEIGHT = 600;

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

  // Creates the main window
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Space Shooter");

  // Sets framerate limit to 60 frames per second
  window.setFramerateLimit(60);
  
  // Creates new player object
  Player player("spaceship.png", 0, 0);

  // Sets sprite smoothness and scale
  player.getTexture().setSmooth(false);
  player.getSprite().setScale(sf::Vector2f(0.5f, 0.5f));
  
  // Sets player position to center of the screen
  player.setPosition(WIDTH / 2 - player.width / 4, 
                     HEIGHT / 2 - player.height / 4);

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
          projectiles.push_back(createProjectile("projectile.png",
                                                 player.position.x + player.width / 4,
                                                 player.position.y));
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

    // Draw the sprite
    window.draw(player.getSprite());

    player.draw(window);
    
    // Iterate through the projectile vector and draw each projectile
    for (Projectile* p : projectiles) { p->update(3); p->draw(window); }

    // Update the window
    window.display();

  }

  return 0;
}
