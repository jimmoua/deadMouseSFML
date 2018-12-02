#include "asset.h"

// Static must be defined here
sf::Font assets::_gameFont;
sf::Text assets::_textDrowned;
sf::Text assets::_textEscaped;
sf::Text assets::_textStarved;


// Extern
assets assetsObj;

// Default ctor
assets::assets() {
  // Load graphics for tiles and characters.
  _assetGraphpics[graphics::TILE_BRIDGE] = "./assets/tiles/bridge.png";
  _assetGraphpics[graphics::TILE_WATER] = "./assets/tiles/water.png";
  _assetGraphpics[graphics::TILE_LAND] = "./assets/tiles/grass.png";
  _assetGraphpics[graphics::TILE_MOUSE] = "./assets/tiles/red_slime.png";

  // Dynamic allocate text

  // Load texts
  _gameFont.loadFromFile("./assets/font/oldschooladventures.ttf");

  // Define drowned text
  _textDrowned.setFont(_gameFont);
  _textEscaped.setString("Drowned!");
  _textDrowned.setOutlineThickness(2.0f);
  _textDrowned.setOutlineColor(sf::Color::Black);
  _textStarved.setCharacterSize(36u);
  _textDrowned.setFillColor(sf::Color::White);
  _textDrowned.setPosition(64, 64);

  // Define escaped text
  _textEscaped.setFont(_gameFont);
  _textEscaped.setString("Esacped!"); 
  _textEscaped.setOutlineThickness(2.0f);
  _textDrowned.setOutlineColor(sf::Color::Black);
  _textStarved.setCharacterSize(36u);
  _textEscaped.setFillColor(sf::Color::White);
  _textEscaped.setPosition(64, 64);

  // Define starved text
  _textStarved.setFont(_gameFont);
  _textEscaped.setString("Starved!");
  _textStarved.setOutlineThickness(2.0f);
  _textDrowned.setOutlineColor(sf::Color::Black);
  _textStarved.setCharacterSize(36u);
  _textStarved.setFillColor(sf::Color::White);
  _textStarved.setPosition(64, 64);

  _assetTexts[mouseStatusEnum::DROWNED] = &_textDrowned;
  _assetTexts[mouseStatusEnum::ESCAPED] = &_textEscaped;
  _assetTexts[mouseStatusEnum::STARVED] = &_textStarved;

}

std::string& assets::getGraphicsName(const graphics& key) {
  return _assetGraphpics[key];
}

/* ----------------------------------------------------------------------------
 * Function:
 *   _getText(const mouseStatusEnum&)
 * Description:
 *   Gets the text depending on what enum value argument is.
 * --------------------------------------------------------------------------*/
sf::Text& assets::_getText(const mouseStatusEnum& key) {
  return *_assetTexts[key];
}

/* ----------------------------------------------------------------------------
 * Function:
 *   ~assets
 * Description:
 *   Deletes dynamically allocated things
 * --------------------------------------------------------------------------*/
assets::~assets() {
}
