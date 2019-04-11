#ifndef __ANIMATEDGRAPHIC_H__
#define __ANIMATEDGRAPHIC_H__
#include "SDLGameObject.h"
#include "Game.h"

class AnimateGraphic: public SDLGameObject {
public:
    AnimateGraphic(const LoaderParams* pParams, int animSpeed, int numFrames=1);
    virtual void draw();
    virtual void update();
    virtual void clean();
private:
    const int m_numFrames;
    int m_animSpeed;
};

#endif