#ifndef __PLAYSTATE__
#define __PLAYSTATE__
#include <iostream>
#include <vector>
#include "Game.h"
#include "GameState.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "LevelParser.h"
#include "Level.h"
#include "CollisionManager.h"

class PlayState: public GameState {
public:
    virtual ~PlayState() { delete pLevel; }
    void update() override;
    void render() override;

    bool onEnter() override;
    bool onExit() override;

    std::string getStateID() const override;
private:
    static const std::string s_playID;
    std::vector<GameObject*> m_gameObjects;
    Level *pLevel;
    CollisionManager m_collisionManager; 
};
// #include "Game.h"
#endif