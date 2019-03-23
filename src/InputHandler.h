#ifndef __INPUTHANDLER__
#define __INPUTHANDLER__

#include "Game.h"
#include "Vector2D.h"
#include <SDL.h>
#include <vector>

enum mouse_buttons {
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler {
public:
    static InputHandler* Instance();
    void update();
    void clean();
    void initialiseJoysticks();
    bool joysticksInitialised();
    int xvalue(int joy, int stick);
    int yvalue(int joy, int stick);
    bool getButtonState(int joy, int buttonNumber);
    bool getMouseButtonState(int buttonNumber);
    Vector2D* getMousePosition();
    bool isKeyDown(SDL_Scancode key);
private:
    InputHandler();
    ~InputHandler();

    static InputHandler* s_pInstance;
    static bool m_bJoysticksInitialised;
    std::vector<SDL_Joystick*> m_joysticks;
    std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
    std::vector<std::vector<bool>> m_buttonStates;
    std::vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePosition;
    const Uint8* m_keystates;
    // handle keyboard events
    void onKeyDown();
    void onKeyUp();

    // handle mouse events
    void onMouseMove(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);

    // handle joysticks events
    void onJoystickAxisMove(SDL_Event& event);
    void onJoystickButtonDown(SDL_Event& event);
    void onJoystickButtonUp(SDL_Event& event);

    static const int m_joystickDeadZone = 10000;
};

typedef InputHandler TheInputHandler;
#endif /* defined(__INPUTHANDLER__) */