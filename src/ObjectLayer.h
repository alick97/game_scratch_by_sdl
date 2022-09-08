#ifndef __OBJECT_LAYER_H__
#define __OBJECT_LAYER_H__
#include "GameObject.h"
#include "Layer.h"
#include <vector>

class ObjectLayer: public Layer {
    public:
        void update() override;
        void render() override;
        
        std::vector<GameObject*>* getGameObjects() {
            return &m_gameObjects;
        };
        
    
    private:
        std::vector<GameObject*> m_gameObjects;
};
#endif
