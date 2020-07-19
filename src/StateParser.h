#ifndef __STATEPARSER__
#define __STATEPARSER__

#include <iostream>
#include <vector>
#include "tinyxml2.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameObjectFactory.h"

class StateParser {
public:
    bool parseState(const char *stateFile, std::string stateID, std::vector<GameObject*> *pObjects, std::vector<std::string> *pTextureIDs);
private:
    void parseObjects(tinyxml2::XMLElement *pStateRoot, std::vector<GameObject*> *pObjects);
    void parseTextures(tinyxml2::XMLElement *pStateRoot, std::vector<std::string> *pTextureIDs);
};


#endif /** defined(__STATEPARSER__) */
