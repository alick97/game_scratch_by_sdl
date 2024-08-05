#ifndef __Game__
#define __Game__
#include "TextureManager.h"
#include "GameObject.h"
#include "InputHandler.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "GameStateMachine.h"


class Game {
public:
    static Game* Instance();

    // simple set the running variable to true
    bool init(const char* title, int xpos, int ypos, int width,
    int height, bool fullscreen);
    void draw();
    void render();
    void update();
    void handleEvents();
    void clean();
    SDL_Renderer* getRender() const;

    // a function to access the private running variable
    bool running() { return m_bRunning; }
    void quit();
    GameStateMachine* getStateMachine();
    int getGameWidth() const;
    int getGameHeight() const;
    float getScrollSpeed() const;
    int getPlayerLives() const;
    void setPlayerLives(int lives);
    
    bool getLevelComplete();
    void setCurrentLevel(int level);
    int getCurrentLevel();
    std::vector<std::string> getLevelFiles() { return m_levelFiles; }
    
    bool changingState() { return m_bChangingState; }
	void changingState(bool cs) { m_bChangingState = cs; }

private:
    Game();
    ~Game();
    Game(const Game&);
    Game operator=(const Game&);

    static Game* s_pInstance;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;

    SDL_Texture* m_pTexture;
    int m_currentFrame;

    int m_gameWidth;
    int m_gameHeight;
    float m_scrollSpeed;
    int m_playerLives;
    int m_currentLevel;
    bool m_bLevelComplete;
    bool m_bChangingState;

    GameStateMachine *m_pGameStateMachine;
    std::vector<GameObject*> m_gameObject;
    std::vector<std::string> m_levelFiles;
    // game object
    GameObject* m_player;
    GameObject* m_enemy1;
    GameObject* m_enemy2;
    GameObject* m_enemy3;
};

typedef Game TheGame;

#endif /* defined(__Game__) */