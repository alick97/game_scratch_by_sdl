#ifndef __MENUSTATE_H__
#define __MENUSTATE_H__

#include <vector>
#include <iostream>
#include "GameState.h"
#include "TextureManager.h"
#include "MenuButton.h"


typedef void(*Callback)();

class MenuState: public GameState {
protected:
    virtual void setCallbacks(const std::vector<Callback> &callbacks) = 0;

    std::vector<Callback> m_callbacks;
};

// #include "Game.h"
#endif
