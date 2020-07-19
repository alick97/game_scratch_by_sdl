#ifndef __GAMEOBJECTFACTORY__
#define __GAMEOBJECTFACTORY__
#include <string>
#include <map>
#include "GameObject.h"

class BaseCreator {
public:
    virtual GameObject* createGameObject() const = 0;
    virtual ~BaseCreator() {}
};


class GameObjectFactory {
public:
    static GameObjectFactory *Instance();
    bool registerType(std::string typeID, BaseCreator* pCreator);
    GameObject* create(std::string typeID);
private:
    GameObjectFactory() {};
    std::map<std::string, BaseCreator*> m_creators;
    static GameObjectFactory *s_pInstance;
};

typedef GameObjectFactory TheGameObjectFactory;

#endif /* defined(__GAMEOBJECTFACTORY__) */
