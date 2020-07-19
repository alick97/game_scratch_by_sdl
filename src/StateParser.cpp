#include "StateParser.h"

bool StateParser:: parseState(const char *stateFile, std::string stateID, std::vector<GameObject*> *pObjects, std::vector<std::string> *pTextureIDs) {
    // Create the XML document.
    tinyxml2::XMLDocument xmlDoc;

    // Load the state file.
    if (tinyxml2::XMLError::XML_SUCCESS != xmlDoc.LoadFile(stateFile)) {
        std::cerr << "xml load file error: " << xmlDoc.ErrorStr() << std::endl;
        return false;
    }

    // Get the root element.
    tinyxml2::XMLElement *pRoot = xmlDoc.RootElement();

    // Pre declare the states root node.
    tinyxml2::XMLElement *pStateRoot = nullptr;
    // Get this states root node and assign it to pStateRoot.
    for (tinyxml2::XMLElement *e = pRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        if (e->Value() == stateID) {
            pStateRoot = e;
            break;
        }
    }

    // Pre declare the texture root.
    tinyxml2::XMLElement *pTextureRoot = nullptr;
    for (tinyxml2::XMLElement *e = pStateRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        if (e->Value() == std::string("TEXTURES")) {
            pTextureRoot = e;
            break;
        }
    }

    // Now parse the textures.
    parseTextures(pTextureRoot, pTextureIDs);

    // Pre declare the object root node.
    tinyxml2::XMLElement *pObjectRoot = nullptr;

    // Get root node and assign it to pObjectRoot.
    for (tinyxml2::XMLElement *e = pStateRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        if (e->Value() == std::string("OBJECTS")) {
            pObjectRoot = e;
            break;
        }
    }

    // Now parse the objects;
    parseObjects(pObjectRoot, pObjects);

    return true;
}

void StateParser::parseObjects(tinyxml2::XMLElement *pStateRoot, std::vector<GameObject*> *pObjects) {
    for(tinyxml2::XMLElement *e = pStateRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        int x, y, width, height, numFrames, callbackID, animSpeed;
        std::string textureID;
        e->QueryAttribute("x", &x);
        e->QueryAttribute("y", &y);
        e->QueryAttribute("width",&width);
        e->QueryAttribute("height", &height);
        e->QueryAttribute("numFrames", &numFrames);
        e->QueryAttribute("callbackID", &callbackID);
        e->QueryAttribute("animSpeed", &animSpeed);
        textureID = e->Attribute("textureID");
        GameObject* pGameObject = TheGameObjectFactory::Instance()->create(e->Attribute("type"));
        pGameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, callbackID, animSpeed));
        pObjects->push_back(pGameObject);
    }

}

void StateParser::parseTextures(tinyxml2::XMLElement *pStateRoot, std::vector<std::string> *pTextureIDs) {
    for (tinyxml2::XMLElement *e = pStateRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
        std::string filenameAttribute = e->Attribute("filename");
        std::string idAttribute = e->Attribute("ID");
        pTextureIDs->push_back(idAttribute);

        TheTextureManager::Instance()->load(filenameAttribute, idAttribute, TheGame::Instance()->getRender());
    }
}

