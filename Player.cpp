#include "Player.h"
#include "Novice.h"

Player::Player(int posX, int posY, int speed, int radius) 
{
	posX_ = posX;
	posY_ = posY;
	speed_ = speed;
	radius_ = radius;
	bullet = new Bullet(float(posX_),float(posY_));
}
Player::~Player()
{
	delete bullet;
}
void Player::Update(char* keys)
{

	if (keys[DIK_W])
	{
		posY_ -= speed_;
	}
	if (keys[DIK_S]) 
	{
		posY_ += speed_; 
	}
	if (keys[DIK_A]) 
	{ 
		posX_ -= speed_; 
	}
	if (keys[DIK_D])
	{
		posX_ += speed_; 
	}
	if (keys[DIK_SPACE] && !bullet->isShoot) {
		bullet->posX_ = float(posX_);
		bullet->posY_ = float(posY_ - bullet->speed_);
		bullet->isShoot = true;
	}

	bullet->Update();
}
void Player::Draw()
{
	Novice::DrawEllipse(int(posX_), int(posY_), int(radius_), int(radius_), 0.0f, 0xFFFFFFFF, kFillModeSolid);

	bullet->Draw();
}
