#ifndef __ENEMY__
#define __ENEMY__

#include "ShooterObject.h"
#include "GameObjectFactory.h"
#include "Game.h"

class Enemy: public ShooterObject {
public:
    void draw() override;
    void update() override;
    void clean() override;
    void load(std::unique_ptr<LoaderParams>  const &pParams);
    virtual void collision() {};
    virtual std::string type() { return "Enemy"; }
protected:
    Enemy();
    int m_health;
    virtual ~Enemy() {}  // for polymorphism.
};

#endif /* defined(__ENEMY__) */