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

class PlayState: public GameState {
public:
    void update() override;
    void render() override;

    bool onEnter() override;
    bool onExit() override;

    std::string getStateID() const override;
private:
    static const std::string s_playID;
    std::vector<GameObject*> m_gameObjects;
    Level *pLevel;
    
    bool checkCollision(SDLGameObject *p1, SDLGameObject *p2);
};
// #include "Game.h"
#endif