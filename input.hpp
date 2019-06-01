// input_hpp

#ifndef input_hpp
#define input_hpp

#include <SFML/Graphics.hpp>
#include "loader.hpp"

// Movement key status
bool UP_KEY    = false;
bool DOWN_KEY  = false;
bool LEFT_KEY  = false;
bool RIGHT_KEY = false;
bool SPACE_BAR_KEY = false;

void handleInput(sf::RenderWindow &window)
{
  sf::Event event;
  while (window.pollEvent(event))
  {
    // Close window when exit is clicked
    if (event.type == sf::Event::Closed)
      window.close();

    // Check if directional key is pressed
    if (event.type == sf::Event::KeyPressed)
    {
      if (event.key.code == sf::Keyboard::Up)
        UP_KEY = true;
      if (event.key.code == sf::Keyboard::Down)
        DOWN_KEY = true;
      if (event.key.code == sf::Keyboard::Left)
        LEFT_KEY = true;
      if (event.key.code == sf::Keyboard::Right)
        RIGHT_KEY = true;
      if (event.key.code == sf::Keyboard::Space)
        SPACE_BAR_KEY = true;
    }

    // Check if directional key is released
    if (event.type == sf::Event::KeyReleased)
    {
      if (event.key.code == sf::Keyboard::Up)
        UP_KEY = false;
      if (event.key.code == sf::Keyboard::Down)
        DOWN_KEY = false;
      if (event.key.code == sf::Keyboard::Left)
        LEFT_KEY = false;
      if (event.key.code == sf::Keyboard::Right)
        RIGHT_KEY = false;
      if (event.key.code == sf::Keyboard::Space)
        SPACE_BAR_KEY = false;
    }
  }
}

#endif