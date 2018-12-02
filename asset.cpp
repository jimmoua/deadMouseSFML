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
sf::Clock assets::_timerReset;
sf::Text assets::_timerTxt;
short int assets::_timer = 3;


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
  _textDrowned.setPosition(16, 16);

  // Define escaped text
  _textEscaped.setFont(_gameFont);
  _textEscaped.setString("Esacped!"); 
  _textEscaped.setOutlineThickness(5.0f);
  _textEscaped.setOutlineColor(sf::Color::Black);
  _textEscaped.setCharacterSize(48u);
  _textEscaped.setFillColor(sf::Color::White);
  _textEscaped.setPosition(16, 16);

  // Define starved text
  _textStarved.setFont(_gameFont);
  _textStarved.setString("Starved!");
  _textStarved.setOutlineThickness(5.0f);
  _textStarved.setOutlineColor(sf::Color::Black);
  _textStarved.setCharacterSize(48u);
  _textStarved.setFillColor(sf::Color::White);
  _textStarved.setPosition(16, 16);


  // Define alive text
  _textAlive.setFont(_gameFont);
  _textAlive.setString("Alive");
  _textAlive.setOutlineThickness(5.0f);
  _textAlive.setOutlineColor(sf::Color::Black);
  _textAlive.setCharacterSize(48u);
  _textAlive.setFillColor(sf::Color::White);
  _textAlive.setPosition(16, 16);

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

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _showMsgReset()
 * DESCRIPTION:
 *   Shows a countdown message until the simulation is reset.
 * --------------------------------------------------------------------------*/
void assets::_showMsgReset() {
  if(_timerReset.getElapsedTime().asSeconds() > sf::seconds(.2).asSeconds()) {
    // For every second that goes by, reset it and increment the timer and
    // change the string/text.
    _timer--;
    _timerReset.restart();
  }
  _timerTxt.setString(std::to_string(_timer));
  winObj._getRefSFMLWindow()->draw(_timerTxt);
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _init();
 * DESCRIPTION:
 *   Need this init because issues with externs. Call this after the init of
 *   Window has been called.
 * --------------------------------------------------------------------------*/
void assets::_init() {
  // Define timer text
  _timerTxt.setFont(_gameFont);
  _timerTxt.setOutlineThickness(3.0f);
  _timerTxt.setOutlineColor(sf::Color::Black);
  _timerTxt.setCharacterSize(32u);
  _timerTxt.setFillColor(sf::Color::White);
  _timerTxt.setString(std::to_string(_timer));
  // Create some temps to get timer to center of screen
  sf::FloatRect tr = _timerTxt.getLocalBounds();
  sf::Vector2u sr = winObj._getWindowResoSize();
  std::cout << sr.x << " " << sr.y << std::endl;
  _timerTxt.setOrigin(tr.left+tr.width/2.0f, tr.top+tr.height/2.0f);
  _timerTxt.setPosition(sf::Vector2f(sr.x/2, sr.y/2));
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _getTimer() const
 * DESCRIPTION:
 *   Gets timer count
 * --------------------------------------------------------------------------*/
short int assets::_getTimer() const {
  return _timer;
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   _restartClockTimer()
 * DESCRIPTION:
 *   Restarts clock and timer counter.
 * --------------------------------------------------------------------------*/
void assets::_restartClockTimer() {
  _timerReset.restart();
  _timer = 3;
}
