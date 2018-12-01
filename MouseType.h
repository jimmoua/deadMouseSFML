#ifndef MOUSE_TYPE_H
#define MOUSE_TYPE_H
#include <SFML/Graphics.hpp>

/* This is the class that will be dealing with the entity of the mouse. This
 * means that in here, we are handling what the mouse does, its number of
 * moves, its status, etc. It can be thought of as a character class when
 * dealing with RPG. */

// Define some nice status for the mouse
enum class mouseStatusEnum {
  ALIVE,
  DROWNED,
  ESCAPED,
  STARVED
};

// Mouse class
class mouseType {
  public:
    mouseStatusEnum getMouseState() const;
  private:
    const unsigned short int maxMouseMoves = 50;
    mouseStatusEnum mouseState;
    std::pair<int, int> currentMouseLoc;
};

#endif
