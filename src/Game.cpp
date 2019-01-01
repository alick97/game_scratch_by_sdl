#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos,
int width, int height, bool fullscreen) {
    int flags = 0;

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
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 100, 255); 
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
    
    // load texture
    TheTextureManager::Instance()->load("../assets/animate.bmp",
    "animate", m_pRenderer);

    // load game object
    // m_go.load(100, 100, 128, 82, "animate");
    // m_player.load(300, 300, 128, 82, "animate");
    m_player = new Player(new LoaderParams(100, 100, 128, 82, "animate"));
    m_enemy1 = new Enemy(new LoaderParams(300, 300, 128, 82, "animate"));
    // m_enemy2 = new Enemy();
    // m_enemy3 = new Enemy();

    m_gameObject.push_back(m_player);
    m_gameObject.push_back(m_enemy1);
    // m_gameObject.push_back(m_enemy2);
    // m_gameObject.push_back(m_enemy3);

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

    // TheTextureManager::Instance()->draw("animate", 100, 100, 128, 82, m_pRenderer);

    // TheTextureManager::Instance()->drawFrame("animate", 0, 0, 128, 82,
    // 1, m_currentFrame, m_pRenderer);

    // m_go.draw(m_pRenderer);
    // m_player.draw(m_pRenderer);

    for(std::vector<GameObject*>::size_type i=0; i < 
    m_gameObject.size(); i++) {
        m_gameObject[i]->draw();
    }

    SDL_RenderPresent(m_pRenderer); // draw to the screen

}

void Game::clean() {
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT: {
                m_bRunning = false;
                break;
            }
                
            default:
                break;
        }
    }
}

void Game::update() {
    // m_currentFrame = int((SDL_GetTicks() / 100) % 6);
    // m_go.update();
    // m_player.update();
    for(std::vector<GameObject*>::size_type i=0; i <
    m_gameObject.size(); i++) {
        m_gameObject[i]->update();
    }
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

Game* Game::s_pInstance = NULL;