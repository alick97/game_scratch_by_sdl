#ifndef __MENUBUTTON_H__
#define __MENUBUTTON_H__

#include "cassert"
#include "ShooterObject.h"
#include "GameObjectFactory.h"
#include "InputHandler.h"

class MenuButton: public ShooterObject {
public:
    MenuButton();

    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void load(std::unique_ptr<LoaderParams> const &pParams);
    virtual void setCallback(void(*callback)());
    virtual int getCallbackID();
    // get the type of the object.
    virtual std::string type() { return "MenuButton"; };
private:
    enum button_state
    {
        MOUSE_OUT = 0, // in picture frame pos 0
        MOUSE_OVER = 1, // in picture frame pos 1
        CLICKED = 2 // in picture frame pos 2
    };
    void (*m_callback)();
    int m_callbackID;
    bool m_bRelease;
};


class MenuButtonCreator: public BaseCreator {
public:
    GameObject* createGameObject() const override;

};

#endif
