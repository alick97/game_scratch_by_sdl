#include "AnimatedGraphic.h"

AnimateGraphic::AnimateGraphic(const LoaderParams* pParams, int animSpeed, int numFrames):
    SDLGameObject(pParams),
    m_numFrames(numFrames),
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
