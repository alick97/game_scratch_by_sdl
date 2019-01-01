#ifndef __ENEMY__
#define __ENEMY__

#include "SDLGameObject.h"
#include "Game.h"

class Enemy: public SDLGameObject {
public:
    Enemy(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif /* defined(__ENEMY__) */