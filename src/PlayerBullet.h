#ifndef __PLAYER_BULLET_H__
#define __PLAYER_BULLET_H__
#include "ShooterObject.h"

class PlayerBullet: ShooterObject {
public:
    PlayerBullet();
    virtual ~PlayerBullet();
    virtual std::string type() { return "PlayerBullet"; }
    virtual void load(std::unique_ptr<LoaderParams> const& pParams, Vector2D heading);
    virtual void draw();
    virtual void collision();
    virtual void update();
    virtual void clean();
private:
    Vector2D m_heading;
};


class EnemyBullet: public PlayerBullet {
public:
    EnemyBullet(): PlayerBullet() {}
    virtual ~EnemyBullet() {}
    virtual std::string type() { return "EnemyBullet"; }
};

#endif
