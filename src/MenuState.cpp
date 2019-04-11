#include "MenuState.h"

const std::string MenuState::s_menuID  = "MENU";

void MenuState::update(){
   for(int i = 0; i < m_gameObjects.size(); i++) {
       m_gameObjects[i]->update();
   }
}

void MenuState::render() {
    for(int i=0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool MenuState::onEnter() {
    if (!TheTextureManager::Instance()->load("../assets/exit_button.png",
    "exitbutton", TheGame::Instance()->getRender())) {
        return false;
    }
    if (!TheTextureManager::Instance()->load("../assets/play_button.png",
    "playbutton", TheGame::Instance()->getRender())) {
        return false;
    }

    GameObject* play_button = new MenuButton(new LoaderParams(100, 100,
    231, 48, "playbutton"), s_menuToPlay);
    GameObject* exit_button = new MenuButton(new LoaderParams(100, 300,
    231, 48, "exitbutton"), s_exitFromMenu);

    m_gameObjects.push_back(play_button);
    m_gameObjects.push_back(exit_button);

    std::cout << "entering MenuState\n";
    return true;
}

bool MenuState::onExit() {
    for (int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("playbutton");
    TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

    std::cout << "exiting MenuState\n";
    return true;
}

std::string MenuState::getStateID() const {
    return s_menuID;
}

void MenuState::s_menuToPlay() {
    TheGame::Instance()->getStateMachine()->pushState(new PlayState());
    std::cout << "Play button clicked\n";
}

void MenuState::s_exitFromMenu() {
    TheGame::Instance()->quit();
}
