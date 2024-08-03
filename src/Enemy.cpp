#include "Enemy.h"

Enemy::Enemy(): ShooterObject() {}

Enemy::Enemy(const LoaderParams* pParams, int numFrames) : 
    ShooterObject(pParams) {
        m_numFrames = numFrames;
        m_velocity.setY(2);
        m_velocity.setX(0.001);
    }

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


void Enemy::load(const LoaderParams *pParams) {
    ShooterObject::load(pParams);
    m_velocity.setY(2);
}

GameObject* EnemyCreator::createGameObject() const {
    return new Enemy();
}