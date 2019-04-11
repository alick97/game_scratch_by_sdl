#include "MenuButton.h"

MenuButton::MenuButton(const LoaderParams *pParams, void (*callback)()):
    SDLGameObject(pParams),
    m_callback(callback),
    m_bRelease(false) {
    m_currentFrame = MOUSE_OUT;
}

void MenuButton::draw() {
    SDLGameObject::draw();
}

void MenuButton::update() {
    Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

    if (pMousePos->getX() < (m_position.getX() + m_width)
    && pMousePos->getX() > m_position.getX()
    && pMousePos->getY() < m_position.getY() + m_height
    && pMousePos->getY() > m_position.getY() ) {
        if (TheInputHandler::Instance()->getMouseButtonState(LEFT)
        && m_bRelease) {
            m_currentFrame = CLICKED;
            m_bRelease = false;
            m_callback(); // call our callback function
        } else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
            m_bRelease = true;
            m_currentFrame = MOUSE_OVER;
        }
    } else {
        m_currentFrame = MOUSE_OUT;
    }
}

void MenuButton::clean() {
    SDLGameObject::clean();
}