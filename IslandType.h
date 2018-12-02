#ifndef ISLAND_TYPE_H
#define ISLAND_TYPE_H

#include <SFML/Graphics.hpp>
#include "asset.h"
#include "Window.h"
#include <fstream>
#include "log.h"
#include <vector>

/* ----------------------------------------------------------------------------
 * Declare some const variables here. These indicate the max and min values
 * that a map is required to have to be properly loaded.
 * --------------------------------------------------------------------------*/
const unsigned short int MAX_SIZE = 20;
const unsigned short int MIN_SIZE  = 3;
const unsigned short int MAX_BRIDGES = 15;
const unsigned short int MIN_BRIDGES = 2;

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
    std::pair<int, int> getMouseStartingLoc();
    mouseStatusEnum _checkCollisions(std::pair<int, int>);
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
