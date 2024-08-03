#include <ScrollingBackground.h>
#include "Game.h"

ScrollingBackground::ScrollingBackground(): GameObject() {
    m_count = 0;
    m_maxCount = 10;
}

void ScrollingBackground::draw() {
    SDL_RenderCopyEx(
        TheGame::Instance()->getRender(),
        TextureManager::Instance()->getTextureMap()[m_textureID],
        &m_srcRect1,
        &m_destRect1,
        0,
        0,
        SDL_FLIP_NONE
    );
    SDL_RenderCopyEx(
        Game::Instance()->getRender(),
        TextureManager::Instance()->getTextureMap()[m_textureID],
        &m_srcRect2,
        &m_destRect2,
        0,
        0,
        SDL_FLIP_NONE
    );
}

void ScrollingBackground::update() {
    if (m_count != m_maxCount) {
        m_count++;
        return;
    }
    // make first rectangle smaller.
    m_srcRect1.x += m_scrollSpeed;
    m_srcRect1.w -= m_scrollSpeed;
    m_destRect1.w -= m_scrollSpeed;

    // make second rectangle bigger.
    m_srcRect2.w += m_scrollSpeed;
    m_destRect2.w += m_scrollSpeed;
    m_destRect2.x -= m_scrollSpeed;
    
    // reset and start again.
    if (m_destRect2.w >= m_width) {
        initRects();
    }
    m_count = 0;
}

void ScrollingBackground::load(std::unique_ptr<LoaderParams> const &pParams) {
    GameObject::load(std::move(pParams));
    
    m_scrollSpeed = 1;

    initRects();
}

void ScrollingBackground::initRects() {
    m_srcRect1.x = m_srcRect1.y = 0;
    m_destRect1.x = m_position.getX();
    m_destRect1.y = m_position.getY();

    m_srcRect1.w = m_destRect1.w = m_srcRect2Width = m_destRect1Width = m_width;
    m_srcRect1.h = m_destRect1.h = m_height;
    
    m_srcRect2.x = m_srcRect2.y = 0;
    m_destRect2.x = m_position.getX() + m_width;
    m_destRect2.y = m_position.getY();
    
    m_srcRect2.w = m_destRect2.w = m_srcRect2Width = m_destRect2Width = 0;
    m_srcRect2.h = m_destRect2.h = m_height;
}
