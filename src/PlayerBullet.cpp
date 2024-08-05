#include "PlayerBullet.h"


PlayerBullet::PlayerBullet():ShooterObject() {}
PlayerBullet::~PlayerBullet() {}
void PlayerBullet::load(std::unique_ptr<LoaderParams> const& pParams, Vector2D heading) {
    ShooterObject::load(std::move(pParams));
    m_heading = heading;
}
void PlayerBullet::draw() {
    ShooterObject::draw();

}
void PlayerBullet::collision() {
    m_bDead = true;
}
void PlayerBullet::update() {
    m_velocity.setX(m_heading.getX());
}
void PlayerBullet::clean() {
    ShooterObject::clean();
}
