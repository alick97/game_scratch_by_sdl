#ifndef __GAMEOVERSTATE_H__
#define __GAMEOVERSTATE_H__
#include <vector>
#include "GameState.h"
#include "GameObject.h"
#include "Game.h"
#include "AnimatedGraphic.h"
#include "StateParser.h"
#include "MenuState.h"


class GameOverState: public MenuState {
public:
    void update() override;
    void render() override;

    bool onEnter() override;
    bool onExit() override;

    std::string getStateID() const override;

private:
    void setCallbacks(const std::vector<Callback> &callbacks) override;
    static void s_gameOverToMain();
    static void s_restartPlay();

    static const std::string s_gameOverID;
    std::vector<GameObject*> m_gameObjects;
};

#endif