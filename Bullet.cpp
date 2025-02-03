#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet(float x, float y)
    : posX_(x), posY_(y), speed_(5.0f), radius_(20.0f), isShoot(false) {}

void Bullet::Update() {
    if (isShoot) {
        posY_ -= speed_;
        if (posY_ <0-radius_) {
            isShoot = false;
        }
    }
}

void Bullet::Draw() {
    if (isShoot) {
        Novice::DrawEllipse(int(posX_), int(posY_), int(radius_), int(radius_), 0.0f, 0xFFFFFFFF, kFillModeSolid);
    }
}