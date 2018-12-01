#include "MouseType.h"

// Externs
sf::Clock mouseType::_mouseMoveWaitTime;

/* ----------------------------------------------------------------------------
 * Function:
 *   mouseType(std::pair<int, int>)
 * Description:
 *   The ctor
 * --------------------------------------------------------------------------*/
mouseType::mouseType(std::pair<int, int> pos) {
  _mouseTexture.loadFromFile(assetsObj.getGraphicsName(graphics::TILE_MOUSE));
  _mouseSprite.setTexture(_mouseTexture);
  _mouseSprite.setPosition(pos.first*64, pos.second*64);
  _currentMouseLoc = pos;
}

/* ----------------------------------------------------------------------------
 * Function:
 *   getMouseState()
 *
 * Description:
 *   Gets the current state of the mouse.
 * --------------------------------------------------------------------------*/
mouseStatusEnum mouseType::_getMouseState() const {
  return _mouseState;
}


/* ----------------------------------------------------------------------------
 * Function:
 *   _move()
 * Description:
 *   If the clock can be reseted, reset it and move the mouse a random
 *   location.
 * --------------------------------------------------------------------------*/
void mouseType::_move() {
  auto t = _mouseMoveWaitTime.getElapsedTime().asSeconds();
  if(t > sf::seconds(0.25f).asSeconds()) {
    // Let the randomly generated number  below represent the follow:
    //   0 = Up
    //   1 = Down
    //   2 = Left
    //   3 = Right
    srand(time(NULL));
    unsigned short int move = rand()%4;
    switch(move) {
      case 0:
        _mouseSprite.move(0, -64);
        _currentMouseLoc.first--;
        std::cout << "Mouse moved up\n";
        break;
      case 1:
        _mouseSprite.move(0, 64);
        _currentMouseLoc.first++;
        std::cout << "Mouse moved down\n";
        break;
      case 2:
        _mouseSprite.move(-64, 0);
        _currentMouseLoc.second--;
        std::cout << "cout << Mouse moved left\n";
        break;
      case 3:
        _mouseSprite.move(64, 0);
        _currentMouseLoc.second++;
        std::cout << "cout << Mouse moved right\n";
        break;
    }
    _mouseMoveWaitTime.restart();
  }
  // Draw the mouse
  winObj._getRefSFMLWindow()->draw(_mouseSprite);
}

/* ----------------------------------------------------------------------------
 * Function:
 *   _getMouseLoc()
 * Description:
 *   Gets the std::pair of mouse location
 * --------------------------------------------------------------------------*/
std::pair<int, int> mouseType::_getMouseLoc() const {
  return _currentMouseLoc;
}

/* ----------------------------------------------------------------------------
 * Function:
 *   _setMouseStatus(const mouseStatusEnum&)
 * Description:
 *   Sets the mouse status enum value
 * --------------------------------------------------------------------------*/
void mouseType::_setMouseStatus(const mouseStatusEnum& key) {
  _mouseState = key;
}
