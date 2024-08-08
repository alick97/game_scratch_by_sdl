#include "PlayState.h"
#include "BulletHandler.h"

const std::string PlayState::s_playID  = "PLAY";

void PlayState::update(){
    if (!m_loadingComplete || m_exiting) {
        return;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        TheGame::Instance()->getStateMachine()->pushState(new PauseState());
    }

    TheBulletHandler::Instance()->updateBullets();
    if(TheGame::Instance()->getPlayerLives() == 0) {
        TheGame::Instance()->getStateMachine()->changeState(new GameOverState());
    }
        
    if(pLevel != nullptr) {
        pLevel->update();
    }
    
}

void PlayState::render() {
    if(!m_loadingComplete) {
        return;
    }
    
    if(pLevel != nullptr) {
        pLevel -> render();
    }
    
     
    for(int i = 0; i < TheGame::Instance()->getPlayerLives(); i++) {
        TheTextureManager::Instance()->drawFrame("lives", i * 30, 0, 32, 30, 0, 0, TheGame::Instance()->getRender(), 0.0, 255);
    }
    
    TheBulletHandler::Instance()->drawBullets();
}

bool PlayState::onEnter() {
    TheGame::Instance()->setPlayerLives(3);
    LevelParser levelParser;
    pLevel = levelParser.parseLevel(TheGame::Instance()->getLevelFiles()[TheGame::Instance()->getCurrentLevel() - 1].c_str());
    
    TheTextureManager::Instance()->load("assets/bullet1.png", "bullet1", TheGame::Instance()->getRender());
    TheTextureManager::Instance()->load("assets/bullet2.png", "bullet2", TheGame::Instance()->getRender());
    TheTextureManager::Instance()->load("assets/bullet3.png", "bullet3", TheGame::Instance()->getRender());
    TheTextureManager::Instance()->load("assets/lives.png", "lives", TheGame::Instance()->getRender());
    
    if(pLevel != 0)
    {
        m_loadingComplete = true;
    }
    

    std::cout << "entering PlayStat\n";
    return true;
}

bool PlayState::onExit() {
    for (int i = 0; i < m_gameObjects.size(); ++i) {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();

    for (const auto &textureID : m_textureIDList) {
        TheTextureManager::Instance()->clearFromTextureMap(textureID);
    }

    std::cout << "exiting PlayStat\n";
    return true;
}

std::string PlayState::getStateID() const {
    return s_playID;
}
