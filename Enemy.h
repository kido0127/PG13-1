#pragma once
class Enemy
{
protected:
	int posX_, posY_;
	int speed_;
	int radius_;
	bool isAlive;
public:
	static int  EnemyCount;
	Enemy(int posX,int posY);
	~Enemy();
	int GetPositionX();
	int GetPositionY();
	bool GetIsAlive();
	int GetRadius();
	void Update(char* keys);
	void Draw();
};