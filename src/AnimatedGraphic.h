#ifndef __ANIMATEDGRAPHIC_H__
#define __ANIMATEDGRAPHIC_H__
#include "GameObject.h"
#include "GameObjectFactory.h"
#include "Game.h"

class AnimateGraphic: public GameObject {
public:
    AnimateGraphic();
    AnimateGraphic(const LoaderParams* pParams, int animSpeed, int numFrames=1);
    void draw() override;
    void update() override;
    void clean() override;
    void load(std::unique_ptr<LoaderParams> const &pParams);
    void collision() {};
    std::string type() { return "GameObject"; };
private:
    int m_animSpeed;
};

class AnimateGraphicCreator: public BaseCreator {
public:
    GameObject* createGameObject() const override;
};

#endif