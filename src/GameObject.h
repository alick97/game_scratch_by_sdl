#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include "TextureManager.h"
#include "LoaderParams.h"
#include <SDL.h>
#include <iostream>

class GameObject {
public:
    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean()=0;
protected:
    GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {}
    std::string m_textureID;
};

#endif /* defined(__GAMEOBJECT__) */
