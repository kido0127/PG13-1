#include <Novice.h>
#include <iostream>
#include "Enemy.h"
#include "Player.h"
using namespace std;
const char kWindowTitle[] = "LC1A_08_キド_シヅノ_タイトル";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	Player* player = new Player;
	Enemy* enemy[2];
	for (int i = 0; i < 2; i++)
	{
		enemy[i] = new Enemy(100 + i*20,100 + i*20);
	}

	
	

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		player->Update(keys);
		for (int i = 0; i < 2; i++)
		{
			
			enemy[i]->Update(keys);
			if (player->bullet->isShoot && enemy[i]->GetIsAlive()) {
				
				
				if (sqrtf(pow(enemy[i]->GetPositionX() - player->bullet->posX_, 2) + pow(enemy[i]->GetPositionY() - player->bullet->posY_, 2) <= enemy[i]->GetRadius() + player->bullet->radius_)) {
					Enemy::EnemyCount = 0;
				}
				
			}
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();
		for (int i = 0; i < 2; i++)
		{
		
			enemy[i]->Draw();
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
