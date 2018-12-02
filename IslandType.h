#ifndef ISLAND_TYPE_H
#define ISLAND_TYPE_H

#include <SFML/Graphics.hpp>
#include "asset.h"
#include "Window.h"
#include <fstream>
#include "log.h"
#include <vector>

const unsigned short int MAX_SIZE = 20;
const unsigned short int MIN_SIZE  = 3;
const unsigned short int MAX_BRIDGES = 15;
const unsigned short int MIN_BRIDGES = 2;

class islandType {
  public:
    islandType();
    bool init();
    void drawMap();
    unsigned short int getGridSize();
    std::pair<int, int> getMouseStartingLoc();
    mouseStatusEnum _checkCollisions(std::pair<int, int>);
    
    friend void debug(islandType&);
  private:
    // Grid information checker
    bool getGrid();

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

    // SFML collisions
    static std::vector<sf::RectangleShape> _colWater;
    static std::vector<sf::RectangleShape> _colBridge;
    static std::vector<sf::RectangleShape> _colOther;
};
#endif
