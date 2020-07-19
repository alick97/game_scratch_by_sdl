#ifndef __PAUSESTATE_H__
#define __PAUSESTATE_H__
#include <vector>
#include "MainMenuState.h"


class PauseState: public MenuState {
public:
    void update() override;
    void render() override;

    bool onEnter() override;
    bool onExit() override;

    std::string getStateID() const override;
private:
    void setCallbacks(const std::vector<Callback> &callbacks) override;
    static void s_pauseToMain();
    static void s_resumePlay();

    static const std::string s_pauseID;

    std::vector<GameObject*> m_gameObjects;
};

// #include "Game.h"
#endif