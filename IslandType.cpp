#include "IslandType.h"

islandType::islandType() {
  // Load the textures in
  _tGround.loadFromFile(assetsObj.getGraphicsName(graphics::TILE_LAND));
  _tWater.loadFromFile(assetsObj.getGraphicsName(graphics::TILE_WATER));
  _tBridge.loadFromFile(assetsObj.getGraphicsName(graphics::TILE_BRIDGE));

  // Set Sprites
  _sGround.setTexture(_tGround);
  _sWater.setTexture(_tWater);
  _sBridge.setTexture(_tBridge);
}

void islandType::drawMap() {
  const sf::Vector2u = winObj._getWindowResoSize();
}
