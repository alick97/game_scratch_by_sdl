#include "AnimatedGraphic.h"

AnimateGraphic::AnimateGraphic(): ShooterObject(), m_animSpeed(0) {}

void AnimateGraphic::draw() {
    ShooterObject::draw();
}

void AnimateGraphic::update() {
    m_currentFrame = int((SDL_GetTicks() / ( 1000 / m_animSpeed))) % m_numFrames;

}

void AnimateGraphic::clean() {
    ShooterObject:clean();
}

void AnimateGraphic::load(std::unique_ptr<LoaderParams> const &pParams) {
    ShooterObject::load(pParams);
    m_animSpeed = pParams->getAnimSpeed();
}

GameObject *AnimateGraphicCreator::createGameObject() const {
    return new AnimateGraphic();
}
