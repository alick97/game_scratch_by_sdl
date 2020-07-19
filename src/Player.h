#ifndef __PLAYER__
#define __PLAYER__

#include "SDLGameObject.h"
#include "Game.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"

class Player : public SDLGameObject {
public:
    Player();
    Player(const LoaderParams* pParams);
    virtual void load(const LoaderParams *pParams) override;
    virtual void draw();
    virtual void update();
    virtual void clean();
private:
    void handleInput();
};


class PlayerCreator: public BaseCreator {
public:
    GameObject* createGameObject() const override;
};

#endif /* defined(__PLAYER__) */