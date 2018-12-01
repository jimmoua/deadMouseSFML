#ifndef WINDOW_h
#define WINDOW_h
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <string>

class sfmlWindowClass {
  public:
    sfmlWindowClass();
    sf::Vector2u _getWindowResoSize() const;
    sf::RenderWindow& _getRefSFMLWindow();
  private:
    sf::RenderWindow _rWindow;
    sf::Vector2u _rWindowSizeResolution = sf::Vector2u(480, 640);
};

sf::Vector2u sfmlWindowClass::_getWindowResoSize() const {
  return _rWindowSizeResolution;
}

sf::RenderWindow& sfmlWindowClass::_getRefSFMLWindow() {
  return _rWindow;
}

sfmlWindowClass::sfmlWindowClass() {
  _rWindow.create(
      // Specify a resolution size
      sf::VideoMode(_rWindowSizeResolution.x, _rWindowSizeResolution.y),
      // Window  Title
      "Dead Mouse SFML",
      // Window options
      sf::Style::Close);
}

#endif
