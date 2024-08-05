#include "Enemy.h"

Enemy::Enemy(): ShooterObject() {}

void Enemy::draw() {
    ShooterObject::draw();
}

void Enemy::update() {
    m_currentFrame = int((SDL_GetTicks() / 100) % m_numFrames);

    if (m_position.getY() < 0) {
        m_velocity.setY(2);
    } else if (m_position.getY() > 300) {
        m_velocity.setY(-2);
    }

    ShooterObject::update();
}

void Enemy::clean() {}


void Enemy::load(std::unique_ptr<LoaderParams>  const &pParams) {
    ShooterObject::load(pParams);
    m_velocity.setY(2);
}
