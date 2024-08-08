#ifndef __LEVEL_PARSER_H__
#define __LEVEL_PARSER_H__
#include <vector>
#include "tinyxml2.h"
#include "base64.h"
#include "zlib.h"
#include "TextureManager.h"
#include "Game.h"
#include "Level.h"
#include "TileLayer.h"

class LevelParser {
public:
    Level *parseLevel(const char *levelFile);
private:
    void parseTilesets(tinyxml2::XMLElement *pTilesetRoot,
        std::vector<Tileset> *pTilesets);
    
    void parseTileLayer(tinyxml2::XMLElement *pTileElement,
        std::vector<Layer*> *pLayers, const std::vector<Tileset> *pTilesets,
        std::vector<TileLayer*> *pCollisionLayers);
    
    void parseTextures(tinyxml2::XMLElement *pTextureRoot);
    void parseObjectLayer(tinyxml2::XMLElement *pObjectElement,
                          std::vector<Layer*> *pLayers, Level* pLevel);
    
    int m_tileSize;
    int m_width;
    int m_height;
};

#endif /* defined(__LEVEL_PARSER_H__) */
