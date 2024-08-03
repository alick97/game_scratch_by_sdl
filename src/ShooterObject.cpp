#include "ShooterObject.h"
#include "Game.h"


ShooterObject::ShooterObject(): GameObject() {}


ShooterObject::ShooterObject(const LoaderParams* pParams)
    :GameObject(pParams) {
    m_currentRow = 1;
    m_currentFrame = 0;
}


void ShooterObject::load(const LoaderParams *pParams) {
    m_position = Vector2D(pParams->getX(), pParams->getY());
    m_velocity = Vector2D(0, 0);
    m_acceleration = Vector2D(0, 0);
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTextureID();
    m_currentFrame = 0;
    m_currentRow = 1;
    m_numFrames = pParams->getNumFrames();
}

void ShooterObject::draw() {
    if (m_velocity.getX() >= 0) {
        TheTextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(),
        int(m_position.getY()), m_width, m_height, m_currentRow, m_currentFrame,
        TheGame::Instance()->getRender());
    } else {
        TheTextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(),
        int(m_position.getY()), m_width, m_height, m_currentRow, m_currentFrame,
        TheGame::Instance()->getRender(), SDL_FLIP_HORIZONTAL);
    }
}

void ShooterObject::update() {
    m_velocity += m_acceleration;
    m_position += m_velocity;
}

void ShooterObject::clean() {

}

void ShooterObject::doDyingAnimation() {
    // keep scrolling with the map.
    scroll(TheGame::Instance()->getScrollSpeed());
    
    // 3 fps
    m_currentFrame = int(((SDL_GetTicks() / (1000 / 3)) % m_numFrames));
    
    if (m_dyingCounter == m_dyingTime) {
        m_bDead = true;
    }
    m_dyingCounter++; // simple counter, fine with fixed frame rate
}