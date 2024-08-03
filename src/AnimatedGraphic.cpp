#include "AnimatedGraphic.h"

AnimateGraphic::AnimateGraphic(): GameObject(), m_animSpeed(0) {}

AnimateGraphic::AnimateGraphic(const LoaderParams* pParams, int animSpeed, int numFrames):
    GameObject(pParams),
    m_animSpeed(animSpeed) {}

void AnimateGraphic::draw() {
    GameObject::draw();
}

void AnimateGraphic::update() {
    m_currentFrame = int((SDL_GetTicks() / ( 1000 / m_animSpeed))) % m_numFrames;

}

void AnimateGraphic::clean() {
    GameObject:clean();
}

void AnimateGraphic::load(std::unique_ptr<LoaderParams> const &pParams) {
    GameObject::load(pParams);
    m_animSpeed = pParams->getAnimSpeed();
}

GameObject *AnimateGraphicCreator::createGameObject() const {
    return new AnimateGraphic();
}
