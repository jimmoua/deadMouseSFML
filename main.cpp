#include "Window.h"
#include "IslandType.h"
#include "asset.h"
#include "MouseType.h"
#include <iostream>

int main(int argc, char* argv[]) {
  // Get the map via IslandType
  islandType islandObj;
  if(argc != 2) {
    std::cerr << "Error: expected one filename. Received: " << argc-1;
    std::cerr << std::endl;
    return -1;
  }
  else if(!islandObj.init(argv[1])) {
    std::cerr << "Unable to load simulation. Check error logs.\n";
    return -1;
  }

  // Create the mouseType object and define its location by getting it from the
  // islandType object.
  mouseType mouseObj(islandObj.getMouseStartingLoc());

  // Init the window by invoking init function of window class.
  winObj._windowInit(islandObj.getGridSize());

  // After window init, init the assets that need to be init after Window
  assetsObj._init();

  // Begin main loop
  while(winObj._getRefSFMLWindow()->isOpen()) {
    while(winObj._getRefSFMLWindow()->pollEvent(winObj._getEvent())) {
      // Poll the window. If SFML window event is close, close the window.
      if(winObj._getEvent().type == sf::Event::Closed)
        winObj._getRefSFMLWindow()->close();
    }

    // Refresh screen black.
    winObj._getRefSFMLWindow()->clear(sf::Color::Black);

    // Draw the map
    islandObj.drawMap();

    // Draw the mouse by moving it.
    mouseObj._move();

    // Check for collisions after moving the mouse. By checking the collisions,
    // we are also checking its status. If it collides with something, then we
    // handle status inside the collision.
    if(mouseObj._getMouseState() == mouseStatusEnum::ALIVE) {
      mouseObj._setMouseStatus(
          islandObj._checkCollisions(mouseObj._getMouseLoc(),
            mouseObj._getMoves()));
    }

    // Draw the text representing current status of mouse.
    winObj._getRefSFMLWindow()->draw(assetsObj._getText(mouseObj._getMouseState()));

    // If dead, show reset message.
    if(mouseObj._getMouseState() != mouseStatusEnum::ALIVE) {
      assetsObj._showMsgReset();
      if(assetsObj._getTimer() == 0) {
        mouseObj._reset(islandObj.getMouseStartingLoc());
      }
    }

    // Display the SFML window.
    winObj._getRefSFMLWindow()->display();
  }

  // SFML window closed, so record the session.
  mouseObj._record();

  return EXIT_SUCCESS;
}
