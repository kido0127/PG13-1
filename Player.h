#pragma once
#include "Bullet.h"
class Player
{
protected:
	int posX_, posY_;
	int speed_;
	int radius_;
	
public:
	Player(int posX_ = 640.0f, int posY_ = 500.0f, int speed_ = 5.0f, int radius_ = 10.0f);
	~Player();
	void Update(char* keys);
	void Draw();
	Bullet* bullet;
};