#ifndef ASSET_H
#define ASSET_H
#include <SFML/Graphics.hpp>
#include <map>

namespace dm {
  enum class graphics {
    TILE_BRIDGE,
    TILE_WATER,
    TILE_LAND,
    TILE_MOUSE,

    WALLPAPER_TITLE
  };

  class assets {
    public:
      assets();
      std::string& getGraphicsName(graphics& key);
    private:
      static sf::Font gameFont;
      
      // Container to hold graphics. Second argument is file loc
      std::map<graphics, std::string> _assetGraphpics;
  };

  // Default ctor
  assets::assets() {
    // Load graphics for tiles and characters.
    _assetGraphpics[graphics::TILE_BRIDGE] = "./assets/tiles/bridge.png";
    _assetGraphpics[graphics::TILE_WATER] = "./assets/tiles/water.png";
    _assetGraphpics[graphics::TILE_LAND] = "./assets/tiles/grass.png";
    _assetGraphpics[graphics::TILE_MOUSE] = "./assets/tiles/red_slime.png";
  }

  std::string& assets::getGraphicsName(graphics& key) {
    return _assetGraphpics[key];
  }

  // Static declarations
  sf::Font assets::gameFont;

  // extern this so accessible by all.
  extern assets assetsObj;
}

#endif
