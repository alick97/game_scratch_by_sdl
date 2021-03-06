#include "SDLGameObject.h"
#include "Game.h"


SDLGameObject::SDLGameObject(): GameObject() {}


SDLGameObject::SDLGameObject(const LoaderParams* pParams)
    :GameObject(pParams),
    m_position(pParams->getX(), pParams->getY()),
    m_velocity(0, 0),
    m_acceleration(0, 0) {
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTextureID();

    m_currentRow = 1;
    m_currentFrame = 0;
}


void SDLGameObject::load(const LoaderParams *pParams) {
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

void SDLGameObject::draw() {
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

void SDLGameObject::update() {
    m_velocity += m_acceleration;
    m_position += m_velocity;
}

void SDLGameObject::clean() {

}

Vector2D& SDLGameObject::getPosition() {
    return m_position;
}

int SDLGameObject::getWidth() {
    return m_width;
}

int SDLGameObject::getHeight() {
    return m_height;
}