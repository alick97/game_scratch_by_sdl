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
    if (!TheTextureManager::Instance()->load("../assets/resume.png",
    "resumebutton", TheGame::Instance()->getRender())) {
        return false;
    }

    if (!TheTextureManager::Instance()->load("../assets/main.png",
    "mainbutton", TheGame::Instance()->getRender())) {
        return false;
    }

    GameObject *button1 = new MenuButton(new LoaderParams(200, 200,
    200, 80, "mainbutton"), s_pauseToMain);

    GameObject *button2 = new MenuButton(new LoaderParams(200, 300,
    200, 80, "resumebutton"), s_resumePlay);

    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    std::cout << "entering PauseState\n";
    return true;

}
bool PauseState::onExit() {
   for (int i = 0; i < m_gameObjects.size(); i++) {
       m_gameObjects[i]->clean();
   }
   m_gameObjects.clear();
   TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
   TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
   // reset the mouse button states to false
//    TheInputHandler::Instance()->reset();

   std::cout << "exting PauseState\n";
   return true;
}

std::string PauseState::getStateID() const {
    return s_pauseID;
}

void PauseState::s_pauseToMain() {
    TheGame::Instance()->getStateMachine()->pushState(new MenuState());
}

void PauseState::s_resumePlay() {
    TheGame::Instance()->getStateMachine()->popState();
}