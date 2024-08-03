#ifndef __ENEMY__
#define __ENEMY__

#include "ShooterObject.h"
#include "GameObjectFactory.h"
#include "Game.h"

class Enemy: public ShooterObject {
public:
    Enemy(const LoaderParams* pParams, int numFrames=6);
    void draw() override;
    void update() override;
    void clean() override;
    void load(const LoaderParams *pParams) override;
    virtual std::string type() { return "Enemy"; }
protected:
    int m_health;
    Enemy();
    virtual ~Enemy() {}  // for polymorphism.
};

class EnemyCreator: public BaseCreator {
public:
    GameObject* createGameObject() const override;
};


#endif /* defined(__ENEMY__) */