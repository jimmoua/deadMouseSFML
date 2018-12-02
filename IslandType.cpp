#include "IslandType.h"
#include "asset.h"
#include "Window.h"

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   islandType()
 * DESCRIPTION:
 *   Default ctor. Doesn't do anything. Refer to init fn instead.
 * --------------------------------------------------------------------------*/
islandType::islandType() {
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   getGrid()
 *
 * DESCRIPTION:
 *   Gets information from a map/grid file.
 * --------------------------------------------------------------------------*/
bool islandType::getGrid(const std::string& fileName) {
  // Used to count total area and mouse. Will be used for err checking.
  int l_totalGridArea = 0;
  int l_mouseCounter = 0;
  int numBridges = 0;
  gridSize = 0;

  // Create ifstream obj to read from file
  std::ifstream infile;
  infile.open(fileName.c_str());
  if(!infile) {
    logger.err("Unable to open file: " + fileName + " was not found.");
    return false;
  }
  else {
    // Read first line, which is gridSize. The map is a square.
    infile >> gridSize;
    if(!infile) {
      if(infile.eof()) {
        logger.err("File is empty.");
        return false;
      }
      else {
        logger.err("Missing or incorrent grid size.");
        return false;
      }
    }
    else
        infile.ignore();

    // If bad read bit or Size is too large/small...
    if(!infile or gridSize > MAX_SIZE or gridSize < MIN_SIZE) {
      logger.err("Missing or incorrent grid size.");
      return false;
    }

    /* The following declares and initializes two identifiers of type size_t.
     * They both keep track of indexes of the Island array.  Inside the while
     * loop, we are continuously reading the from the file into the array. */
    size_t i = 0; // Index of rows
    size_t k = 0; // Index of col
    while(infile.peek() != '\0' and !infile.eof())
    {
      infile >> islandMap[i][k];
      if(!infile) {
        logger.err("Missing or incorrect grid size.");
        return false;
      }
      else {
        infile.ignore();
      }

      l_totalGridArea++; // Everytime it reads, increase the area by 1 unit.

      /* The following switch is for checking the type of type. We only care
       * about whether it is a bridge or if it is a mouse because we will be
       * making ordered pairs out of them. */
      switch(islandMap[i][k]) {
        case -2:
          /* Adding this if statement to check and see if the max number
           * of bridge is created because lovely stack smashing is
           * detected */
          if(numBridges == MAX_BRIDGES) {
            infile.close();
            logger.err("Too many bridges.");
          }
          numBridges++;
          break;
        case -1:
        case  0:
          break;
        case  1:
          // If mouse
          if(l_mouseCounter == 0) {
            mouseStartLoc.first = i;
            mouseStartLoc.second = k;
          }
          l_mouseCounter++;
          break;
        default:
          // The switch defaults if it read in something that isn't
          // recognizable. This means that it read in a value that doesn't
          // represent a bridge, water, land, or mouse
          logger.err("Missing or incorrect grid size");
          return false;
      }
      // k++ allows the next slot of the array to be pulled up since for loops
      // aren't being used. Inside the if statement, we are saying everytime k
      // is equal to the total max that we are allowed to read in for 1 row,
      // which is the same value as Size, we will go to the next row and also
      // reset the value of k back to 0 so we can go index the array correctly.
      k++;
      if(k == gridSize) {
        i++;
        k = 0;
      }
    }

    // Do some error checking below, as mentioned above.

    // Check to see if there was a mouse defined.
    // We don't care to check if there are too many
    // mice down here (after the loop), since we are
    // already checking to see if there are already
    // too many mice defined inside the loop. */
    if(l_mouseCounter == 0) {
      infile.close();
      logger.err("Missing mouse location");
      return false;
    }
    else if(l_mouseCounter > 1) {
      infile.close();
      logger.err("Too many mice.");
      return false;
    }
    
    // Does the map meet the satisfied number of bridges?
    if(numBridges < MIN_BRIDGES) {
      infile.close();
      logger.err("Missing bridges.");
      return false;
    }
    else if(numBridges > MAX_BRIDGES) {
      infile.close();
      logger.err("Too many bridges.");
      return false;
    }

    // Is there enough grid information?
    if(l_totalGridArea < gridSize*gridSize) {
      infile.close();
      logger.err("Not enough grid information");
      return false;
    }
    else if(l_totalGridArea > gridSize*gridSize) {
      infile.close();
      logger.err("Too much grid information.");
      return false;
    }
    infile.close();
  }
  return true;
}

/* ----------------------------------------------------------------------------
 * Function:
 *   DrawMap()
 *
 * Description:
 *   Draws the grid on the SFML window.
 * --------------------------------------------------------------------------*/
void islandType::drawMap() {
  // Each sprite is a 64x64 because that's how the png were made.
  // Draw rows
  for(unsigned short int x = 0; x != gridSize+1; x++) {
    // Draw cols
    for(unsigned short int y = 0; y != gridSize+1; y++) {
      /* For setPosition, set the y as first parameter because setPosition is
       * dealing with the x parameter first. Because of this, we need to pass
       * the y in because we are drawing y-cols first. */
      switch(islandMap[y][x]) {
        case -2:
          winObj._getRefSFMLWindow()->draw(_sBridge);
          _sBridge.setPosition(x*__SCALE__, y*__SCALE__);
          break;
        case -1:
          winObj._getRefSFMLWindow()->draw(_sWater);
          _sWater.setPosition(x*__SCALE__, y*__SCALE__);
          break;
        case 0:
        case 1:
          winObj._getRefSFMLWindow()->draw(_sGround);
          _sGround.setPosition(x*__SCALE__, y*__SCALE__);
          break;
        default: break;
      }
    }
  }
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   getGridSize()
 * DESCRIPTION:
 *   Returns the grid size.
 * --------------------------------------------------------------------------*/
unsigned short int islandType::getGridSize() const {
  return gridSize;
}

/* ----------------------------------------------------------------------------
 * FUNCTION:
 *   init()
 * DESCRIPTION:
 *   The init function. Loads in all the textures of the island type. Use an
 *   init function because we do not use extern for obj.
 * --------------------------------------------------------------------------*/
bool islandType::init(const std::string &fileName) {
  // Load the textures in and set sprites if successful
  if(!_tGround.loadFromFile(assetsObj.getGraphicsName(graphics::TILE_LAND)))
    logger.err("Unable to load land tile.");
  else {
    _sGround.setTexture(_tGround);
    _sGround.setScale(0.5f, 0.5f);
  }

  if(!_tWater.loadFromFile(assetsObj.getGraphicsName(graphics::TILE_WATER)))
    logger.err("Unable to load water tile.");
  else {
    _sWater.setTexture(_tWater);
    _sWater.setScale(0.5f, 0.5f);
  }

  if(!_tBridge.loadFromFile(assetsObj.getGraphicsName(graphics::TILE_BRIDGE)))
    logger.err("Unable to load bridge tile.");
  else {
    _sBridge.setTexture(_tBridge);
    _sBridge.setScale(0.5f, 0.5f);
  }

  // Begin loading map
  return getGrid(fileName);
}

/* ----------------------------------------------------------------------------
 * Function:
 *   getMouseStartingLoc()
 *
 * Description:
 *   Returns the std::pair for mouse location.
 * --------------------------------------------------------------------------*/
std::pair<int, int> islandType::getMouseStartingLoc() {
  return mouseStartLoc;
}

/* ----------------------------------------------------------------------------
 * Function:
 *   _checkCollisions(std::pair<int, int>)
 * Description:
 *   Checks to see where the mouse is.
 * --------------------------------------------------------------------------*/
mouseStatusEnum islandType::_checkCollisions(std::pair<int, int> mouseLoc) {
  mouseStatusEnum newMouseState;
  switch(islandMap[mouseLoc.first][mouseLoc.second]) {
    case -2:
      newMouseState = mouseStatusEnum::ESCAPED;
      std::cout << "The mouse escaped: " << mouseLoc.first << " " <<
        mouseLoc.second << std::endl;
      break;
    case -1:
      newMouseState = mouseStatusEnum::DROWNED;
      std::cout << "The mouse drowned: " << mouseLoc.first << " " <<
        mouseLoc.second << std::endl;
      break;
    default:
      newMouseState = mouseStatusEnum::ALIVE;
      break;
  }
  return newMouseState;
}
