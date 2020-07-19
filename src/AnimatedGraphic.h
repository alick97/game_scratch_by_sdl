#ifndef __ANIMATEDGRAPHIC_H__
#define __ANIMATEDGRAPHIC_H__
#include "SDLGameObject.h"
#include "GameObjectFactory.h"
#include "Game.h"

class AnimateGraphic: public SDLGameObject {
public:
    AnimateGraphic();
    AnimateGraphic(const LoaderParams* pParams, int animSpeed, int numFrames=1);
    void draw() override;
    void update() override;
    void clean() override;
    void load(const LoaderParams *pParams) override;
private:
    int m_animSpeed;
};

class AnimateGraphicCreator: public BaseCreator {
public:
    GameObject* createGameObject() const override;
};

#endif