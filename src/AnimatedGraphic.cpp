#include "AnimatedGraphic.h"

AnimateGraphic::AnimateGraphic(): SDLGameObject(), m_animSpeed(0) {}

AnimateGraphic::AnimateGraphic(const LoaderParams* pParams, int animSpeed, int numFrames):
    SDLGameObject(pParams),
    m_animSpeed(animSpeed) {}

void AnimateGraphic::draw() {
    SDLGameObject::draw();
}

void AnimateGraphic::update() {
    m_currentFrame = int((SDL_GetTicks() / ( 1000 / m_animSpeed))) % m_numFrames;

}

void AnimateGraphic::clean() {
    SDLGameObject:clean();
}

void AnimateGraphic::load(const LoaderParams *pParams) {
    SDLGameObject::load(pParams);
    m_animSpeed = pParams->getAnimSpeed();
}

GameObject *AnimateGraphicCreator::createGameObject() const {
    return new AnimateGraphic();
}
