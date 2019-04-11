#ifndef __PLAYSTATE__
#define __PLAYSTATE__
#include "GameState.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "PauseState.h"
#include "GameOverState.h"
#include <iostream>
#include <vector>

class PlayState: public GameState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const;
private:
    static const std::string s_playID;
    std::vector<GameObject*> m_gameObjects;
    bool checkCollision(SDLGameObject *p1, SDLGameObject *p2);
};
#include "Game.h"
#endif