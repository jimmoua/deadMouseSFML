#ifndef ISLAND_TYPE_H
#define ISLAND_TYPE_H

#include <SFML/Graphics.hpp>
#include "asset.h"
#include "Window.h"
#include <fstream>
#include "log.h"
#include <vector>

/* ----------------------------------------------------------------------------
 * CLASS:
 *   islandType
 * DESCRIPTION:
 *   This class keeps track of what the map or grid.
 * --------------------------------------------------------------------------*/
class islandType {
  public:
    islandType();
    bool init(const std::string&);
    void drawMap();
    unsigned short int getGridSize() const;
    std::pair<int, int> getMouseStartingLoc() const;
    mouseStatusEnum _checkCollisions(std::pair<int, int>, unsigned short int&);
    void _reset();
  private:
    // Grid information checker
    bool getGrid(const std::string&);

    // Textures
    sf::Texture _tGround;
    sf::Texture _tWater;
    sf::Texture _tBridge;

    // Sprites
    sf::Sprite _sGround;
    sf::Sprite _sWater;
    sf::Sprite _sBridge;

    // Grid information
    unsigned short int gridSize; // Size of grid (row x col)
    int islandMap[MAX_SIZE][MAX_SIZE]; // Array used for collision detect
    std::pair<int, int> mouseStartLoc; // Ordered pair of mouse start loc
};
#endif
