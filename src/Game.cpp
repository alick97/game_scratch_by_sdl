#include "Game.h"
#include "SoundManager.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "ScrollingBackground.h"
#include "Turret.h"
#include "Glider.h"

Game::~Game() {
    m_pRenderer = nullptr;
    m_pWindow = nullptr;

}


Game::Game():
m_pWindow(0),
m_pRenderer(0),
m_bRunning(false),
m_pGameStateMachine(0),
m_playerLives(3),
m_scrollSpeed(0.8),
m_bLevelComplete(false),
m_bChangingState(false)
{
    // add some level files to an array
    m_levelFiles.push_back("assets/map1.tmx");
    m_levelFiles.push_back("assets/map2.tmx");
    
    // start at this level
    m_currentLevel = 1;
}


bool Game::init(const char* title, int xpos, int ypos,
int width, int height, bool fullscreen) {
    int flags = 0;
    
    m_gameWidth = width;
    m_gameHeight = height;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    // attempt to initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL init success\n";
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos,
        width, height, flags);
        if (m_pWindow != 0) { // window init success
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1 , 0);

            if (m_pRenderer != 0) { // renderer init success
                std::cout<< "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255); 
            }
            else {
                std::cout << "renderer init fail\n";
                return false; // render init fail   
            }
        }
        else {
            std::cout << "window init fail\n";
            return false; // window init fail
        }
    }
    else {
        std::cout << "SDL init fail\n";
        return false; // SDL init fail
    }
    
    // add some sound effects.
    TheSoundManager::Instance()->load("assets/DST_ElectroRock.ogg", "music1", SOUND_MUSIC);
    TheSoundManager::Instance()->load("assets/boom.wav", "explode", SOUND_SFX);
    TheSoundManager::Instance()->load("assets/phaser.wav", "shoot", SOUND_SFX);

    TheSoundManager::Instance()->playMusic("music1", -1);

    // Register GameObject creater to GameObjectFactory.
    TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
    TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
    TheGameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimateGraphicCreator());
    TheGameObjectFactory::Instance()->registerType("ScrollingBackground", new ScrollingBackgroundCreator());
    TheGameObjectFactory::Instance()->registerType("Turret", new TurretCreator());
    TheGameObjectFactory::Instance()->registerType("Glider", new GliderCreator());
    // TODO: add other ememy.
    // TheGameObjectFactory::Instance()->registerType("ShotGlider", new ShotGliderCreator());
    // TheGameObjectFactory::Instance()->registerType("RoofTurret", new RoofTurretCreator());
    // TheGameObjectFactory::Instance()->registerType("Eskeletor", new EskeletorCreator());
    // TheGameObjectFactory::Instance()->registerType("Level1Boss", new Level1BossCreator());
    TheGameObjectFactory::Instance()->registerType("ShotGlider", new GliderCreator());
    TheGameObjectFactory::Instance()->registerType("RoofTurret", new GliderCreator());
    TheGameObjectFactory::Instance()->registerType("Eskeletor", new GliderCreator());
    TheGameObjectFactory::Instance()->registerType("Level1Boss", new GliderCreator());

    // init handle events system
    TheInputHandler::Instance()->initialiseJoysticks();
    // init stat machine
    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MainMenuState());
    
    std::cout << "init success\n";
    m_bRunning = true; // everything inited successfully, start thi min loop

    return true;
}

void Game::draw() {
    for(std::vector<GameObject>::size_type i=0; i !=
    m_gameObject.size(); i++) {
        m_gameObject[i]->draw();
    }
}

void Game::render() {
    SDL_RenderClear(m_pRenderer); // clear the render to draw color

    m_pGameStateMachine->render();

    SDL_RenderPresent(m_pRenderer); // draw to the screen

}

void Game::clean() {
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    TheInputHandler::Instance()->clean();
    SDL_Quit();
}

void Game::handleEvents() {
    TheInputHandler::Instance()->update();

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
        m_pGameStateMachine->changeState(new PlayState());
    }
}

void Game::update() {
    m_pGameStateMachine->update();
}

Game* Game::Instance() {
    if (s_pInstance == NULL) {
        s_pInstance = new Game();
        return s_pInstance;
    }

    return s_pInstance;
}

SDL_Renderer* Game::getRender() const {
    return m_pRenderer;
}

void Game::quit() {
    m_bRunning = false;
}

GameStateMachine* Game::getStateMachine() {
    return m_pGameStateMachine;
}

int Game::getGameWidth() const {
    return m_gameWidth;
}
int Game::getGameHeight() const {
    return m_gameHeight;
}

float Game::getScrollSpeed() const {
    return m_scrollSpeed;
}

int Game::getPlayerLives() const {
    return m_playerLives;
}

void Game::setPlayerLives(int lives) {
    m_playerLives = lives;
}

bool Game::getLevelComplete() {
    return m_bLevelComplete;
}

void Game::setCurrentLevel(int level) {
    m_currentLevel = level;
    // m_pGameStateMachine->changeState(new BetweenLevelState());
    m_bLevelComplete = false;
}
int Game::getCurrentLevel() {
    return m_currentLevel;
}


Game* Game::s_pInstance = nullptr;
