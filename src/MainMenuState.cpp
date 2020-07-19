#include "MainMenuState.h"

const std::string MainMenuState::s_menuID  = "MENU";

void MainMenuState::update(){
   for(int i = 0; i < m_gameObjects.size(); i++) {
       m_gameObjects[i]->update();
   }
}

void MainMenuState::render() {
    for(int i=0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

bool MainMenuState::onEnter() {
    // Parse the state.
    StateParser stateParser;
    stateParser.parseState("assets/test.xml", s_menuID, &m_gameObjects, &m_textureIDList);
    m_callbacks.push_back(0);  // Pushback 0 callbackID start from 1.
    m_callbacks.push_back(s_menuToPlay);
    m_callbacks.push_back(s_exitFromMenu);

    // Set the callbacks for menu items.
    setCallbacks(m_callbacks);

    std::cout << "entering MenuState\n";
    return true;
}

bool MainMenuState::onExit() {
    for (int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("playbutton");
    TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

    std::cout << "exiting MainMenuState\n";
    return true;
}


void MainMenuState::s_menuToPlay() {
    TheGame::Instance()->getStateMachine()->pushState(new PlayState());
    std::cout << "Play button clicked\n";
}

void MainMenuState::s_exitFromMenu() {
    TheGame::Instance()->quit();
}

void MainMenuState::setCallbacks(const std::vector<Callback> &callbacks) {
    // Go through the game objects.
    for (int i = 0; i < m_gameObjects.size(); i++) {
        // If they are of type MenuButton then assign a callback
        // based on the id passed in from the file.
        if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {
            MenuButton *pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
            pButton->setCallback(callbacks[pButton->getCallbackID()]);
        }
    }
}
