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

  mouseType mouseObj(islandObj.getMouseStartingLoc());

  // Init the window and create it inside the init function
  winObj._windowInit(islandObj.getGridSize());
  // After window init, init the assets that need to be init after Window
  assetsObj._init();
  while(winObj._getRefSFMLWindow()->isOpen()) {
    while(winObj._getRefSFMLWindow()->pollEvent(winObj._getEvent())) {
      // Poll the window
      if(winObj._getEvent().type == sf::Event::Closed)
        winObj._getRefSFMLWindow()->close();
    }
    // Paint window black
    winObj._getRefSFMLWindow()->clear(sf::Color::Black);

    // Draw the map
    islandObj.drawMap();

    // Draw the mouse and simulation
    mouseObj._move();

    // Check for collisions
    if(mouseObj._getMouseState() == mouseStatusEnum::ALIVE) {
      mouseObj._setMouseStatus(
          islandObj._checkCollisions(mouseObj._getMouseLoc(),
            mouseObj._getMoves()));
    }
    winObj._getRefSFMLWindow()->draw(assetsObj._getText(mouseObj._getMouseState()));

    // If dead, show reset msg
    if(mouseObj._getMouseState() != mouseStatusEnum::ALIVE) {
      assetsObj._showMsgReset();
      if(assetsObj._getTimer() == 0) {
        mouseObj._reset(islandObj.getMouseStartingLoc());
      }
    }
    // Display the window.
    winObj._getRefSFMLWindow()->display();
  }
  return EXIT_SUCCESS;
}
