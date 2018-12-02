#include "Window.h"

// Extern object (must be defined here)
sfmlWindowClass winObj;

// Static members (must be declared here)
sf::Vector2u sfmlWindowClass::_rWindowSizeResolution;
sf::RenderWindow* sfmlWindowClass::_rWindow;
sf::Event sfmlWindowClass:: _windowEvent;

sf::Vector2u sfmlWindowClass::_getWindowResoSize() const {
  return _rWindowSizeResolution;
}

sf::RenderWindow* sfmlWindowClass::_getRefSFMLWindow() {
  return _rWindow;
}

sfmlWindowClass::sfmlWindowClass() {
  _rWindow = new sf::RenderWindow;
}

sfmlWindowClass::~sfmlWindowClass() {
  delete _rWindow;
}

sf::Event& sfmlWindowClass::_getEvent() {
  return _windowEvent;
}

void sfmlWindowClass::_windowInit(const unsigned short int& reso) {
  // Each width and height is multiplied by 64 to represent resolution.
  _rWindowSizeResolution.x = (reso)*64;
  _rWindowSizeResolution.y = (reso)*64;

  // Create the SMFL window
  _rWindow->create(
      // Specify a resolution size
      sf::VideoMode(_rWindowSizeResolution.x, _rWindowSizeResolution.y),
      // Window  Title
      "Dead Mouse SFML",
      // Window options
      sf::Style::Close);
}
