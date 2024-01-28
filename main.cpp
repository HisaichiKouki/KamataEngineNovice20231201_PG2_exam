#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"
const char kWindowTitle[] = "LC1A_20_ヒサイチ_コウキ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	int windowX = 1280;
	int windowY = 720;
	Novice::Initialize(kWindowTitle, windowX, windowY);

	Player *player=new Player;

	Enemy* enemy = new Enemy;

	//bool True = true;
	//bool False = false;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		/*memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);*/
		InputManager::Update();
		///------------------///
		/// ↓更新処理ここから
		///------------------///

		

		player->Upadte();
		enemy->Update();

		if (enemy->GetIsAlive())
		{
			for (int i = 0; i < kMaxBullet; i++)
			{
				if (player->bullet[i]->isAlive)
				{
					if (EllipseCollision(enemy->GetPos(), enemy->GetRadius()
						, player->bullet[i]->pos, player->bullet[i]->radius))
					{
						//enemy->setIsAlive(false);
						enemy->setIsHit(true);

						player->bullet[i]->isAlive = false;
					}
				}
				
			}
		}
		
		if (EllipseCollision(enemy->GetPos(), enemy->GetRadius()
			, player->GetPos(), player->GetRadius()))
		{
			player->isAlive = false;


		}

		if (player->isAlive==false)
		{
			if (InputManager::GetIsTriggerKey(DIK_R))
			{
				player->Init();
				enemy->Init();

			}
		}
		///------------------///
		/// ↑更新処理ここまで
		///------------------///

		///------------------///
		/// ↓描画処理ここから
		///------------------///

		enemy->Draw();
		player->Draw();


		for (int i = 0; i < kMaxBullet; i++)
		{
			player->bullet[i]->Draw();
		}

		player->Debug();
		if (!player->isAlive)
		{
			Novice::ScreenPrintf(590, 360, "GameOver");
			Novice::ScreenPrintf(600, 380, "> R <");
		}
		///------------------///
		/// ↑描画処理ここまで
		///------------------///

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
