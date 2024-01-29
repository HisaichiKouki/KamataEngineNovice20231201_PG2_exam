#include <Novice.h>
#include "Game.h"
#include "Title.h"
const char kWindowTitle[] = "LC1A_20_ヒサイチ_コウキ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	int windowX = 1280;
	int windowY = 720;
	Novice::Initialize(kWindowTitle, windowX, windowY);

	Game* game = new Game;
	Title* title = new Title;

	bool change = false;

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

		if (InputManager::GetIsTriggerKey(DIK_RETURN))
		{
			if (change==false)
			{
				delete title;
				title = nullptr;

				game = new Game;
			}
			else if (change==true)
			{
				delete game;
				game = nullptr;

				title = new Title;
			}

			change = !change;
		}

		if (change == false)
		{
			title->Update();
		}
		else if (change == true)
		{
			game->Update();
		}

		
		///------------------///
		/// ↑更新処理ここまで
		///------------------///

		///------------------///
		/// ↓描画処理ここから
		///------------------///

		if (change == false)
		{
			title->Draw();
		}
		else if (change == true)
		{
			game->Draw();
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
