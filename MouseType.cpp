#include "MouseType.h"

// Externs
sf::Clock mouseType::_mouseMoveWaitTime;

/* ----------------------------------------------------------------------------
 * Function:
 *   mouseType(std::pair<int, int>)
 * Description:
 *   Default ctor
 * --------------------------------------------------------------------------*/
mouseType::mouseType(std::pair<int, int> pos) {
  _mouseTexture.loadFromFile(assetsObj.getGraphicsName(graphics::TILE_MOUSE));
  _mouseSprite.setTexture(_mouseTexture);
  _mouseSprite.setPosition(pos.first*64, pos.second*64);
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
 *   resetWaitTime()
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
        _mouseSprite.move(0, 64);
        break;
      case 1:
        _mouseSprite.move(0, -64);
        break;
      case 2:
        _mouseSprite.move(64, 0);
        break;
      case 3:
        _mouseSprite.move(-64, 0);
        break;
    }
    _mouseMoveWaitTime.restart();
  }
  // Draw the mouse
  winObj._getRefSFMLWindow()->draw(_mouseSprite);
}
