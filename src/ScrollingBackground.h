#ifndef __SCROLLING_BACKGROUND_H__
#define __SCROLLING_BACKGROUND_H__
#include <memory>
#include "LoaderParams.h"
#include "ShooterObject.h" 
#include "GameObjectFactory.h"

class ScrollingBackground: public ShooterObject {
public:
    ScrollingBackground();
    void draw();
    void update();
    void load(std::unique_ptr<LoaderParams> const &pParams);
private:
    void initRects();

    int m_scrollSpeed;
    int m_count;
    int m_maxCount;

    SDL_Rect m_srcRect1;
    SDL_Rect m_srcRect2;

    SDL_Rect m_destRect1;
    SDL_Rect m_destRect2;

    int m_destRect1Width;
    int m_destRect2Width;

    int m_srcRect1Width;
    int m_srcRect2Width;
};

class ScrollingBackgroundCreator : public BaseCreator {
public:
    virtual GameObject* createGameObject() const {
        return new ScrollingBackground();
    }
};

#endif
