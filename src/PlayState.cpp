#include "PlayState.h"

const std::string PlayState::s_playID  = "PLAY";

void PlayState::update(){
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        TheGame::Instance()->getStateMachine()->pushState(new PauseState());
    }

    for (int i = 0; i < m_gameObjects.size(); ++i) {
        m_gameObjects[i]->update();
    }

    for (int i = 1; i < m_gameObjects.size(); ++i) {
        if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
            dynamic_cast<SDLGameObject*>(m_gameObjects[i]))) {
                std::cout <<"SDLGameObject num 0 and num "<< i << " collide\n"; 
                TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
                break;
        }
    }
    
}

void PlayState::render() {
    for (int i = 0; i < m_gameObjects.size(); ++i) {
        m_gameObjects[i]->draw();
    }
}

bool PlayState::onEnter() {
    if (!TheTextureManager::Instance()->load("../assets/helicopter.png",
    "helicopter", TheGame::Instance()->getRender())) {
        return false;
    }

    if (!TheTextureManager::Instance()->load("../assets/helicopter2.png",
    "helicopter2", TheGame::Instance()->getRender())) {
        return false;
    }

    GameObject *player = new Player(new LoaderParams(100, 100, 150, 64,
    "helicopter"));
    GameObject *enemy = new Enemy(new LoaderParams(350, 100, 150, 64,
    "helicopter2"));
    m_gameObjects.push_back(player);
    m_gameObjects.push_back(enemy);

    std::cout << "entering PlayStat\n";
    return true;
}

bool PlayState::onExit() {
    for (int i = 0; i < m_gameObjects.size(); ++i) {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("helicopter");

    std::cout << "exiting PlayStat\n";
    return true;
}

std::string PlayState::getStateID() const {
    return s_playID;
}

bool PlayState::checkCollision(SDLGameObject *p1, SDLGameObject *p2) {
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = p1->getPosition().getX();
    rightA = p1->getPosition().getX() + p1->getWidth();
    topA = p1->getPosition().getY();
    bottomA = p1->getPosition().getY() + p1->getHeight();

    // calculate the sides of rect B
    leftB = p2->getPosition().getX();
    rightB = p2->getPosition().getX() + p2->getWidth();
    topB = p2->getPosition().getY();
    bottomB = p2->getPosition().getY() + p2->getHeight();

    // if any of the sides from A are outside of B
    if ( bottomA <= topB ) {return false;}
    if ( topA >= bottomB) {return false;}
    if ( rightA <= leftB) {return false;}
    if ( leftA >= rightB ) {return false;}
    
    return true;
}