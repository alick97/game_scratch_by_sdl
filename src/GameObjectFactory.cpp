#include "GameObjectFactory.h"


bool GameObjectFactory::registerType(std::string typeID, BaseCreator* pCreator) {
    auto it = m_creators.find(typeID);

    // If the type is already registered, do nothing.
    if (it != m_creators.end()) {
        delete pCreator;
        return false;
    }

    m_creators[typeID] = pCreator;
    return true;
}

GameObject *GameObjectFactory::create(std::string typeID) {
    auto it = m_creators.find(typeID);

    if (it == m_creators.end()) {
        std::cout << "GameObjectFactory: could not find type: " << typeID << std::endl;
        return nullptr;
    }

    BaseCreator* pCreator = (*it).second;
    return pCreator->createGameObject();
}

GameObjectFactory *GameObjectFactory::Instance() {
    if (s_pInstance == NULL) {
        s_pInstance = new GameObjectFactory();
        return s_pInstance;
    }

    return s_pInstance;
}

GameObjectFactory *GameObjectFactory::s_pInstance = nullptr;
