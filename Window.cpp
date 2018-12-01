#include "Window.h"

sfmlWindowClass winObj;

// Static members
sf::Vector2u sfmlWindowClass::_rWindowSizeResolution;
sf::RenderWindow sfmlWindowClass::_rWindow;

sf::Vector2u sfmlWindowClass::_getWindowResoSize() const {
  return _rWindowSizeResolution;
}

sf::RenderWindow& sfmlWindowClass::_getRefSFMLWindow() {
  return _rWindow;
}

sfmlWindowClass::sfmlWindowClass() {
  // Get a specific resolution...
  unsigned short int x, y;
  std::cout << "Enter in width and height: ";
  std::cin >> x >> y;
  // Each width and height is multiplied by 64 to represent resolution.
  _rWindowSizeResolution.x = x*64;
  _rWindowSizeResolution.y = y*64;

  // Create the SMFL window
  _rWindow.create(
      // Specify a resolution size
      sf::VideoMode(_rWindowSizeResolution.x, _rWindowSizeResolution.y),
      // Window  Title
      "Dead Mouse SFML",
      // Window options
      sf::Style::Close);
}

sf::Event& sfmlWindowClass::_getEvent() {
  return _windowEvent;
}
