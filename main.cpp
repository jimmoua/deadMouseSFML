#include "IslandType.h"
#include "Window.h"
#include "asset.h"

int main() {
  // TODO: Get a working displaying window that can loop

  // Create an object of the window class. Automatically displays too.
  sfmlWindowClass objWin;

  while(objWin._getRefSFMLWindow().isOpen()) {
    while(objWin._getRefSFMLWindow().pollEvent(objWin._getEvent())) {
      // Poll the window
      if(objWin._getEvent().type == sf::Event::Closed)
        objWin._getRefSFMLWindow().close();
    }

    // Paint window black
    objWin._getRefSFMLWindow().clear(sf::Color::Black);

    // What to draw?

    // Display the window.
    objWin._getRefSFMLWindow().display();
  }
  return EXIT_SUCCESS;
}
