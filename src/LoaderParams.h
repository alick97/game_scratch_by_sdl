#ifndef __LOADERPARAMS_
#define __LOADERPARAMS_

#include<iostream>

class LoaderParams {
public:
    LoaderParams(int x, int y, int width, int height, std::string
    textureID) : m_x(x), m_y(y), m_width(width), m_height(height),
    m_textureID(textureID) {}

    int getX() const;

    int getY() const;

    int getWidth() const;

    int getHeight() const;

    std::string getTextureID() const;

private:
    int m_x;
    int m_y;

    int m_width;
    int m_height;

    std::string m_textureID;
};

#endif /* defined(__LOADERPARAMS__) */