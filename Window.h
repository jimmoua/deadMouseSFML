#ifndef WINDOW_h
#define WINDOW_h
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <string>
#include <iostream>

class sfmlWindowClass {
  public:
    sfmlWindowClass();
    sf::Vector2u _getWindowResoSize() const;
    sf::RenderWindow& _getRefSFMLWindow();
    sf::Event& _getEvent();
  private:
    static sf::RenderWindow _rWindow;
    static sf::Vector2u _rWindowSizeResolution;
    sf::Event _windowEvent; // Use this to poll windows in different states
};

// Externs
extern sfmlWindowClass winObj;


#endif
