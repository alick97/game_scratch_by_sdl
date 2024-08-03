#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include <SDL.h>
#include <iostream>
#include "TextureManager.h"
#include "LoaderParams.h"
#include <memory>

class GameObject {
public:
    // draw the object.
    virtual void draw() = 0;
    // do update stuff.
    virtual void update() = 0;
    // remove anything that needs to be deleted.
    virtual void clean() = 0;
    // object has collided, handle accordingly.
    virtual void collision() = 0;
    // get the type of the object.
    virtual std::string type() = 0;
    // getters for common variables.
    Vector2D& getPosition() { return m_position; }
    int getWidth() { return m_width; }
    int getHeight() { return m_height; }
    // scroll along with tile map.
    void scroll (float scrollSpeed) { m_position.setX(m_position.getX() - scrollSpeed); }
    // is the object currently being updated?
    bool updating() { return m_bUpdating; }
    // is the obejct dead?
    bool dead() { return m_bDead; }
    // is the object doing a death animation.
    bool dying() { return m_bDying; }
    // set whether to update the object or not.
    void setUpdating(bool updating) { m_bUpdating = updating; }
    
    // load from file.
    virtual void load(std::unique_ptr<LoaderParams> const &pParams) = 0;
    GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {}
protected:
    // movement variables.
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;
    // size variables;
    int m_width;
    int m_height;
    // animation variables.
    int m_currentRow;
    int m_currentFrame;
    int m_numFrames;
    std::string m_textureID;
    // common boolean variables.
    bool m_bUpdating;
    bool m_bDead;
    bool m_bDying;
    // rotation.
    double m_angle;
    // blending.
    int m_alpha;

    // constructor with default initialisation list.
    GameObject(): m_position(0,0),
    m_velocity(0, 0),
    m_acceleration(0, 0),
    m_width(0),
    m_height(0),
    m_currentRow(0),
    m_currentFrame(0),
    m_bUpdating(false),
    m_bDead(false),
    m_bDying(false),
    m_angle(0),
    m_alpha(255)
    {}
};

#endif /* defined(__GAMEOBJECT__) */
