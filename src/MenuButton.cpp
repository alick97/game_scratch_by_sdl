#include "MenuButton.h"

MenuButton::MenuButton():ShooterObject(),m_callback(0),m_bRelease(true) {}

void MenuButton::draw() {
    ShooterObject::draw();
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
            assert(m_callback != nullptr);
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
    ShooterObject::clean();
} 

void MenuButton::load(std::unique_ptr<LoaderParams> const &pParams) {
    ShooterObject::load(pParams);
    m_callbackID = pParams->getCallbackID();
    m_currentFrame = MOUSE_OUT;
}

void MenuButton::setCallback(void(*callback)()) {
    m_callback = callback;
}

int MenuButton::getCallbackID() {
    return m_callbackID;
}

GameObject *MenuButtonCreator::createGameObject() const {
    return new MenuButton();
}
