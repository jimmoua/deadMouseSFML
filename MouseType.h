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
    // The max number of moves the mouse can move before starving
    const unsigned short int _maxMouseMoves = 20;
    static unsigned short int _mouseMoves;

    // The state of the mouse
    static mouseStatusEnum _mouseState;

    // Keeping stack of the mouse location
    static std::pair<int, int> _currentMouseLoc;

    // Use for waiting for mouse to move.
    static sf::Clock _mouseMoveWaitTime;

    // Used to keep track of count and display on SFML window.
    static sf::Text _txtMouseMoves;

    // Mouse images
    static sf::Texture _mouseTextures;
    static sf::Sprite _mouseSprite;
};

#endif
