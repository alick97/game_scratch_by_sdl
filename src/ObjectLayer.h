#ifndef __OBJECT_LAYER_H__
#define __OBJECT_LAYER_H__
#include "GameObject.h"
#include "Layer.h"
#include "CollisionManager.h"
#include <vector>

class ObjectLayer: public Layer {
    public:
        virtual ~ObjectLayer();
        void update(Level *pLevel) override;
        void render() override;
        
        std::vector<GameObject*>* getGameObjects() {
            return &m_gameObjects;
        };
        
    
    private:
        // check for collisions between game objects
        CollisionManager m_collisionManager;
        std::vector<GameObject*> m_gameObjects;
};
#endif
