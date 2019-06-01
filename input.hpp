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
      if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
        UP_KEY = true;
      if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
        DOWN_KEY = true;
      if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
        LEFT_KEY = true;
      if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
        RIGHT_KEY = true;
      if (event.key.code == sf::Keyboard::Space)
        SPACE_BAR_KEY = true;
    }

    // Check if directional key is released
    if (event.type == sf::Event::KeyReleased)
    {
      if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
        UP_KEY = false;
      if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
        DOWN_KEY = false;
      if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
        LEFT_KEY = false;
      if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
        RIGHT_KEY = false;
      if (event.key.code == sf::Keyboard::Space)
        SPACE_BAR_KEY = false;
    }
  }
}

#endif