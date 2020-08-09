#include "LevelParser.h"


Level *LevelParser::parseLevel(const char *levelFile) {
    // Create a TinyXML document and load the map XML.
    tinyxml2::XMLDocument levelDocument;
    levelDocument.LoadFile(levelFile);

    // Create the level object.
    Level *pLevel = new Level();

    // Get the root node.
    tinyxml2::XMLElement *pRoot = levelDocument.RootElement();

    m_tileSize = pRoot->IntAttribute("tilewidth");
    m_width = pRoot->IntAttribute("width");
    m_height = pRoot->IntAttribute("height");

    // Parse the tilesets.
    for(tinyxml2::XMLElement *e=pRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        if(e->Value() == std::string("tileset")) {
            parseTilesets(e, pLevel->getTitlesets());
        }
    }

    // Parse any object layers.
    for(tinyxml2::XMLElement *e = pRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        if (e->Value() == std::string("layer")) {
            parseTileLayer(e, pLevel->getLayers(), pLevel->getTitlesets());
        }
    }

    return pLevel;
}

void LevelParser::parseTilesets(tinyxml2::XMLElement *pTilesetRoot,
        std::vector<Tileset> *pTilesets) {
    // First add the tileset to texture manager.
    TheTextureManager::Instance()->load(pTilesetRoot->FirstChildElement()->Attribute("source"),
        pTilesetRoot->Attribute("name"), TheGame::Instance()->getRender());

    // Create a tileset object.
    Tileset tileset;
    tileset.width = pTilesetRoot->FirstChildElement()->IntAttribute("width");
    tileset.height = pTilesetRoot->FirstChildElement()->IntAttribute("height");
    tileset.firstGridID = pTilesetRoot->IntAttribute("firstgid");
    tileset.titleWidth = pTilesetRoot->IntAttribute("tilewidth");
    tileset.tileHeight = pTilesetRoot->IntAttribute("tileheight");
    tileset.spacing = pTilesetRoot->IntAttribute("spacing");
    tileset.margin = pTilesetRoot->IntAttribute("margin");
    tileset.numColumns = pTilesetRoot->IntAttribute("columns");
    tileset.name = pTilesetRoot->Attribute("name");

    pTilesets->push_back(tileset);
}
    
void LevelParser::parseTileLayer(tinyxml2::XMLElement *pTileElement,
        std::vector<Layer*> *pLayers, const std::vector<Tileset> *pTilesets) {
    TileLayer *pTileLayer = new TileLayer(m_tileSize, *pTilesets);
    // Tile data.
    std::vector<std::vector<int>> data;

    std::string decodedIDs;
    tinyxml2::XMLElement *pDataNode;

    for(tinyxml2::XMLElement *e = pTileElement->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        if (e->Value() == std::string("data")) {
            pDataNode = e;
        }
    }

    for(tinyxml2::XMLNode *e = pDataNode->FirstChild(); e != nullptr; e = e->NextSiblingElement()) {
        tinyxml2::XMLText *text = e->ToText();
        std::string t = text->Value();
        decodedIDs = base64_decode(t);
    }

    // Uncompress zlib compression.
    uLongf numGids = m_width * m_height * sizeof(int);
    std::vector<unsigned> gids(numGids);
    uncompress((Bytef*)&gids[0], &numGids, reinterpret_cast<const Bytef*>(decodedIDs.c_str()), decodedIDs.size());

    std::vector<int> layerRow(m_width);
    for (int j = 0; j < m_height; j++) {
        data.push_back(layerRow);
    }

    for (int rows = 0; rows < m_height; rows++) {
        for (int cols = 0; cols < m_width; cols++) {
            data[rows][cols] = gids[rows * m_width + cols];
        }
    }

    pTileLayer->setTileIDs(data);

    pLayers->push_back(pTileLayer);
}
