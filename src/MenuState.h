#ifndef __MENUSTATE_H__
#define __MENUSTATE_H__

#include "GameState.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include <vector>
#include <iostream>

class MenuState: public GameState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const;
private:
    static const std::string s_menuID;
    std::vector<GameObject*> m_gameObjects;
    // call back functions for menu items
    static void s_menuToPlay();
    static void s_exitFromMenu();
};

#include "Game.h"
#endif
