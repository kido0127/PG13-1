#pragma once
class Bullet
{
public:
	float posX_, posY_;
	float speed_;
	float radius_;
	bool isShoot;

	Bullet(float X , float Y);
	void Update();
	void Draw();
};