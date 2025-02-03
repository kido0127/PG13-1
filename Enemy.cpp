#include"Enemy.h"
#include<Novice.h>
#include <math.h>
int Enemy::EnemyCount=1;
Enemy::Enemy(int posX,int posY)
{
	posX_ = posX;
	posY_ = posY;
	speed_ = 1;
	radius_ = 30;
	isAlive = true;

}

Enemy::~Enemy()
{

}

int Enemy::GetPositionX()
{
	return posX_;
}
int Enemy::GetPositionY()
{
	return posY_;
}
bool Enemy::GetIsAlive()
{
	return isAlive;
}
int Enemy::GetRadius()
{
	return radius_;
}

void Enemy::Update(char*keys)
{
	if (isAlive) {
		posX_ += speed_;
		if (posX_ + radius_ <= 0 || posX_ - radius_ >= 1280) {
			speed_ = -speed_;
		}if (EnemyCount == 0) {
			isAlive = false;
		}
	}
	else {
		if (keys[DIK_R]) {
			EnemyCount = 1;
			isAlive = true;
		}
	}
	
	
}
void Enemy::Draw()
{
	if (isAlive == 1) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
	
}