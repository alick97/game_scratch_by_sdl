#ifndef __MENUBUTTON_H__
#define __MENUBUTTON_H__

#include "SDLGameObject.h"
#include "InputHandler.h"

class MenuButton: public SDLGameObject {
public:
    MenuButton(const LoaderParams *pParams, void (*callback)());

    virtual void draw();
    virtual void update();
    virtual void clean();
private:
    enum button_state
    {
        MOUSE_OUT = 0, // in picture frame pos 0
        MOUSE_OVER = 1, // in picture frame pos 1
        CLICKED = 2 // in picture frame pos 2
    };
    void (*m_callback)();
    bool m_bRelease;
};

#endif