#ifndef __ENEMY__
#define __ENEMY__

#include "SDLGameObject.h"
#include "Game.h"

class Enemy: public SDLGameObject {
public:
    Enemy(const LoaderParams* pParams, int numFrames=6);
    virtual void draw();
    virtual void update();
    virtual void clean();
private:
    int m_numFrames;
};

#endif /* defined(__ENEMY__) */