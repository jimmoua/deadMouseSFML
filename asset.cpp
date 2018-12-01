#include "asset.h"

// Static must be defined here
sf::Font assets::gameFont;

// Extern
assets assetsObj;

// Default ctor
assets::assets() {
  // Load graphics for tiles and characters.
  _assetGraphpics[graphics::TILE_BRIDGE] = "./assets/tiles/bridge.png";
  _assetGraphpics[graphics::TILE_WATER] = "./assets/tiles/water.png";
  _assetGraphpics[graphics::TILE_LAND] = "./assets/tiles/grass.png";
  _assetGraphpics[graphics::TILE_MOUSE] = "./assets/tiles/red_slime.png";
}

std::string& assets::getGraphicsName(const graphics& key) {
  return _assetGraphpics[key];
}
