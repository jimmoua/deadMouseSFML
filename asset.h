#ifndef ASSET_H
#define ASSET_H
#include <SFML/Graphics.hpp>
#include <map>

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
  private:
    static sf::Font gameFont;
    
    // Container to hold graphics. Second argument is file loc
    std::map<graphics, std::string> _assetGraphpics;
};

// Default ctor
assets::assets() {
}

// Static declarations
sf::Font assets::gameFont;

// extern this so accessible by all.
extern assets assetsObj;

#endif
