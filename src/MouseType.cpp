#include "../include/MouseType.h"


/* ----------------------------------------------------------------------------
 * Static Declarations
 * --------------------------------------------------------------------------*/
sf::Clock mouseType::_mouseMoveWaitTime;
unsigned short int mouseType::_mouseMoves;
unsigned short int mouseType::_mouseDeaths;
unsigned short int mouseType::_mouseStarved;
unsigned short int mouseType::_mouseEscaped;
unsigned short int mouseType::_mouseDrowned;
unsigned short int mouseType::_simsRan;
mouseStatusEnum mouseType::_mouseState;
std::pair<int, int> mouseType::_currentMouseLoc;
sf::Text mouseType::_txtMouseMoves;
sf::Texture mouseType::_mouseTexture;
sf::Sprite mouseType::_mouseSprite;

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   mouseType(std::pair<int, int>)
 * DESCRIPTION:
 *   The ctor. The argument is the mouse position that is handed from the
 *   getGrid function from IslandType header.
 * --------------------------------------------------------------------------*/
mouseType::mouseType(std::pair<int, int> pos) {
  // Define some things for the mouse here.
  _mouseDeaths = 0;
  _mouseStarved = 0;
  _mouseEscaped = 0;
  _simsRan = 0;
  _mouseMoves = 0;
  _mouseState = mouseStatusEnum::ALIVE;
  _mouseTexture.loadFromFile(assetsObj.getGraphicsName(graphics::TILE_MOUSE));
  _mouseSprite.setTexture(_mouseTexture);
  _mouseSprite.setPosition((pos.first-1)*__SCALE__, (pos.second+1)*__SCALE__);
  // Scale by half since trying to get 32. The png image is 64x64
  _mouseSprite.scale(0.5f, 0.5f);
  _currentMouseLoc = pos;

  // Define the text for mouse move counter
  _txtMouseMoves.setFont(assetsObj._getFont());
  _txtMouseMoves.setOutlineThickness(5u);
  _txtMouseMoves.setString(std::to_string(_mouseMoves));
  _txtMouseMoves.setFillColor(sf::Color::White);
  _txtMouseMoves.setOutlineColor(sf::Color::Black);
  _txtMouseMoves.setPosition(16, 96);
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   getMouseState()
 * DESCRIPTION:
 *   Gets the current state of the mouse.
 * --------------------------------------------------------------------------*/
mouseStatusEnum mouseType::_getMouseState() const {
  return _mouseState;
}


/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _move()
 * DESCRIPTION:
 *   If the clock can be reseted, reset it and move the mouse a random
 *   location. The mouse is only moved if the status on it is still alive.
 *   Otherwise, the mouse is just drawn (if not moving its last location when
 *   it was alive is drawn).
 * --------------------------------------------------------------------------*/
void mouseType::_move() {
  // If the mouse is still alive, move it.
  if(_mouseState == mouseStatusEnum::ALIVE) {
    auto t = _mouseMoveWaitTime.getElapsedTime().asSeconds();
    if(t > sf::seconds(0.10f).asSeconds()) {
      // Let the randomly generated number  below represent the follow:
      //   0 = Up
      //   1 = Down
      //   2 = Left
      //   3 = Right
      srand(time(0)); // For random number
      unsigned short int move = rand()%4;
      switch(move) {
        case 0:
          _mouseSprite.move(0, -__SCALE__);
          _currentMouseLoc.first--;
          std::cout << "Mouse moved up\n";
          break;
        case 1:
          _mouseSprite.move(0, __SCALE__);
          _currentMouseLoc.first++;
          std::cout << "Mouse moved down\n";
          break;
        case 2:
          _mouseSprite.move(-__SCALE__, 0);
          _currentMouseLoc.second--;
          std::cout << "Mouse moved left\n";
          break;
        case 3:
          _mouseSprite.move(__SCALE__, 0);
          _currentMouseLoc.second++;
          std::cout << "Mouse moved right\n";
          break;
        default:
          std::cerr << "No define\n";
      }
      _mouseMoveWaitTime.restart();
      _mouseMoves++;
      _txtMouseMoves.setString(std::to_string(_mouseMoves));
    }
  }

  // Draw the mouse
  winObj._getRefSFMLWindow()->draw(_mouseSprite);

  // Draw the total number of moves
  winObj._getRefSFMLWindow()->draw(_txtMouseMoves);
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _getMouseLoc()
 * DESCRIPTION:
 *   Gets the std::pair of mouse location
 * --------------------------------------------------------------------------*/
std::pair<int, int> mouseType::_getMouseLoc() const {
  return _currentMouseLoc;
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _setMouseStatus(const mouseStatusEnum&)
 * DESCRIPTION:
 *   Sets the mouse status enum value
 * --------------------------------------------------------------------------*/
void mouseType::_setMouseStatus(const mouseStatusEnum& key) {
  _mouseState = key;
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _getMoves() const
 * DESCRIPTION:
 *   Gets number of mouse moves. Fn needed for status checking in IslandType
 * --------------------------------------------------------------------------*/
unsigned short int& mouseType::_getMoves() const {
  return _mouseMoves;
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _reset(std::pair<int, int>&)
 * DESCRIPTION:
 *   Resets the mouse position and number of moves. It is called in main. If
 *   this reset is called, that means we should increment the numbers of
 *   whatever its status was by one and sims by 1.
 * --------------------------------------------------------------------------*/
void mouseType::_reset(std::pair<int, int> pos) {
  _mouseMoves = 0;
  _currentMouseLoc = pos;
  _mouseSprite.setPosition((pos.first-1)*__SCALE__, (pos.second+1)*__SCALE__);

  // Increment identifying status
  switch(_mouseState) {
    case mouseStatusEnum::ALIVE:
      break;
    case mouseStatusEnum::DROWNED:
      _mouseDrowned++;
      break;
    case mouseStatusEnum::ESCAPED:
      _mouseEscaped++;
      break;
    case mouseStatusEnum::STARVED:
      _mouseStarved++;
      break;
  }
  _simsRan++;
  _mouseState = mouseStatusEnum::ALIVE;
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _record()
 * DESCRIPTION:
 *   If the window is exited, record the simulation of the mouse.
 * --------------------------------------------------------------------------*/
void mouseType::_record() {
  // Create string so we can append status to it.
  std::string m("\0");

  m.append("Mouse starved: ");
  m.append(std::to_string(_mouseStarved) + " times.\n");

  m.append("Mouse escaped: ");
  m.append(std::to_string(_mouseEscaped) + " times.\n");

  m.append("Mouse drowned: ");
  m.append(std::to_string(_mouseDrowned) + " times.\n");

  m.append("Total simulations ran: ");
  m.append(std::to_string(_simsRan));

  logger.session(m);
}
