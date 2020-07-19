#ifndef __MAINMENUSTATE_H__
#define __MAINMENUSTATE_H__

#include "GameObject.h"
#include "MenuState.h"
#include "PlayState.h"
#include "StateParser.h"



class MainMenuState: public MenuState {
public:
    void update() override;
    void render() override;

    bool onEnter() override;
    bool onExit() override;

    std::string getStateID() const override { return s_menuID; }
private:
    void setCallbacks(const std::vector<Callback>& callbacks) override;
    // call back functions for menu items
    static void s_menuToPlay();
    static void s_exitFromMenu();

    static const std::string s_menuID;
    std::vector<GameObject*> m_gameObjects;
};


#endif /* defined(__MAINMENUSTATE_H__) */
