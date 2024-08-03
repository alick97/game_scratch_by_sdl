#ifndef __SHOOTEROBJECT__
#define __SHOTTEROBJECT__

#include "GameObject.h"
#include "Vector2D.h"

class ShooterObject : public GameObject {
public:
    virtual ~ShooterObject() {} // for polymorophism
    ShooterObject();
    ShooterObject(const LoaderParams* pParams);
    virtual void draw() override;
    virtual void update() override;
    virtual void clean() override;
    virtual void load(std::unique_ptr<LoaderParams>  const &pParams) override;
protected:
    // we won't directly create ShooterObject's ShotterObject();
    // draw the animation for the obejct being destroyed.
    void doDyingAnimation();
    // how fast will this obejct fire bullets? with a counter.
    int m_bulletFiringSpeed;
    int m_bulletCounter;

    // how fast with this obejct move?
    int m_moveSpeed;
    // how long will the death animation takes? with a counter.
    int m_dyingTime;
    int m_dyingCounter;
    
    // has the explosion sound played?
    bool m_bPlayedDeathSound;
};

#endif /* defined(__SHOOTEROBJECT__) */
