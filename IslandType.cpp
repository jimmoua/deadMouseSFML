#include "IslandType.h"
#include "asset.h"
#include "Window.h"

// Statics
std::string islandType::mapName = "./assets/maps/";

islandType::islandType() {
}

// Function for getting grid information
bool islandType::getGrid() {
  // Used to count total area and mouse
  int l_totalGridArea = 0;
  int l_mouseCounter = 0;

  std::ifstream infile;   // Create the read from map...
  infile.open(mapName.c_str());
  if(!infile) {
    logger.err("Unable to open file");
    return false;   // Return code 1 = can't open file.
  }
  else {
    // First, check if the file is empty. If it is, the function returns 9
    // which indicates empty file.
    
    infile >> gridSize;// This line reads in the specified size of the grid
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
          bridgeLoc[numBridges].first = i;
          bridgeLoc[numBridges].second = k;
          numBridges++;
          break;
        case -1:
          break;
        case 1: // If mouse
          if(l_mouseCounter == 0) {
            mouseStartLoc.first = i;
            mouseStartLoc.second = k;
          }
          l_mouseCounter++;
          break;
        case 0: {
          /* We read in a tile, so do nothing */
          break;
        }
        default:
          /* The switch defaults if it read in something that isn't
           * recognizable. This means that it read in a value that doesn't
           * represent a bridge, water, land, or mouse */
          logger.err("Missing or incorrect grid size");
          return false;
      }
      /* k++ allows the next slot of the array to be pulled up since for loops
       * aren't being used. Inside the if statement, we are saying everytime k
       * is equal to the total max that we are allowed to read in for 1 row,
       * which is the same value as Size, we will go to the next row and also
       * reset the value of k back to 0 so we can go index the array correctly.
       * */
      k++;
      if(k == gridSize) {
        i++;
        k = 0;
      }
    }

    /* Do some error checking below, as mentioned above */

    /* Check to see if there was a mouse defined.
     *   We don't care to check if there are too many
     *   mice down here (after the loop), since we are
     *   already checking to see if there are already
     *   too many mice defined inside the loop. */
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
    
    /* Does the map meet the satisfied number of bridges? */
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

void islandType::drawMap() {
  const sf::Vector2u reso = winObj._getWindowResoSize();

  // Draw rows
  for(unsigned short int x = 0; x != reso.x; x++) {

    // Draw cols
    for(unsigned short int y = 0; y != reso.y; y++) {

    }
  }
}

// Gets grid size. Needed for window initialization
unsigned short int islandType::getGridSize() {
  return gridSize;
}

bool islandType::init() {
  // Load the textures in
  _tGround.loadFromFile(assetsObj.getGraphicsName(graphics::TILE_LAND));
  _tWater.loadFromFile(assetsObj.getGraphicsName(graphics::TILE_WATER));
  _tBridge.loadFromFile(assetsObj.getGraphicsName(graphics::TILE_BRIDGE));

  // Set Sprites
  _sGround.setTexture(_tGround);
  _sWater.setTexture(_tWater);
  _sBridge.setTexture(_tBridge);

  // Set to 0 so increment without overflow
  gridSize = 0;
  numBridges = 0;

  std::cout << "Enter in a map name: ";
  std::string mapAppend;
  std::getline(std::cin, mapAppend);
  mapName.append(mapAppend);
  return getGrid();
}

void debug(islandType& obj) {
  std::cout << "Grid size:   " << obj.gridSize << std::endl;
  std::cout << "Name of map: " << obj.mapName << std::endl;
}
