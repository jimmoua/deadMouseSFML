#ifndef ISLAND_TYPE_H
#define ISLAND_TYPE_H

#include <SFML/Graphics.hpp>
#include "asset.h"
#include "Window.h"

class islandType {
  public:
    islandType();
    void drawMap();
  private:
    // Textures
    sf::Texture _tGround;
    sf::Texture _tWater;
    sf::Texture _tBridge;

    // Sprites
    sf::Sprite _sGround;
    sf::Sprite _sWater;
    sf::Sprite _sBridge;
};
#endif
