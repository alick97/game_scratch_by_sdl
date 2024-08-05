#ifndef __ANIMATEDGRAPHIC_H__
#define __ANIMATEDGRAPHIC_H__
#include "ShooterObject.h"
#include "GameObjectFactory.h"
#include "Game.h"

class AnimateGraphic: public ShooterObject {
public:
    AnimateGraphic();
    void draw() override;
    void update() override;
    void clean() override;
    void load(std::unique_ptr<LoaderParams> const &pParams);
private:
    int m_animSpeed;
};

class AnimateGraphicCreator: public BaseCreator {
public:
    GameObject* createGameObject() const override;
};

#endif