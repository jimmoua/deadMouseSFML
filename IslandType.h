#ifndef ISLAND_TYPE_H
#define ISLAND_TYPE_H

#include <SFML/Graphics.hpp>
#include "asset.h"
#include "Window.h"
#include <fstream>
#include "log.h"

const unsigned short int MAX_SIZE = 20;
const unsigned short int MIN_SIZE  = 3;
const unsigned short int MAX_BRIDGES = 10;
const unsigned short int MIN_BRIDGES = 2;

class islandType {
  public:
    islandType();
    void drawMap();
    bool getGrid();
    unsigned short int getGridSize();
  private:
    // Textures
    sf::Texture _tGround;
    sf::Texture _tWater;
    sf::Texture _tBridge;

    // Sprites
    sf::Sprite _sGround;
    sf::Sprite _sWater;
    sf::Sprite _sBridge;

    // Grid information
    static std::string mapName;
    unsigned short int gridSize; // Size of grid (row x col)
    int islandMap[MAX_SIZE][MAX_SIZE];
    std::pair<int, int> mouseStartLoc;
    std::pair<int, int> bridgeLoc[MAX_BRIDGES];
    unsigned short int numBridges;
};
#endif
