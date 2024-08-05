#include "LevelParser.h"
#include "ObjectLayer.h"
#include "GameObjectFactory.h"

Level *LevelParser::parseLevel(const char *levelFile)
{
    // Create a TinyXML document and load the map XML.
    tinyxml2::XMLDocument levelDocument(true, tinyxml2::COLLAPSE_WHITESPACE);
    levelDocument.LoadFile(levelFile);

    // Create the level object.
    Level *pLevel = new Level();

    // Get the root node.
    tinyxml2::XMLElement *pRoot = levelDocument.RootElement();

    m_tileSize = pRoot->IntAttribute("tilewidth");
    m_width = pRoot->IntAttribute("width");
    m_height = pRoot->IntAttribute("height");

    // Parse the tilesets.
    for (tinyxml2::XMLElement *e = pRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("tileset"))
        {
            parseTilesets(e, pLevel->getTitlesets());
        }
    }

    // Parse any object layers.
    for (tinyxml2::XMLElement *e = pRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("objectgroup") || e->Value() == std::string("layer"))
        {
            if (e->FirstChildElement()->Value() == std::string("object"))
            {
                parseObjectLayer(e, pLevel->getLayers());
            }
            else if (e->FirstChildElement()->Value() == std::string("data"))
            {
                parseTileLayer(e, pLevel->getLayers(), pLevel->getTitlesets());
            }
        }
    }

    // Parse Textures.
    for (tinyxml2::XMLElement *e = pRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("properties"))
        {
            for (tinyxml2::XMLElement *pProperty = e->FirstChildElement(); pProperty != nullptr; pProperty = pProperty->NextSiblingElement()) {
                parseTextures(pProperty);
            }
        }
    }

    return pLevel;
}

void LevelParser::parseTilesets(tinyxml2::XMLElement *pTilesetRoot,
                                std::vector<Tileset> *pTilesets)
{
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
                                 std::vector<Layer *> *pLayers, const std::vector<Tileset> *pTilesets)
{
    TileLayer *pTileLayer = new TileLayer(m_tileSize, *pTilesets);
    // Tile data.
    std::vector<std::vector<int>> data;

    std::string decodedIDs;
    tinyxml2::XMLElement *pDataNode;

    for (tinyxml2::XMLElement *e = pTileElement->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("data"))
        {
            pDataNode = e;
        }
    }

    for (tinyxml2::XMLNode *e = pDataNode->FirstChild(); e != nullptr; e = e->NextSiblingElement())
    {
        tinyxml2::XMLText *text = e->ToText();
        std::string t = text->Value();
        decodedIDs = base64_decode(t);
    }

    // Uncompress zlib compression.
    uLongf numGids = m_width * m_height * sizeof(int);
    std::vector<unsigned> gids(numGids);
    uncompress((Bytef *)&gids[0], &numGids, reinterpret_cast<const Bytef *>(decodedIDs.c_str()), decodedIDs.size());

    std::vector<int> layerRow(m_width);
    for (int j = 0; j < m_height; j++)
    {
        data.push_back(layerRow);
    }

    for (int rows = 0; rows < m_height; rows++)
    {
        for (int cols = 0; cols < m_width; cols++)
        {
            data[rows][cols] = gids[rows * m_width + cols];
        }
    }

    pTileLayer->setTileIDs(data);

    pLayers->push_back(pTileLayer);
}

void LevelParser::parseTextures(tinyxml2::XMLElement *pTextureRoot)
{
    TheTextureManager::Instance()->load(pTextureRoot->Attribute("value"), pTextureRoot->Attribute("name"), TheGame::Instance()->getRender());
}

void LevelParser::parseObjectLayer(tinyxml2::XMLElement *pObjectElement, std::vector<Layer *> *pLayers)
{
    // create an object layer
    ObjectLayer *pObjectLayer = new ObjectLayer();

    std::cout << pObjectElement->FirstChildElement()->Value();

    for (tinyxml2::XMLElement *e = pObjectElement->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        std::cout << e->Value();
        if (e->Value() == std::string("object"))
        {
            int x, y, width, height, numFrames, callbackID, animSpeed;
            std::string textureID;
            // get the initial node values type, x and y
            x = e->IntAttribute("x");
            y = e->IntAttribute("y");
            std::string type;
            type = e->Attribute("type");
            GameObject *pGameObject = TheGameObjectFactory::Instance()->create(type);
            // get the property values
            for (tinyxml2::XMLElement *properties = e->FirstChildElement();
                 properties != NULL; properties = properties -> NextSiblingElement())
            {
                if (properties->Value() == std::string("properties"))
                {
                    for (tinyxml2::XMLElement *property = properties -> FirstChildElement();
                         property != NULL; property = property -> NextSiblingElement())
                    {
                        if (property->Value() == std::string("property"))
                        {
                            if (property->Attribute("name") ==
                                std::string("numFrames"))
                            {
                                numFrames = property->IntAttribute("value");
                            }
                            else if (property->Attribute("name") ==
                                     std::string("textureHeight"))
                            {
                                height = property->IntAttribute("value");
                            }
                            else if (property->Attribute("name") ==
                                     std::string("textureID"))
                            {
                                textureID = property->Attribute("value");
                            }
                            else if (property->Attribute("name") ==
                                     std::string("textureWidth"))
                            {
                                width = property->IntAttribute("value");
                            }
                            else if (property->Attribute("name") ==
                                     std::string("callbackID"))
                            {
                               callbackID = property->IntAttribute("value");
                            }
                            else if (e->Attribute("name") ==
                                     std::string("animSpeed"))
                            {
                                animSpeed = property->IntAttribute("value");
                            }
                        }
                    }
                }
            }
            pGameObject->load(std::make_unique<LoaderParams>(x, y, width, height, textureID,
                                               numFrames, callbackID, animSpeed));
            pObjectLayer->getGameObjects()->push_back(pGameObject);
        }
    }
    pLayers->push_back(pObjectLayer);
}