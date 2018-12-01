#include "IslandType.h"
#include "Window.h"
#include "asset.h"
#include <iostream>

int main() {
  // Create an object of the window class. Automatically displays too.

  while(winObj._getRefSFMLWindow().isOpen()) {
    while(winObj._getRefSFMLWindow().pollEvent(winObj._getEvent())) {
      // Poll the window
      if(winObj._getEvent().type == sf::Event::Closed)
        winObj._getRefSFMLWindow().close();
    }

    // Paint window black
    winObj._getRefSFMLWindow().clear(sf::Color::Black);

    // What to draw?

    // Display the window.
    winObj._getRefSFMLWindow().display();
  }
  return EXIT_SUCCESS;
}
