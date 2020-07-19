#include "GameOverState.h"
#include "PlayState.h"
#include "MainMenuState.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update() {
    for (int i = 0; i < m_gameObjects.size(); ++i) {
        m_gameObjects[i]->update();
    }
}

void GameOverState::render() {
    for (int i = 0; i < m_gameObjects.size(); ++i) {
        m_gameObjects[i]->draw();
    }
}

bool GameOverState::onEnter() {
    // Parse the state.
    StateParser stateParser;
    stateParser.parseState("assets/test.xml", s_gameOverID, &m_gameObjects, &m_textureIDList);
    m_callbacks.push_back(nullptr); // Pushback 0 callbackID start from 1.
    m_callbacks.push_back(s_gameOverToMain);
    m_callbacks.push_back(s_restartPlay);

    // Set the callbacks for menu items.
    setCallbacks(m_callbacks);

    std::cout << "entering GameOverState\n";
    return true;
}

bool GameOverState::onExit() {
    for (int i = 0; i < m_gameObjects.size(); ++i) {
        m_gameObjects[i]->clean();
    }

    for (const auto &textureID : m_textureIDList) {
        TheTextureManager::Instance()->clearFromTextureMap(textureID);
    }

    m_gameObjects.clear();

    return true;
}

std::string GameOverState::getStateID() const {
    return s_gameOverID;
}

void GameOverState::s_gameOverToMain() {
    TheGame::Instance()->getStateMachine()->pushState(new MainMenuState());
}

void GameOverState::s_restartPlay() {
    TheGame::Instance()->getStateMachine()->pushState(new PlayState());
}

void GameOverState::setCallbacks(const std::vector<Callback> &callbacks) {
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