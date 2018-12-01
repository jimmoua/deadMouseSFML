#include "IslandType.h"
#include "Window.h"

int main() {
  // TODO: Get a working displaying window that can loop

  // Create an object of the window class. Automatically displays too.
  sfmlWindowClass objWin;

  while(objWin._getRefSFMLWindow().isOpen()) {
    while(objWin._getRefSFMLWindow().pollEvent(objWin._getEvent())) {
      if(objWin._getEvent().type == sf::Event::Closed)
        objWin._getRefSFMLWindow().close();
    }
  }
  return EXIT_SUCCESS;
}
