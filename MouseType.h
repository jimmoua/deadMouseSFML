#ifndef MOUSE_TYPE_H
#define MOUSE_TYPE_H
#include <time.h>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "asset.h"

/* This is the class that will be dealing with the entity of the mouse. This
 * means that in here, we are handling what the mouse does, its number of
 * moves, its status, etc. It can be thought of as a character class when
 * dealing with RPG. */


// Mouse class
class mouseType {
  public:
    mouseType(std::pair<int, int>);
    mouseStatusEnum _getMouseState() const;
    std::pair<int, int> _getMouseLoc() const;
    void _move();
    void _setMouseStatus(const mouseStatusEnum&);
  private:
    const unsigned short int _maxMouseMoves = 50;
    mouseStatusEnum _mouseState;
    std::pair<int, int> _currentMouseLoc;
    static sf::Clock _mouseMoveWaitTime;

    // Mouse images
    sf::Texture _mouseTexture;
    sf::Sprite _mouseSprite;
};

#endif
