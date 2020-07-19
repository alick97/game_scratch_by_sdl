#include "PauseState.h"

const std::string PauseState::s_pauseID  = "PAUSE";

void PauseState::update() {
    for (int i = 0; i < m_gameObjects.size(); ++i) {
        m_gameObjects[i]->update();
    }
}

void PauseState::render() {
    for (int i = 0; i < m_gameObjects.size(); ++i) {
        m_gameObjects[i]->draw();
    }
}

bool PauseState::onEnter() {
    // if (!TheTextureManager::Instance()->load("../assets/resume.png",
    // "resumebutton", TheGame::Instance()->getRender())) {
    //     return false;
    // }

    // if (!TheTextureManager::Instance()->load("../assets/main.png",
    // "mainbutton", TheGame::Instance()->getRender())) {
    //     return false;
    // }

    // GameObject *button1 = new MenuButton(new LoaderParams(200, 200,
    // 200, 80, "mainbutton"), s_pauseToMain);

    // GameObject *button2 = new MenuButton(new LoaderParams(200, 300,
    // 200, 80, "resumebutton"), s_resumePlay);

    // m_gameObjects.push_back(button1);
    // m_gameObjects.push_back(button2);

    // Parse the state.
    StateParser stateParser;
    stateParser.parseState("assets/test.xml", s_pauseID, &m_gameObjects, &m_textureIDList);
    m_callbacks.push_back(nullptr); // Pushback 0 callbackID start from 1.
    m_callbacks.push_back(s_pauseToMain);
    m_callbacks.push_back(s_resumePlay);

    std::cout << "entering PauseState\n";
    return true;

}
bool PauseState::onExit() {
    for (int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();

    for (const auto &textureID : m_textureIDList) {
        TheTextureManager::Instance()->clearFromTextureMap(textureID);
    }

    std::cout << "exting PauseState\n";
    return true;
}

std::string PauseState::getStateID() const {
    return s_pauseID;
}

void PauseState::s_pauseToMain() {
    TheGame::Instance()->getStateMachine()->pushState(new MainMenuState());
}

void PauseState::s_resumePlay() {
    TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::setCallbacks(const std::vector<Callback> &callbacks) {
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