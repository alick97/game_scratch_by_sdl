#include "PlayerBullet.h"

PlayerBullet::PlayerBullet() : ShooterObject() {}
PlayerBullet::~PlayerBullet() {}
void PlayerBullet::load(std::unique_ptr<LoaderParams> const &pParams,
                        Vector2D heading) {
  ShooterObject::load(std::move(pParams));
  m_heading = heading;
}
void PlayerBullet::draw() { ShooterObject::draw(); }
void PlayerBullet::collision() { m_bDead = true; }
void PlayerBullet::update() {
  if (!m_bDying) {
    m_velocity.setX(m_heading.getX());
    m_velocity.setY(m_heading.getY());

    ShooterObject::update();
  } else {
    m_velocity.setX(0);
    m_velocity.setY(0);
    doDyingAnimation();
  }
}
void PlayerBullet::clean() { ShooterObject::clean(); }
