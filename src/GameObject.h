#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include <SDL.h>
#include <iostream>
#include "TextureManager.h"
#include "LoaderParams.h"

class GameObject {
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
    virtual void load(const LoaderParams *pParams) = 0;
    GameObject() {}
    GameObject(const LoaderParams* pParams) {}
protected:
    virtual ~GameObject() {}
    std::string m_textureID;
};

#endif /* defined(__GAMEOBJECT__) */
