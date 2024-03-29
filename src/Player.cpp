#include "Player.h"

Player::Player(): SDLGameObject() {

}

Player::Player(const LoaderParams* pParams) : 
    SDLGameObject(pParams) {
        m_currentFrame = 0;
    }

void Player::draw() {
    SDLGameObject::draw();
}

void Player::update() {
    m_velocity.setX(0);
    m_velocity.setY(0);

    handleInput(); // add our function

    SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput() {
    if (TheInputHandler::Instance()->joysticksInitialised()) {
        if (TheInputHandler::Instance()->xvalue(0, 1) > 0 ||
        TheInputHandler::Instance()->xvalue(0, 1) < 0) {
            m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0, 1));
        }

        if (TheInputHandler::Instance()->yvalue(0, 1) > 0 ||
        TheInputHandler::Instance()->yvalue(0, 1) < 0) {
            m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0, 1));
        }

        if (TheInputHandler::Instance()->xvalue(0, 2) > 0 ||
        TheInputHandler::Instance()->xvalue(0, 2) < 0) {
            m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0, 2));
        }

        if (TheInputHandler::Instance()->yvalue(0, 2) > 0 ||
        TheInputHandler::Instance()->yvalue(0, 2) < 0) {
            m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0, 2));
        }

        // test for joystick button
        // if (TheInputHandler::Instance()->getButtonState(0, 1)) {
        //     m_velocity.setX(1);
        // }
    }

    // mouse event
    if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
        Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
        m_velocity = (*vec - m_position) / 10;
    }

    // keyboard input
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        m_velocity.setX(-2);
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_velocity.setX(2);
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        m_velocity.setY(-2);
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        m_velocity.setY(2);
    }
}

GameObject* PlayerCreator::createGameObject() const {
    return new Player();
}

void Player::load(const LoaderParams *pParams) {
    SDLGameObject::load(pParams);
}
