#include "asset.h"

/* ----------------------------------------------------------------------------
 * Static variables from assets class must be defined here
 * --------------------------------------------------------------------------*/
sf::Font assets::_gameFont;
std::map<mouseStatusEnum, sf::Text> assets::_assetTexts;
std::map<graphics, std::string> assets::_assetGraphpics;
sf::Text assets::_textDrowned;
sf::Text assets::_textEscaped;
sf::Text assets::_textStarved;
sf::Text assets::_textAlive;


/* ----------------------------------------------------------------------------
 * Define extern here
 * --------------------------------------------------------------------------*/
assets assetsObj;

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   assets()
 * DESCRIPTION:
 *   Default ctor of assets class. Loads SMFL assets and defines some other
 *   assets such as text, etc, etc.
 * --------------------------------------------------------------------------*/
assets::assets() {
  // Load graphics for tiles and characters.
  _assetGraphpics[graphics::TILE_BRIDGE] = "./assets/tiles/bridge.png";
  _assetGraphpics[graphics::TILE_WATER] = "./assets/tiles/water.png";
  _assetGraphpics[graphics::TILE_LAND] = "./assets/tiles/grass.png";
  _assetGraphpics[graphics::TILE_MOUSE] = "./assets/tiles/red_slime.png";

  // Load texts
  _gameFont.loadFromFile("./assets/font/oldschooladventures.ttf");

  // Define drowned text
  _textDrowned.setFont(_gameFont);
  _textDrowned.setString("Drowned!");
  _textDrowned.setOutlineThickness(5.0f);
  _textDrowned.setOutlineColor(sf::Color::Black);
  _textDrowned.setCharacterSize(48u);
  _textDrowned.setFillColor(sf::Color::White);

  // Define escaped text
  _textEscaped.setFont(_gameFont);
  _textEscaped.setString("Esacped!"); 
  _textEscaped.setOutlineThickness(5.0f);
  _textEscaped.setOutlineColor(sf::Color::Black);
  _textEscaped.setCharacterSize(48u);
  _textEscaped.setFillColor(sf::Color::White);

  // Define starved text
  _textStarved.setFont(_gameFont);
  _textStarved.setString("Starved!");
  _textStarved.setOutlineThickness(5.0f);
  _textStarved.setOutlineColor(sf::Color::Black);
  _textStarved.setCharacterSize(48u);
  _textStarved.setFillColor(sf::Color::White);

  // Define alive text
  _textAlive.setFont(_gameFont);
  _textAlive.setString("Alive");
  _textAlive.setOutlineThickness(5.0f);
  _textAlive.setOutlineColor(sf::Color::Black);
  _textAlive.setCharacterSize(48u);
  _textAlive.setFillColor(sf::Color::White);

  _assetTexts[mouseStatusEnum::DROWNED] = _textDrowned;
  _assetTexts[mouseStatusEnum::ESCAPED] = _textEscaped;
  _assetTexts[mouseStatusEnum::STARVED] = _textStarved;
  _assetTexts[mouseStatusEnum::ALIVE] = _textAlive;

}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   getGraphicsName(const graphics&)
 * DESCRIPTION:
 *   Gets the path of a texture based on the argument, which is an enum class.
 * --------------------------------------------------------------------------*/
std::string& assets::getGraphicsName(const graphics& key) {
  return _assetGraphpics[key];
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _getText(const mouseStatusEnum&)
 * DESCRIPTION:
 *   Gets the text depending on what enum value argument is.
 * --------------------------------------------------------------------------*/
sf::Text& assets::_getText(const mouseStatusEnum& key) {
  return _assetTexts[key];
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   ~assets
 * DESCRIPTION:
 *   Deletes dynamically allocated things
 * --------------------------------------------------------------------------*/
assets::~assets() {
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   getFont()
 * DESCRIPTION:
 *   Gets the game font.
 * --------------------------------------------------------------------------*/
sf::Font& assets::_getFont() const {
  return _gameFont;
}
