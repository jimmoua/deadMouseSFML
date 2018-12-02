#ifndef ASSET_H
#define ASSET_H
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

enum class graphics {
  TILE_BRIDGE,
  TILE_WATER,
  TILE_LAND,
  TILE_MOUSE,

  WALLPAPER_TITLE
};

// Define some nice status for the mouse
enum class mouseStatusEnum {
  ALIVE,
  DROWNED,
  ESCAPED,
  STARVED
};

class assets {
  public:
    assets();
    std::string& getGraphicsName(const graphics& key);
    sf::Text& _getText(const mouseStatusEnum& key);
  private:
    static sf::Font _gameFont;
    static sf::Text _textDrowned;
    static sf::Text _textEscaped;
    static sf::Text _textStarved;

    // Container to hold graphics. Second argument is file loc
    std::map<graphics, std::string> _assetGraphpics;
    std::map<mouseStatusEnum, sf::Text*> _assetTexts;
};

// Externs
extern assets assetsObj;

#endif
