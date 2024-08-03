#ifndef __PLAYER__
#define __PLAYER__

#include "ShooterObject.h"
#include "Game.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"

class Player : public ShooterObject {
public:
    Player();
    Player(const LoaderParams* pParams);
    virtual void load(const LoaderParams *pParams) override;
    virtual void draw();
    virtual void update();
    virtual void clean();
private:
    // bring the player back if there are lives left.
    void ressurect();
    
    // handle any input form the keyboard, mouse, or joystick.
    void handleInput();
    
    // handle any animation for the player.
    void handleAnimation();
    
    // player can be invulnerable for a time.
    int m_invulnerable;
    int m_invulnerableTime;
    int m_invulnerableCounter;
};


class PlayerCreator: public BaseCreator {
public:
    GameObject* createGameObject() const override;
};

#endif /* defined(__PLAYER__) */