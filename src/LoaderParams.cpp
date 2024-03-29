#include "LoaderParams.h"

int LoaderParams::getX() const {
    return m_x;
}

int LoaderParams::getY() const {
    return m_y;
}

int LoaderParams::getWidth() const {
    return m_width;
}

int LoaderParams::getHeight() const {
    return m_height;
}

int LoaderParams::getNumFrames() const {
    return m_numFrames;
}

int LoaderParams::getCallbackID() const {
    return m_callbackID;
}

int LoaderParams::getAnimSpeed() const {
    return m_animSpeed;
}


std::string LoaderParams::getTextureID() const {
    return m_textureID;
}