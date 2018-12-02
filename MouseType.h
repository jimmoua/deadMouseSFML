#ifndef MOUSE_TYPE_H
#define MOUSE_TYPE_H
#include <time.h>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "asset.h"
#include "log.h"

/* ----------------------------------------------------------------------------
 * CLASS:
 *   mouseType
 * DESCRIPTION:
 *   Class that holds info about the mouse. Or in this case, since I'm too lazy
 *   to make another image, it's just going to be a red slime :)
 * --------------------------------------------------------------------------*/
class mouseType {
  public:
    mouseType(std::pair<int, int>);
    mouseStatusEnum _getMouseState() const;
    std::pair<int, int> _getMouseLoc() const;
    void _move();
    void _setMouseStatus(const mouseStatusEnum&);
    unsigned short int& _getMoves() const;
    void _reset(std::pair<int, int>);
    void _record();
  private:
    static unsigned short int _mouseDeaths;
    static unsigned short int _mouseStarved;
    static unsigned short int _mouseEscaped;
    static unsigned short int _mouseDrowned;
    static unsigned short int _simsRan;
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
    static sf::Texture _mouseTexture;
    static sf::Sprite _mouseSprite;
};

#endif
