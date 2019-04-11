#include "GameOverState.h"

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
    if (!TheTextureManager::Instance()->load("../assets/gameover.png", "gameovertext",
    TheGame::Instance()->getRender())) {
        return false;
    }

    if (!TheTextureManager::Instance()->load("../assets/main.png",
    "mainbutton", TheGame::Instance()->getRender())) {
        return false;
    }

    if (!TheTextureManager::Instance()->load("../assets/resume.png",
    "restartbutton", TheGame::Instance()->getRender())) {
        return false;
    }

    GameObject *gameOverText = new AnimateGraphic(new
    LoaderParams(160, 10, 300, 50, "gameovertext"), 2, 2);
    GameObject *button1 = new MenuButton(new LoaderParams(200, 200,
    200, 80, "mainbutton"), s_gameOverToMain);
    GameObject *button2 = new MenuButton(new LoaderParams(200, 300,
    200, 80, "restartbutton"), s_restartPlay);

    m_gameObjects.push_back(gameOverText);
    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    std::cout << "entering PauseState\n";
    return true;
}

bool GameOverState::onExit() {
    for (int i = 0; i < m_gameObjects.size(); ++i) {
        m_gameObjects[i]->clean();
    }
    TheTextureManager::Instance()->clearFromTextureMap("gameovertext");
    TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
    TheTextureManager::Instance()->clearFromTextureMap("restartbutton");

    m_gameObjects.clear();

    return true;
}

std::string GameOverState::getStateID() const {
    return s_gameOverID;
}

void GameOverState::s_gameOverToMain() {
    TheGame::Instance()->getStateMachine()->pushState(new MenuState());
}

void GameOverState::s_restartPlay() {
    TheGame::Instance()->getStateMachine()->pushState(new PlayState());
}
