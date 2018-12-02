#ifndef ASSET_H
#define ASSET_H
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

/* ----------------------------------------------------------------------------
 * Enumerators for identifying textures via std::maps
 * --------------------------------------------------------------------------*/
enum class graphics {
  TILE_BRIDGE,
  TILE_WATER,
  TILE_LAND,
  TILE_MOUSE,

  WALLPAPER_TITLE
};

/* ----------------------------------------------------------------------------
 * Enumerators for mouse states.
 * --------------------------------------------------------------------------*/
enum class mouseStatusEnum {
  ALIVE,
  DROWNED,
  ESCAPED,
  STARVED
};

/* ----------------------------------------------------------------------------
 * CLASS NAME:
 *   assets
 * DESCRIPTION:
 *   This class is for managing assets.
 * --------------------------------------------------------------------------*/
class assets {
  public:
    assets();
    virtual ~assets();
    std::string& getGraphicsName(const graphics& key);
    sf::Text& _getText(const mouseStatusEnum& key);
    sf::Font& _getFont() const;
  private:
    static sf::Font _gameFont;
    static sf::Text _textDrowned;
    static sf::Text _textEscaped;
    static sf::Text _textStarved;
    static sf::Text _textAlive;

    // Container to hold graphics. Second key is file loc
    static std::map<graphics, std::string> _assetGraphpics;
    // Container to hold texts based on mouse status
    static std::map<mouseStatusEnum, sf::Text> _assetTexts;
};

/* ----------------------------------------------------------------------------
 * Define externals
 * --------------------------------------------------------------------------*/
extern assets assetsObj;

#endif
