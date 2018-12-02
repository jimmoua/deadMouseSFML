#include "../include/Window.h"

/* ----------------------------------------------------------------------------
 * Define externs here
 * --------------------------------------------------------------------------*/
sfmlWindowClass winObj;

/* ----------------------------------------------------------------------------
 * Static class members of sfmlWindowClass defined here
 * --------------------------------------------------------------------------*/
sf::Vector2u sfmlWindowClass::_rWindowSizeResolution;
sf::RenderWindow* sfmlWindowClass::_rWindow = nullptr;
sf::Event sfmlWindowClass:: _windowEvent;

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _getWindowResoSize()
 * DESCRIPTION:
 *   Gets the window reso.
 * --------------------------------------------------------------------------*/
sf::Vector2u sfmlWindowClass::_getWindowResoSize() const {
  return _rWindowSizeResolution;
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _getRefSFMLWindow()
 * DESCRIPTION:
 *   Gets the reference of SFML window
 * --------------------------------------------------------------------------*/
sf::RenderWindow* sfmlWindowClass::_getRefSFMLWindow() {
  return _rWindow;
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   sfmlWindowClass()
 * DESCRIPTION:
 *   Default ctor. Dynamically allocates SFML window. Needed to do this because
 *   giving seg faults if not.
 * --------------------------------------------------------------------------*/
sfmlWindowClass::sfmlWindowClass() {
  _rWindow = new sf::RenderWindow;
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   ~sfmlWindowClass()
 * DESCRIPTION:
 *   Dtor of the class. Dealloc the SFML window
 * --------------------------------------------------------------------------*/
sfmlWindowClass::~sfmlWindowClass() {
  delete _rWindow;
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _getEvent()
 * DESCRIPTION:
 *   Gets the window event.
 * --------------------------------------------------------------------------*/
sf::Event& sfmlWindowClass::_getEvent() {
  return _windowEvent;
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _windowInit(const unsigned short int&)
 * DESCRIPTION:
 *   Inits the window with the first argument.
 * --------------------------------------------------------------------------*/
void sfmlWindowClass::_windowInit(const unsigned short int& reso) {
  // Each width and height is multiplied by 64 to represent resolution.
  _rWindowSizeResolution.x = (reso)*__SCALE__;
  _rWindowSizeResolution.y = (reso)*__SCALE__;

  // Create the SMFL window
  _rWindow->create(
      // Specify a resolution size
      sf::VideoMode(_rWindowSizeResolution.x, _rWindowSizeResolution.y),
      // Window  Title
      "Dead Mouse SFML",
      // Window options
      sf::Style::Close);
  _rWindow->setFramerateLimit(60u);
}
