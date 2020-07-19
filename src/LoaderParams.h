#ifndef __LOADERPARAMS_
#define __LOADERPARAMS_

#include<iostream>

class LoaderParams {
public:
    LoaderParams(
        int x, int y, int width, int height, std::string textureID,
        int numFrames, int callbackID=0, int animSpeed=0) :
    m_x(x),
    m_y(y),
    m_width(width),
    m_height(height),
    m_numFrames(numFrames),
    m_callbackID(callbackID),
    m_animSpeed(animSpeed),
    m_textureID(textureID) {}

    int getX() const;

    int getY() const;

    int getWidth() const;

    int getHeight() const;

    int getNumFrames() const;

    int getCallbackID() const;

    int getAnimSpeed() const;

    std::string getTextureID() const;

private:
    int m_x;
    int m_y;

    int m_width;
    int m_height;
    int m_numFrames;
    int m_callbackID;
    int m_animSpeed;

    std::string m_textureID;
};

#endif /* defined(__LOADERPARAMS__) */
